#include <stdio.h>
#include <math.h>                                 //uses for pow() and for NAN
#include "name.h"

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int x_count = -1;

    greeting();
    while(input(&a, &b, &c)) {
        solve(a, b, c, &x1, &x2, &x_count);
        output(x_count, x1, x2);
    }
    goodbye();

    return 0;
}

void greeting()
{
    printf("Hello, this program helps to solve quadratic equations!\n");
    printf("Type any symbol to exit\n");
}

int input(double *k1, double *k2, double *k3)
{
    printf("Enter the coefficients a, b and c separated by a space\n");
    if (scanf("%lf %lf %lf", &*k1, &*k2, &*k3) == 3)
        return 1;
    else
        return 0;
}

void solve(double k1, double k2, double k3, double *s1, double *s2, int *roots)
{
    double dis = NAN;

    *s1 = *s2 = NAN;
    *roots = -1;
    //case, when it's linear equation
    if (k1 == 0) {
        if (k2 == 0) {
            if (k3 == 0) {
                *roots = 3;
            } else
                *roots = 0;
        } else {
            *s1 = -k3/k2;
            *roots = 1;
        }
    //case, when it's quadratic equation
    } else {
        dis = k2*k2 - 4*k1*k3;
        if (dis > 0) {
            *s1 = (-k2 - pow(dis, 0.5))/(2*k1);
            *s2 = (-k2 + pow(dis, 0.5))/(2*k1);
            *roots = 2;
        }
        else if (dis == 0) {
            *s1 = -k2/(2*k1);
            *roots = 1;
        } else
            *roots = 0;
    }
}

void output(int roots, double s1, double s2)
{
    switch(roots) {
        case 0:
            printf("No solutions\n");
            break;
        case 1:
            printf("One solution x = %lf\n", s1);
            break;
        case 2:
            printf("Two solutions x1 = %lf, x2 = %lf\n", s1, s2);
            break;
        case 3:
            printf("An infinite number of solutions\n");
            break;
    }

}

void goodbye()
{
    printf("Program completed! Have a good day!\n");
}
