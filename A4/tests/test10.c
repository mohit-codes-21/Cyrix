/* test10.c - Complex: nested loops + compound ops + logical ops */
int n = 4;
int i;
int j;
int total = 0;
for (i = 1; i <= n; i = i + 1) {
    j = 1;
    while (j <= i) {
        if (j != i && j > 0)
            total += i * j;
        j = j + 1;
    }
}
