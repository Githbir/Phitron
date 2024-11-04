#include <stdio.h>
#include <math.h>
double f(double x)
{
    return x * x - 2;
}
double false_position(double a, double b, double tol)
{
    double c, fa, fb, fc;
    if (f(a) * f(b) >= 0)
    {
        printf("Error: f(a) and f(b) must have opposite signs.\n");
        return 0;
    }
    do
    {
        fa = f(a);
        fb = f(b);
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        if (fabs(fc) < tol)
            return c;
        else if (fa * fc < 0)
            b = c;
        else
            a = c;
    } while (1);
}
int main()
{
    double a, b, tol, root;
    printf("Enter the initial interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tol);
    root = false_position(a, b, tol);
    printf("The root is: %lf\n", root);
    return 0;
}