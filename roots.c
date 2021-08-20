#include <stdio.h>
#include <math.h>

#define TRUE 1

double f(double x) {
    double fx = (x - 1) * (x - 5) * (2 * x - 9) + 5;
    return fx;
}

int main(void) {
    // Initialisation
    double x1 = 100.0;
    double x0 = 2.5;
    double h = 0.01;
    double dx = 0.1;

    double fx, dfdx;

    // Run loop
    while (TRUE) 
    {
        fx = f(x0);
        dfdx = (f(x0 + h) - fx) / h;
        x1 = x0 - fx / dfdx;
        if (fabs(x1 - x0) < dx)
        {
            break;
        }
        x0 = x1;
    };

    printf("%f", x1);

    return 0;
}