#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "SquareSolver.hpp"

void greeting() {
    printf("Hello, this program helps to solve quadratic equations!\n");
}

int input(double *k1, double *k2, double *k3) {
    printf("Enter the coefficients a, b and c separated by a space\n");
    if (scanf("%lf %lf %lf", k1, k2, k3) == 3)
        return 1;
    else
        return 0;
}

void failedInput()
{
    while ((getchar()) != '\n') continue;
    printf("Oh no, you entered another symbol. Be more attentive and try again!\n");
}

int isequal(double x, double y) {
    double eps = 1e-7;

    if(fabs(x - y) < eps)
        return 1;
    else
        return 0;
}

int solve(double k1, double k2, double k3, double *s1, double *s2) {
    assert(isfinite(k1) && isfinite(k2) && isfinite(k3) && "number must be finite");
    assert(*s1 != NULL && *s2 != NULL && "s1 and s2 must have not null address");
    assert(*s1 != *s2 && "must point to different variables");

    if (isequal(k1, 0))
        return linearSolve(k2, k3, s1);
    else
        return squareSolve(k1, k2, k3, s1, s2);
}

int linearSolve(double k2, double k3, double *s1) {
    assert(isfinite(k2) && isfinite(k3) && "number must be finite");
    assert(*s1 != NULL  && "s1 mustn't have null address");

    if (isequal(k2, 0)) {
        if (isequal(k3, 0))
            return INFINITYANSWERS;
        else
            return NOANSWERS;
    } else {
        *s1 = -k3 / k2;
        return ONEANSWER;
    }
}

int squareSolve(double k1, double k2, double k3, double *s1, double *s2) {
    assert(isfinite(k1) && isfinite(k2) && isfinite(k3) && "number must be finite");
    assert(*s1 != NULL && *s2 != NULL && "s1 and s2 must have not null address");

    double dis = NAN;

    dis = k2 * k2 - 4 * k1 * k3;
    k1 *= 2;
    dis = sqrt(dis);

    if (dis > 0) {
        *s1 = (-k2 - dis) / k1;
        *s2 = (-k2 + dis) / k1;
        return TWOANSWERS;
    }
    else if (isequal(dis, 0)) {
        *s1 = -k2 / k1;
        return ONEANSWER;
    } else {
        return NOANSWERS;
    }
}

void output(double s1, double s2, int ans) {
    switch(ans) {
        case NOANSWERS:
            printf("No solutions\n");
            break;
        case ONEANSWER:
            printf("One solution x = %lf\n", s1);
            break;
        case TWOANSWERS:
            printf("Two solutions x1 = %lf, x2 = %lf\n", s1, s2);
            break;
        case INFINITYANSWERS:
            printf("An infinite number of solutions\n");
            break;
        default:
            break;
    }

}

void nextEquation(char *sym) {
    printf("Do you want continue? y/n\n");
    while (!isspace(getchar())) continue;
    scanf("%c", sym);
}

void goodbye() {
    printf("Program completed! Have a good day!\n");
}
