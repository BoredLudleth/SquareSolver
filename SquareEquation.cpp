#include <stdio.h>
#include <math.h>                                 //uses for pow() and for NAN
#include <assert.h>
#include <ctype.h>
#include "name.h"
#include "deffunc.cpp"

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int x_count = -1;
    char cont = 'y';

    greeting();
    while (cont == 'y'){
        while(!input(&a, &b, &c))
            failedInput();
        x_count = solve(a, b, c, &x1, &x2);
        output(x_count, x1, x2);
        nextEquation(&cont);
    }
    goodbye();

    return 0;
}
