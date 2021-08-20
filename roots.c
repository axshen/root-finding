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
    double x1 = 100.0;
    double x0 = 2.5;
    double h = 0.01;
    double tolerance = 0.1;

    double fx, dfdx;

    // Run loop
    while (TRUE) 
    {
        fx = f(x0);
        dfdx = (f(x0 + h) - fx) / h;
        x1 = x0 - fx / dfdx;
        if (fabs(x1 - x0) < tolerance)
        {
            break;
        }
        x0 = x1;
        iter ++;
    };

    printf("%f\n", x1);
    printf("Iterations: %i\n", iter);
    return 0;
}