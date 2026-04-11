/* test15.c - Mixed errors: scope redeclaration + undeclared assignment */
int a = 1;
int b = 2;
{
    int a = 10;
    int a = 20;
    b = a + q;
}
int result = a + b;
