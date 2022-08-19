#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "SquareSolver.hpp"

int main() {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    char cont = 'y';
    enum allAnswers ans;

    greeting();
    while (cont == 'y') {
        while(!input(&a, &b, &c)) failedInput();
        ans = (allAnswers) solve(a, b, c, &x1, &x2);
        output(x1, x2, ans);
        nextEquation(&cont);
    }
    goodbye();

    return 0;
}
