/* test09.c - for loop with break and continue */
int sum = 0;
int i;
for (i = 0; i < 10; i = i + 1) {
    if (i == 5)
        break;
    if (i == 2)
        continue;
    sum = sum + i;
}
