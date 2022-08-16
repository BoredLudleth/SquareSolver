#include <stdio.h>
#include <math.h>                                 //uses for pow() and for NAN and isnan()
#include "name.h"

int main(void)
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    greeting();
    while(input(a, b, c)) {
        solve(a, b, c, x1, x2);
        output(x1, x2);
    }
    goodbye();

    return 0;
}

void greeting()
{
    printf("Hello, this program helps to solve quadratic equations!\n");
    printf("Type any symbol to exit\n");
}

int input(double &k1, double &k2, double &k3)
{
    printf("Enter the coefficients a, b and c separated by a space\n");
    if (scanf("%lf %lf %lf", &k1, &k2, &k3) == 3)
        return 1;
    else
        return 0;
}

void solve(double k1, double k2, double k3, double &s1, double &s2)
{
    double dis = NAN;

    s1 = s2 = NAN;
    //case, when it's linear equation
    if (k1 == 0) {
        if (k2 == 0) {
            if (k3 == 0) {
                s1 = 0;
                s2 = 0;
            }
        } else
            s1 = -k3/k2;
    //case, when it's quadratic equation
    } else {
        dis = k2*k2 - 4*k1*k3;
        if (dis > 0) {
            s1 = (-k2 - pow(dis, 0.5))/(2*k1);
            s2 = (-k2 + pow(dis, 0.5))/(2*k1);
        }
        else if (dis == 0)
            s1 = -k2/(2*k1);
    }
}

void output(double s1, double s2)
{
    if (s1 == 0 and s2 == 0)
        infinitySolution();
    else if (!isnan(s1) and !isnan(s2))
        twoSquareSolution(s1, s2);
    else if (!isnan(s1) and isnan(s2))
        oneSolution(s1);
    else if (isnan(s1) and isnan(s2))
        noSolution();

}

void infinitySolution()
{
    printf("An infinite number of solutions\n");
}

void noSolution()
{
    printf("No solutions\n");
}

void oneSolution(double s1)
{
    printf("One solution x = %lf\n", s1);
}

void twoSquareSolution(double s1, double s2)
{
    printf("Two solutions x1 = %lf, x2 = %lf\n", s1, s2);
}

void goodbye()
{
    printf("Program completed! Have a good day!\n");
}
