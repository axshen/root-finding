#include <stdio.h>
#include <math.h>

#define TRUE 1

double f(double x) {
    double fx = (x - 1) * (x - 5) * (2 * x - 9) + 5;
    return fx;
}

int main(void) {
    // Initialisation
    int iter = 0;
    double x0 = 2.5;
    double x1 = 2.6;
    double x2;
    double tolerance = 0.01;

    double fx0, fx1, dfdx;

    fx0 = f(x0);

    // Run loop
    while (TRUE) 
    {
        fx1 = f(x1);
        dfdx = (fx1 - fx0) / (x1 - x0);
        x2 = x0 - fx0 / dfdx;
        if (fabs(x2 - x1) < tolerance)
        {
            break;
        }

        x0 = x1;
        x1 = x2;
        fx0 = fx1;
        iter ++;
    };

    printf("%f\n", x1);
    printf("Iterations: %i\n", iter);
    return 0;
}