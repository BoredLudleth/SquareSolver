void greeting() {
    printf("Hello, this program helps to solve quadratic equations!\n");
    printf("Type any symbol to exit\n");
}

int input(double *k1, double *k2, double *k3) {
    printf("Enter the coefficients a, b and c separated by a space\n");
    if (scanf("%lf %lf %lf", &*k1, &*k2, &*k3) == 3)
        return 1;
    else
        return 0;
}

int solve(double k1, double k2, double k3, double *s1, double *s2) {
    double dis = NAN;

    if (k1 == 0) {
        linearSolve(k2, k3, &*s1);
    } else
        squareSolve(k1, k2, k3, &*s1, &*s2);
}

int linearSolve(double k2, double k3, double *s1) {
    if (k2 == 0) {
        if (k3 == 0)
            return 3;
        else
            return 0;
    } else {
        *s1 = -k3 / k2;
        return 1;
        }
}

int squareSolve(double k1, double k2, double k3, double *s1, double *s2) {
    double dis = NAN;
    dis = k2 * k2 - 4 * k1 * k3;
    if (dis > 0) {
        *s1 = (-k2 - pow(dis, 0.5)) / (2 * k1);
        *s2 = (-k2 + pow(dis, 0.5)) / (2 * k1);
        return 2;
    }
    else if (dis == 0) {
        *s1 = -k2 / (2 * k1);
        return 1;
    } else
        return 0;
}

void output(int roots, double s1, double s2) {
    switch(roots) {
        case 0:
            printf("No solutions\n");
            break;
        case 1:
            printf("One solution x = %lf\n", s1);
            break;
        case 2:
            printf("Two solutions x1 = %lf, x2 = %lf\n", s1, s2);
            break;
        case 3:
            printf("An infinite number of solutions\n");
            break;
    }

}

void goodbye() {
    printf("Program completed! Have a good day!\n");
}
