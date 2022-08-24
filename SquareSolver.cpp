/*!
\file
\brief This fail contains descriptions and code of all functions
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "SquareSolver.hpp"

#define NEWASSERT(condition)                                                            \
    if (!(condition)) {                                                                 \
        printf("Problem with in file %s in function %s, condition %s in line %d\n",     \
               __FILE__, __FUNCTION__, #condition, __LINE__);                           \
        exit(1);                                                                        \
    }

void input(double *a, double *b, double *c) {
    NEWASSERT(a != NULL && b != NULL && c != NULL);
    printf("Hello, this program helps to solve quadratic equations!\n"
           "Enter the coefficients a, b and c separated by a space\n");
    while(scanf("%lf %lf %lf", a, b, c) != 3) {
        failedInput();
    }
}

void failedInput() {
    while ((getchar()) != '\n')
        continue;
    printf("Oh no, you entered another symbol. Be more attentive and try again!\n");
}

bool isequal(double x, double y) {
    const double EPSILON = 1e-7;

    return fabs(x - y) < EPSILON;
}

int linearSolve(double b, double c, double *x1) {
    NEWASSERT(isfinite(b) && isfinite(c));
    NEWASSERT(*x1 != 0  && "x1 must have not null address");

    if (isequal(b, 0)) {
        if (isequal(c, 0))
            return INFINITYANSWERS;
        else
            return NOANSWERS;
    } else {
        *x1 = -c / b;
        return ONEANSWER;
    }
}

int squareSolve(double a, double b, double c, double *x1, double *x2) {
    NEWASSERT(isfinite(a) && isfinite(b) && isfinite(c) && "number must be finite");
    NEWASSERT(*x1 != 0 && *x2 != 0 && "x1 and x2 must have not null address");

    if (isequal(a, 0)) {
        return linearSolve(b, c, x1);
    }

    double dis = b*b - 4*a*c;

    a *= 2;
    if (dis > 0) {
        dis = sqrt(dis);
        *x1 = (-b - dis) / a;
        *x2 = (-b + dis) / a;
        return TWOANSWERS;
    } 
    if (isequal(dis, 0)) {
        *x1 = -b / a;
        return ONEANSWER;
    }
    return NOANSWERS;
}

void output(double x1, double x2, int numOfAnswers) {
    switch(numOfAnswers) {
        case NOANSWERS:
            printf("No solutions\n");
            break;
        case ONEANSWER:
            printf("One solution x = %lf\n", x1);
            break;
        case TWOANSWERS:
            printf("Two solutions x1 = %lf, x2 = %lf\n", x1, x2);
            break;
        case INFINITYANSWERS:
            printf("An infinite number of solutions\n");
            break;
        default:
            printf("Something go wrong");
            break;
    }
    printf("Program completed! Have a good day!\n");
}
