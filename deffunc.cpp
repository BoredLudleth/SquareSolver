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

void failedInput()
{
	while ((getchar()) != '\n');
        printf("Oh no, you entered another symbol. Be more attentive and try again!\n");
}

int isequal(double x, double y) {
    double eps = 1e-7;

    if(fabs(x - y) < eps)
        return 1;
    else
        return 0;
}

int solve(double k1, double k2, double k3, double *s1, double *s2) {
    assert(isfinite(k1));
	assert(isfinite(k2));
	assert(isfinite(k3));

	assert(*s1 != NULL);
	assert(*s2 != NULL);
	assert(*s1 != *s2);
    if (isequal(k1, 0)) {
        linearSolve(k2, k3, &*s1);
    } else
        squareSolve(k1, k2, k3, &*s1, &*s2);
}

int linearSolve(double k2, double k3, double *s1) {
    if (isequal(k2, 0)) {
        if (isequal(k3, 0))
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
    else if (isequal(dis, 0)) {
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
        default:
            break;
    }

}

void nextEquation(char *sym) {
    printf("Do you want continue? y/n\n");
    while (!isspace(getchar()));
        scanf("%c", &*sym);
}

void goodbye() {
    printf("Program completed! Have a good day!\n");
}
