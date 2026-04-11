/* test08.c - Scoping and block nesting */
int x = 1;
int y = 2;
{
    int x = 100;
    y = x + y;
    {
        int z = x * 2;
        y = y + z;
    }
}
int result = x + y;
