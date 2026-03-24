import re
import csv
from collections import defaultdict

INPUT_FILE = "cyrix.output"
OUTPUT_FILE = "parsing_table.csv"

# -------------------------------
# DATA STRUCTURES
# -------------------------------
terminals = []
non_terminals = set()

action_table = defaultdict(lambda: defaultdict(list))
goto_table = defaultdict(dict)
default_actions = {}

all_states = set()


# -------------------------------
# NORMALIZATION
# -------------------------------
def normalize(sym):
    if sym == "$end":
        return "$"
    return sym.strip()


# -------------------------------
# SYMBOL EXTRACTION
# -------------------------------
def extract_symbol(line):
    """
    Safely extract the leading symbol from a bison output line.
    Handles quoted single-char terminals like '(', '[', '.' correctly.
    The old regex [^\s(]+ would stop at '(' and break these symbols.
    """
    m = re.match(r"('[^']+'|\S+)", line)
    return normalize(m.group(1)) if m else None


# -------------------------------
# STEP 1: EXTRACT TERMINALS
# -------------------------------
def extract_terminals(lines):
    start = False

    for raw_line in lines:
        line = raw_line.strip().replace("\ufeff", "")

        if "Terminals," in line:
            start = True
            continue

        if start:
            if "Nonterminals," in line or "Grammar rules" in line or line.startswith("Grammar"):
                break

            if line == "":
                continue

            # FIX: use extract_symbol so '(' and '[' terminals are captured correctly
            sym = extract_symbol(line)
            if sym and sym not in terminals:
                terminals.append(sym)

    print(f"Extracted {len(terminals)} terminals")
    print("Sample:", terminals[:10])


# -------------------------------
# STEP 2: PARSE STATES
# -------------------------------
def parse_states(lines):
    current_state = None

    for raw_line in lines:
        line = raw_line.strip()

        # State start
        state_match = re.match(r"State (\d+)", line)
        if state_match:
            current_state = int(state_match.group(1))
            all_states.add(current_state)
            continue

        if current_state is None or line == "":
            continue

        # DEFAULT (must come before all other checks)
        if "$default" in line:
            _ = action_table[current_state]
            if "reduce using rule" in line:
                m = re.search(r"rule\s+(\d+)", line)
                if m:
                    default_actions[current_state] = f"r{m.group(1)}"
            elif re.search(r'\baccept\b', line) and "reduce" not in line:
                default_actions[current_state] = "acc"

        # SHIFT + ACCEPT merged (some bison versions emit "shift and accept")
        elif "shift" in line and re.search(r'\baccept\b', line):
            sym = extract_symbol(line)
            if sym:
                action_table[current_state][sym].append("acc")

        # SHIFT
        elif "shift, and go to state" in line:
            sym = extract_symbol(line)
            next_state = line.split()[-1]
            if sym:
                action_table[current_state][sym].append(f"s{next_state}")

        # REDUCE (explicit, no brackets)
        elif "reduce using rule" in line and '[' not in line:
            sym = extract_symbol(line)
            m = re.search(r"rule\s+(\d+)", line)
            if sym and m:
                action_table[current_state][sym].append(f"r{m.group(1)}")

        # BRACKETED REDUCE — bison resolved this conflict, loser shown in [...]
        # e.g.  '['   [reduce using rule 37 (unary_expression)]
        # FIX: extract symbol from START of line (before bracket region),
        # and extract rule directly from \[reduce...\] — do NOT do a blanket
        # replace('[','') because that would corrupt symbols like '['  and '('
        elif re.search(r'\[reduce using rule', line):
            sym = extract_symbol(line)
            m = re.search(r'\[reduce using rule\s+(\d+)', line)
            if sym and m:
                action_table[current_state][sym].append(f"r{m.group(1)}")

        # ACCEPT
        elif re.search(r'\baccept\b', line) and "reduce" not in line and "$default" not in line:
            sym = extract_symbol(line)
            if sym:
                action_table[current_state][sym].append("acc")

        # GOTO (non-terminals only)
        elif "go to state" in line and "shift" not in line:
            sym = extract_symbol(line)
            next_state = line.split()[-1]
            if sym and sym not in terminals:
                goto_table[current_state][sym] = next_state
                non_terminals.add(sym)


# -------------------------------
# STEP 3: APPLY DEFAULTS
# -------------------------------
def apply_defaults():
    for state in all_states:
        default = default_actions.get(state)

        if not default:
            continue

        for t in terminals:
            # Use .get() — avoids creating ghost empty-list entries in the defaultdict
            existing = action_table[state].get(t)
            if not existing:
                action_table[state][t] = [default]


# -------------------------------
# STEP 4: FORMAT CELL
# -------------------------------
def format_cell(actions):
    if not actions:
        return ""
    return "/".join(sorted(set(actions)))


# -------------------------------
# STEP 5: WRITE CSV
# -------------------------------
def write_csv():
    all_states_sorted = sorted(all_states)
    non_terms_sorted = sorted(non_terminals)

    with open(OUTPUT_FILE, "w", newline="") as f:
        writer = csv.writer(f)

        # Header
        writer.writerow(["State"] + terminals + non_terms_sorted)

        # Rows
        for state in all_states_sorted:
            row = [state]

            # ACTION columns
            for t in terminals:
                cell = format_cell(action_table[state].get(t, []))
                row.append(cell)

            # GOTO columns
            for nt in non_terms_sorted:
                row.append(goto_table[state].get(nt, ""))

            writer.writerow(row)


# -------------------------------
# MAIN
# -------------------------------
def main():
    with open(INPUT_FILE, "r", encoding="utf-8-sig") as f:
        lines = f.readlines()

    extract_terminals(lines)
    parse_states(lines)
    apply_defaults()
    write_csv()

    print("Parsing table written to:", OUTPUT_FILE)


if __name__ == "__main__":
    main()