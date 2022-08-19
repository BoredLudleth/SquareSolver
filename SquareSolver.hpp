enum allAnswers {
        NOANSWERS = 0,
        ONEANSWER = 1,
        INFINITYANSWERS = 2,
        TWOANSWERS = 3
};

void greeting();

int input(double *k1, double *k2, double *k3);

void failedInput();

int isequal(double x, double y);

int solve(double k1, double k2, double k3, double *s1, double *s2);

int linearSolve(double k2, double k3, double *s1);

int squareSolve(double k1, double k2, double k3, double *s1, double *s2);

void output(double s1, double s2, int ans);

void nextEquation(char *sym);

void goodbye();
