#include <math.h>
#include <stdio.h>

double func(double x)
{
    return 1 + pow(x, 2); // формула (можно менять)
}

double simpson(const double eps, const double a, const double b, const int n0)
{
    int n = n0, j;

    double sq[2], delta = 1;
    for (j = 0; delta > eps; n *= 2, j ^= 1)
    {
        double h = (b - a) / n;
        double s = func(a) + func(b);
        int k = 4;
        for (int i = 1; i < n; i++)
        {
            s += k * func(a + h * i);
            k = 6 - k;
        }
        sq[j] = s * h / 3;
        if (n > n0)
            delta = fabs(sq[j] - sq[j ^ 1]) / 3.0;
    }
    return sq[j];
}

int main()
{
    FILE* out;
    out = fopen("output.txt", "w");
    const double eps = 1E-5;
    const double a = 0;
    const double b = 4;
    const int n0 = 1000000;
    double res = simpson(eps, a, b, n0);
    fprintf(out, "result = %.6lf", res);
}