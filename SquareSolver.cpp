/*!
\file
\brief This fail contains descriptions and code of all functions
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "SquareSolver.hpp"

/*!
\brief Function greet user
\details Say "Hello, this program helps to solve quadratic equations!"
\code
void greeting() {
    printf("Hello, this program helps to solve quadratic equations!\n");
}
\endcode
*/

void greeting() {
    printf("Hello, this program helps to solve quadratic equations!\n");
}

/*!
\brief Program reads users input
\details Assigns values to k1, k2 and k3
\param[in,out] k1 Coefficient before x^2
\param[in,out] k2 Coefficient before x
\param[in,out] k3 Free coefficient
\return Return 1 if input correct and 0 if input is wrong.
\code
int input(double *k1, double *k2, double *k3) {
    printf("Enter the coefficients a, b and c separated by a space\n");
    if (scanf("%lf %lf %lf", k1, k2, k3) == 3)
        return 1;
    else
        return 0;
}
\endcode
*/

int input(double *k1, double *k2, double *k3) {
    printf("Enter the coefficients a, b and c separated by a space\n");
    if (scanf("%lf %lf %lf", k1, k2, k3) == 3)
        return 1;
    else
        return 0;
}

/*!
\brief Notifies the user of invalid input
\details Clears the line on invalid input and print
"Oh no, you entered another symbol. Be more attentive and try again!"
\code
void failedInput()
{
    while ((getchar()) != '\n') continue;
    printf("Oh no, you entered another symbol. Be more attentive and try again!\n");
}
\endcode
*/

void failedInput() {
    while ((getchar()) != '\n') continue;
    printf("Oh no, you entered another symbol. Be more attentive and try again!\n");
}

/*!
\brief Compare two double variables
\details Operation == can be incorrect for double variables.
So this function can compare them with precision 1e-7
\param [in] x First double
\param [in] y Second double
\return Return 1 if x equal y and 0 if it is wrong.
\code
int isequal(double x, double y) {
    double eps = 1e-7;

    if(fabs(x - y) < eps)
        return 1;
    else
        return 0;
}
\endcode
*/

int isequal(double x, double y) {
    double eps = 1e-7;

    if(fabs(x - y) < eps)
        return 1;
    else
        return 0;
}

/*!
\brief Solves square equation
\details Assigns roots and returns the number of answers
\param[in] k1 Coefficient before x^2
\param[in] k2 Coefficient before x
\param[in] k3 Free coefficient
\param[in,out] s1 First root
\param[in,out] s2 Second root
\return Return number of answers
\code
int solve(double k1, double k2, double k3, double *s1, double *s2) {
    assert(isfinite(k1) && isfinite(k2) && isfinite(k3) && "number must be finite");
    assert(*s1 != NULL && *s2 != NULL && "s1 and s2 must have not null address");
    assert(*s1 != *s2 && "must point to different variables");

    if (isequal(k1, 0))
        return linearSolve(k2, k3, s1);
    else
        return squareSolve(k1, k2, k3, s1, s2);
}
\endcode
*/

int solve(double k1, double k2, double k3, double *s1, double *s2) {
    assert(isfinite(k1) && isfinite(k2) && isfinite(k3) && "number must be finite");
    assert(*s1 != NULL && *s2 != NULL && "s1 and s2 must have not null address");
    assert(*s1 != *s2 && "must point to different variables");

    if (isequal(k1, 0))
        return linearSolve(k2, k3, s1);
    else
        return squareSolve(k1, k2, k3, s1, s2);
}

/*!
\brief Solve linear equation
\details Assigns roots and solve linear equation
\param[in] k2 Coefficient before x
\param[in] k3 Free coefficient
\param[in,out] s1 First root
\return Return number of answers
\code
int linearSolve(double k2, double k3, double *s1) {
    assert(isfinite(k2) && isfinite(k3) && "number must be finite");
    assert(*s1 != NULL  && "s1 must have not null address");

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
\endcode
*/

int linearSolve(double k2, double k3, double *s1) {
    assert(isfinite(k2) && isfinite(k3) && "number must be finite");
    assert(*s1 != NULL  && "s1 must have not null address");

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

/*!
\brief Solve square equation, if k1 not equal 0 (first coefficient before x^2)
\details Assigns roots and solve quadratic equation
\param[in] k1 Coefficient before x^2
\param[in] k2 Coefficient before x
\param[in] k3 Free coefficient
\param[in,out] s1 First root
\param[in,out] s2 Second root
\return Return number of answers
\code
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
\endcode
*/

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

/*!
\brief Print answer for equation
\details Print answer in the form [number of roots]<roots>
\param [in] s1 First root
\param [in] s2 Second root
\param [in] ans Indicates how many roots(allAnswers)
\code
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
\endcode
*/

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

/*!
\brief Ask user if he want continue
\details Asks"Do you want continue? y/n" and writes down the answer
\param[out] sym Answer on the question
\code
void nextEquation(char *sym) {
    printf("Do you want continue? y/n\n");
    while (!isspace(getchar())) continue;
    scanf("%c", sym);
}
\endcode
*/

void nextEquation(char *sym) {
    printf("Do you want continue? y/n\n");
    while (!isspace(getchar())) continue;
    scanf("%c", sym);
}

/*!
\brief Function says goodbye
\details Say "Program completed! Have a good day!"
\code
void goodbye() {
    printf("Program completed! Have a good day!\n");
}
\endcode
*/

void goodbye() {
    printf("Program completed! Have a good day!\n");
}
