#include <stdio.h>
#include <math.h>
double f(double x)
{
    return x * x - 2;
}
double df(double x)
{
    return 2 * x;
}
int main()
{
    double x0, x1, e;
    int iter = 0;
    printf("Enter initial guess: ");// 2 10
    scanf("%lf", &x0);
    printf("Enter tolerance: ");
    scanf("%lf", &e);
    do
    {
        x1 = x0 - f(x0) / df(x0);
        iter++;
        printf("Iteration %d: x = %lf\n", iter, x1);
        x0 = x1;
    } while (fabs(f(x1)) > e);
    printf("Root found after %d iterations: %lf\n", iter, x1);
    return 0;
}
