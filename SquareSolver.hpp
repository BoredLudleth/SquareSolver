/*!
\mainpage Program for solving square equations
Program uses for solving square equations ax^2 + bx + c = 0.
It includes linear cases.
\author BoredLudleth
\version 1.0
\date August 2022
*/

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
    NOANSWERS       = 0, ///< Indicates that equation hasn't got roots
    ONEANSWER       = 1, ///< Indicates that equation has got one root
    INFINITYANSWERS = 2, ///< Indicates that equation has got infinity roots
    TWOANSWERS      = 3 ///< Indicates that equation has got two roots
};

/*!
\brief Function greet user
\details Say "Hello, this program helps to solve quadratic equations!"
*/

void greeting();

/*!
\brief Program reads users input
\details Assigns values to k1, k2 and k3
\param[in,out] k1 Coefficient before x^2
\param[in,out] k2 Coefficient before x
\param[in,out] k3 Free coefficient
\return Return 1 if input correct and 0 if input is wrong.
*/

int input(double *k1, double *k2, double *k3);

/*!
\brief Notifies the user of invalid input
\details Clears the line on invalid input and print
"Oh no, you entered another symbol. Be more attentive and try again!"
*/

void failedInput();

/*!
\brief Compare two double variables
\details Operation == can be incorrect for double variables.
So this function can compare them with precision 1e-7
\param [in] x First double
\param [in] y Second double
\return Return 1 if x equal y and 0 if it is wrong.
*/

int isequal(double x, double y);

/*!
\brief Solves square equation
\details Assigns roots and returns the number of answers
\param[in] k1 Coefficient before x^2
\param[in] k2 Coefficient before x
\param[in] k3 Free coefficient
\param[in,out] s1 First root
\param[in,out] s2 Second root
\return Return number of answers
*/

int solve(double k1, double k2, double k3, double *s1, double *s2);

/*!
\brief Solve linear equation
\details Assigns roots and solve linear equation
\param[in] k2 Coefficient before x
\param[in] k3 Free coefficient
\param[in,out] s1 First root
\return Return number of answers
*/

int linearSolve(double k2, double k3, double *s1);

/*!
\brief Solve square equation, if k1 not equal 0 (first coefficient before x^2)
\details Assigns roots and solve quadratic equation
\param[in] k1 Coefficient before x^2
\param[in] k2 Coefficient before x
\param[in] k3 Free coefficient
\param[in,out] s1 First root
\param[in,out] s2 Second root
\return Return number of answers
*/

int squareSolve(double k1, double k2, double k3, double *s1, double *s2);

/*!
\brief Print answer for equation
\details Print answer in the form [number of roots]<roots>
\param [in] s1 First root
\param [in] s2 Second root
\param [in] ans Indicates how many roots(allAnswers)
*/

void output(double s1, double s2, int ans);

/*!
\brief Ask user if he want continue
\details Asks"Do you want continue? y/n" and writes down the answer
\param[out] sym Answer on the question
*/

void nextEquation(char *sym);

/*!
\brief Function tests checks the correctness of work
*/


void test();

/*!
\brief Function says goodbye
\details Say "Program completed! Have a good day!"
*/

void goodbye();
