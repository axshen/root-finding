#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TRUE 1

double f(double x)
{   
    double noise = 0.05;
    double random = (double)rand() / RAND_MAX * 2.0 - 1.0;
    double fx = fabs(sqrt(2.0 * x + 3.0) - 3.0 + noise * random);
    return fx;
}

int main(void)
{
    // Initialise
    int iter = 0;

    double dfdx, fx0, fx1, x2;
    double step = 0.1;
    double x0 = 1.5;
    double x1 = 1.6;
    double tolerance = 0.01;

    fx0 = f(x0);

    // Loop
    while (TRUE)
    {
        fx1 = f(x1);
        dfdx = (fx1 - fx0) / (x1 - x0);
        x2 = x1 - dfdx * step;
        if (fabs(fx1) < tolerance)
        {
            break;
        }

        if (iter > 500) {
            printf("Too many iterations required...\n");
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