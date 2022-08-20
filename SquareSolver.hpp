/*!
\file
\brief Header file with function definitions
\details This file contains definitions of the main functions
*/

/*! Set of all possible answers
\code
enum allAnswers {
    NOANSWERS = 0, ///< Indicates that equation hasn't got roots
    ONEANSWER = 1, ///< Indicates that equation has got one root
    INFINITYANSWERS = 2, ///< Indicates that equation has got infinity roots
    TWOANSWERS = 3 ///< Indicates that equation has got two roots
};
\endcode
*/

enum allAnswers {
    NOANSWERS = 0, ///< Indicates that equation hasn't got roots
    ONEANSWER = 1, ///< Indicates that equation has got one root
    INFINITYANSWERS = 2, ///< Indicates that equation has got infinity roots
    TWOANSWERS = 3 ///< Indicates that equation has got two roots
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
