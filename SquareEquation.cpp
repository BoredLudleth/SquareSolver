#include <stdio.h>
#include <math.h>                                 //uses for pow() and for NAN

int main(void)
{
    double a = NAN, b = NAN, c = NAN;
    void greeting();
    int input(double &k1, double &k2, double &k3);
    void solve(double k1, double k2, double k3);
    void goodbye();

    greeting();
    while (input(a, b, c))
        solve(a, b, c);
    goodbye();

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

void solve(double k1, double k2, double k3)
{
    void infinitySolution();
    void noSolution();
    void linearSolution(double k2, double k3);
    void oneSquareSolution(double k1, double k2);
    void twoSquareSolution(double k1, double k2, double k3);
    double dis = NAN;

    //case, when it's linear equation
    if (k1 == 0) {
        if (k2 == 0) {
            if (k3 == 0)
                infinitySolution();
            else
                noSolution();
        } else
            linearSolution(k2, k3);
    //case, when it's quadratic equation
    } else {
        dis = k2*k2 - 4*k1*k3;
        if (dis > 0)
            twoSquareSolution(k1, k2, k3);
        else if (dis == 0)
            oneSquareSolution(k1, k2);
        else
            noSolution();
    }
}

void infinitySolution()
{
    printf("An infinite number of solutions\n");
}

void noSolution()
{
    printf("No solutions\n");
}

void linearSolution(double k2, double k3)
{
    printf("One solution x=%lf\n", -k3/k2);
}

void oneSquareSolution(double k1, double k2)
{
    printf("One solution x = %lf\n", -k2/(2*k1));
}

void twoSquareSolution(double k1, double k2, double k3)
{
    double dis = NAN;

    dis = k2*k2 - 4*k1*k3;
    printf("Two solutions x1 = %lf, x2 = %lf\n",
    (-k2 - pow(dis, 0.5))/(2*k1), (-k2 + pow(dis, 0.5))/(2*k1));
}

void goodbye()
{
    printf("Program completed! Have a good day!\n");
}
