/*!
\file
\brief File contains checker order
*/

#include <stdio.h>
#include <math.h>
#include "SquareSolver.hpp"
#include "Tests.hpp"

int main() {
    double a = NAN, b = NAN, c = NAN;
    enum allAnswers ans;

    FILE *mytests = fopen("TEST.txt", "r");
    if (mytests == NULL) {
        printf("Error, can't find file TEST.txt");
        return 1;
    }

    while (fscanf(mytests, "%lf %lf %lf %d", &a, &b, &c, &ans) == 4) {
       test(a, b, c, ans);
    }

    fclose(mytests);
    return 0;
}

void test(double k1, double k2, double k3, int correctAns) {
    double x1 = NAN, x2 = NAN;
    bool is_correct = false;

    if (squareSolve(k1, k2, k3, &x1, &x2) == correctAns) {
        if (correctAns == INFINITYANSWERS or correctAns == NOANSWERS) {
            is_correct = true;
        } else if (correctAns == ONEANSWER) {
            if (isequal(k1 * x1 * x1 + k2 * x1 + k3, 0))
                is_correct = true;
        } else if (correctAns == TWOANSWERS) {
            if (isequal(k1 * x1 * x1 + k2 * x1 + k3, 0) && isequal(k1 * x2 * x2 + k2 * x2 + k3, 0))
                is_correct = true;
        }
    }
    if (is_correct)
        printf("Test[#] - True\n");
    else
        printf("Test[#] - False. Problem with a = %lf, b = %lf, c = %lf,"
               " found roots x1 = %lf, x2 =%lf\n", k1, k2, k3, x1, x2);
}
