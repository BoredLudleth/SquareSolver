/*!
\file
\brief Main file compiles project
\details User run the project. Than he should enter 3 numbers.
If he entered another symbol, program asks him to enter data again.
After correct input, program output answer and ask user if he wants to continue.
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "SquareSolver.hpp"

int main() {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    input(&a, &b, &c);
    enum allAnswers ans = (allAnswers) squareSolve(a, b, c, &x1, &x2);
    output(x1, x2, ans); 

    return 0;
}
