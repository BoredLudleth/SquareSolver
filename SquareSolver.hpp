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

/// Set of all possible answers

enum allAnswers {
    NOANSWERS       = 0, ///< Indicates that equation hasn't got roots
    ONEANSWER       = 1, ///< Indicates that equation has got one root
    TWOANSWERS      = 2, ///< Indicates that equation has got two roots
    INFINITYANSWERS = 3  ///< Indicates that equation has got infinity roots
};

/*!
\brief Program reads users a, b and c
\details If user entered another symbol, program asks enter data again
If you enter test, you will run test
\param[in,out] a Coefficient before x^2
\param[in,out] b Coefficient before x
\param[in,out] c Free coefficient
*/

void input(double *a, double *b, double *c);

/*!
\brief Checks input 1 3 4;kladsj and 1 3 4 kk;j
\details Clears the line on invalid input and print
"Oh no, you entered another symbol. Be more attentive and try again!"
*/

bool input_check();

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

bool isEqual(double x, double y);

/*!
\brief Solves square equation
\details Assigns roots and returns the number of answers
\param[in] a Coefficient before x^2
\param[in] b Coefficient before x
\param[in] c Free coefficient
\param[in,out] x1 First root
\param[in,out] x2 Second root
\return Return number of answers
*/

int solve(double a, double b, double c, double *x1, double *x2);

/*!
\brief Solve linear equation
\details Assigns roots and solve linear equation
\param[in] b Coefficient before x
\param[in] c Free coefficient
\param[in,out] x1 First root
\return Return number of answers
*/

int linearSolve(double b, double c, double *x1);

/*!
\brief Solve square equation, if a not equal 0 (first coefficient before x^2)
\details Assigns roots and solve quadratic equation
\param[in] a Coefficient before x^2
\param[in] b Coefficient before x
\param[in] c Free coefficient
\param[in,out] x1 First root
\param[in,out] x2 Second root
\return Return number of answers
*/

int squareSolve(double a, double b, double c, double *x1, double *x2);


/*!
\brief Print answer for equation
\details Print answer in the form [number of roots]<roots>
\param [in] x1 First root
\param [in] x2 Second root
\param [in] ans Indicates how many roots(allAnswers)
*/

void output(double x1, double x2, int numOfAnswers);
