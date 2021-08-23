#include <stdio.h>
#include <math.h>

#define TRUE 1

double f(double x)
{
    double fx = (x - 1) * (x - 5) * (2 * x - 9) + 5;
    return fx;
}

int main(void)
{
    // Initialise
    int iter = 0;

    double dfdx, fx0, fx1, x2;
    double step = 0.01;
    double x0 = 2.5;
    double x1 = 2.6;
    double tolerance = 0.1;

    fx0 = f(x0);

    // Loop
    while (TRUE)
    {
        fx1 = f(x1);
        dfdx = (fx1 - fx0) / (x1 - x0);
        x2 = x1 - dfdx * step;
        if (fabs(dfdx) < tolerance)
        {
            break;
        }
        x0 = x1;
        x1 = x2;
        fx0 = fx1;
        printf("%f\n", x1);
    
        iter ++;
    }

    printf("%f\n", x1);
    printf("Iterations: %i\n", iter);

    return 0;
}