#include <stdio.h>
#include <math.h>
#include "SquareSolver.hpp"

void test() {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    //Test[#1]
    a = 0;
    b = 0;
    c = 0;
    printf("Test[#1] - ");
    if (solve(a, b, c, &x1, &x2) == INFINITYANSWERS)
        printf("True\n");
    else
        printf("False. Problem with coefficients %lf %lf %lf\n", a, b, c);
    //Test[#2]
    a = 0;
    b = 0;
    c = 1;
    printf("Test[#2] - ");
    if (solve(a, b, c, &x1, &x2) == NOANSWERS)
        printf("True\n");
    else
        printf("False. Problem with coefficients %lf %lf %lf\n", a, b, c);
    //Test[#3]
    a = 0;
    b = 1;
    c = 1;
    solve(a, b, c, &x1, &x2);
    printf("Test[#3] - ");
    if (a * x1 * x1 + b * x1 + c == 0 or a * x2 * x2 + b * x2 + c == 0)
        printf("True\n");
    else
        printf("False. Problem with coefficients %lf %lf %lf\n", a, b, c);
    //Test[#4]
    a = 1;
    b = 1;
    c = 1;
    printf("Test[#4] - ");
    if (solve(a, b, c, &x1, &x2) == NOANSWERS)
        printf("True\n");
    else
        printf("False. Problem with coefficients %lf %lf %lf\n", a, b, c);
    //Test[#5]
    a = 1;
    b = 12;
    c = 36;
    solve(a, b, c, &x1, &x2);
    printf("Test[#5] - ");
    if (a * x1 * x1 + b * x1 + c == 0 or a * x2 * x2 + b * x2 + c == 0)
        printf("True\n");
    else
        printf("False. Problem with coefficients %lf %lf %lf\n", a, b, c);
    //Test[#6]
    a = 1;
    b = 5;
    c = -6;
    solve(a, b, c, &x1, &x2);
    printf("Test[#6] - ");
    if (a * x1 * x1 + b * x1 + c == 0 and a * x2 * x2 + b * x2 + c == 0)
        printf("True\n");
    else
        printf("False. Problem with coefficients %lf %lf %lf\n", a, b, c);
}
