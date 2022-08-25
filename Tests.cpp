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
    int count_wrong = 0;
    enum allAnswers ans;

    FILE *mytests = fopen("TEST.txt", "r");
    if (mytests == NULL) {
        printf("Error, can't find file TEST.txt\n");
        return 1;
    }

    int num_test = 1;
    while (fscanf(mytests, "%lf %lf %lf %d", &a, &b, &c, &ans) == 4) {
       count_wrong += test(a, b, c, ans, num_test);
       num_test++;
    }
    printf("Wrong tests - %d\n", count_wrong);

    fclose(mytests);
    return 0;
}

int test(double a, double b, double c, int correctAns, int num_test) {
    double x1 = NAN, x2 = NAN;
    bool is_correct = false;

    if (squareSolve(a, b, c, &x1, &x2) == correctAns) {
        if (correctAns == INFINITYANSWERS or correctAns == NOANSWERS) {
            is_correct = true;
        } else if (correctAns == ONEANSWER) {
            if (isEqual(a * x1 * x1 + b * x1 + c, 0))
                is_correct = true;
        } else if (correctAns == TWOANSWERS) {
            if (isEqual(a * x1 * x1 + b * x1 + c, 0) && isEqual(a * x2 * x2 + b * x2 + c, 0))
                is_correct = true;
        }
    }
    if (is_correct) {
        printf("Test[#%d] - True\n", num_test);
        return 0;
    } else {
        printf("Test[#%d] - False. Problem with a = %lf, b = %lf, c = %lf, "
               "found roots x1 = %lf, x2 = %lf\n", num_test, a, b, c, x1, x2);
        return 1;
    }
}
