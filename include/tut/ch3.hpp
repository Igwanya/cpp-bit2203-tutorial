#ifndef CH3_HPP
#define CH3_HPP

#include <vector>
#include <string>

namespace tut {
  namespace ch3 {

    /**
     * solve quadratic equations.
     *
     * r1 = \f$-b + \sqrt{b^2-4ac} / 2a\f$
     * r2 =  \f$-b - \sqrt{b^2-4ac} / 2a\f$
     *
     * b 2 - 4ac is called the discriminant of the quadratic equation.
     *  If it is positive, the equation has two real roots.
     *   If it is zero, the equation has one root. If it is negative,
     *   the equation has no real roots. If the discriminant is positive, two roots found.
     *    If the discriminant is 0 , display one root. Otherwise,
     *     “The equation has no real roots”.
     *
     *     @param  a
     *     @param  b
     *     @param  c
     *
     *     @return the quadratic equation is solved
     *
     */
    double exe_3_01(double a, double b, double c);
    double FirstRoot(double a, double b, double c);
    double SecondRoot(double a, double b, double c);

    /**
     * @brief Game: add three numbers.
     *
     * generate three single-digit integers and prompt the user to
     * enter the sum of these three integers
     *
     */
    void exe_3_02();

    /**
     *  @brief Algebra: solve 2 * 2 linear equations.
     *
     *  A linear equation can be solved using Cramer’s rule given in
     *  Programming Exercise 1.13. Write a program that prompts
     *  x1, y1, z1, x2, y2, and x2 and displays the result.
     *
     *  @note If x1.y2 - y1.x2 is 0 ,  “The equation has no solution.”
     *
     *  The formualae:
     *                  x = ( (z1.y2 -y1.z2) / (x1.y2 - y1.x2) )
     *                  y = ( (x1.z2 - z1.x2) / (x1.y2 -y1.x1) )
     *
     *   @param x1
     *   @param y1
     *   @param z1
     *   @param x2
     *   @param y2
     *   @param z2
     *
     *  @return x,y the solution
     */
    std::vector<double> exe_3_03(double x1, double y1, double z1, double x2, double y2,double z2);

    /**
     * @brief Random month.
     *
     *  Write a program that randomly generates an integer between 1
     *  and 12 and displays the English month name January,
     *  February, …, December for the number 1, 2, …, 12, accordingly.
     */
    void exe_3_04();


    /**
     * @brief Find future dates.
     *
     * Write a program that prompts the user to enter an integer for today’s day
     *  of the week (Sunday is 0, Monday is 1, …, and Saturday is 6).
     *  Also prompt the user to enter the number of days after today
     *  or a future day and display the future day of the week
     */
    void exe_3_05();

    /**
     * @brief Health application: BMI.
     *
     *  Revise Listing 3.4, ComputeAndInterpretBMI.java,
     *   to let the user enter weight, feet, and inches.
     *    For example, if a person is 5 feet and 10 inches,
     *    you will enter 5 for feet and 10 for inches
     */
    void exe_3_06();

    /**
     * @brief Financial application: monetary units
     *
     *  Modify Listing 2.10, ComputeChange.java, to display
     *  the nonzero denominations only, using singular words for single
     *  units such as 1 dollar and 1 penny,
     *  and plural words for more than one unit such as 2 dollars and 3 pennies.
     */
    void exe_3_07();

    /**
     * @brief Sort three integers.
     *
     *  Write a program that prompts the user to enter three integers
     *  and display the integers in non-decreasing order.
     */
    void exe_3_08();

    /**
     * @brief Business: check ISBN-10.
     *
     *  An ISBN-10 (International Standard Book Number) consists of 10 digits:
     *  d 1 d 2 d 3 d 4 d 5 d 6 d 7 d 8 d 9 d 10 . The last digit, d 10 , is a checksum,
     *  which is calculated from the other nine digits
     *
     *  @note using the following formula:
     *          (d 1 * 1 + d 2 * 2 + d 3 * 3 + d 4 * 4 + d 5 * 5 +
     *          d 6 * 6 + d 7 * 7 + d 8 * 8 + d 9 * 9) % 11
     *
     *  If the checksum is 10 , the last digit is denoted as X according to the ISBN-10
     *  convention. Write a program that prompts the user to enter the first 9 digits and
     *  displays the 10-digit ISBN (including leading zeros).
     */
    void exe_3_09();

    /**
     * @brief Game: addition quiz
     *
     * Listing 3.3, SubtractionQuiz.java, randomly generates a subtraction question.
     *  Revise the program to randomly generate an addition question with
     *  two integers less than 100.
     */
    void exe_3_10();

    /**
     * @brief Find the number of days in a month
     *
     *  Write a program that prompts the user to enter the month and year and
     *   displays the number of days in the month. For example,
     *    if the user entered month 2 and year 2012 , the program should display
     *    that February 2012 had 29 days. If the user entered month 3 and year 2015 ,
     *     the program should display that March 2015 had 31 days.
     */
    void exe_3_11();

    /**
     * @brief Palindrome number.
     *
     *  Write a program that prompts the user to enter a three-digit integer
     *   and determines whether it is a palindrome number. A number is palindrome
     *   if it reads the same from right to left and from left to right.
     */
    void exe_3_12();

    /**
     * @brief Financial application: compute taxes.
     *
     *  Listing 3.5, ComputeTax.java, gives the source code to compute taxes
     *   for single filers. Complete Listing 3.5 to compute the taxes for all filing statuses.
     */
    void exe_3_13();

    /**
     * @brief Game: heads or tails.
     *
     *  Write a program that lets the user guess whether the flip of a coin results in heads or tails.
     *  The program randomly generates an integer 0 or 1 , which represents head or tail.
     *   The program prompts the user to enter a guess and reports whether the guess is correct or incorrect.
     */
    void exe_3_14();

    /**
     * @brief Game: lottery.
     *
     *  Revise Listing 3.8, Lottery.java, to generate a lottery of a three digit number.
     *  The program prompts the user to enter a three-digit number and determines whether
     *  the user wins according to the following rules
     *
     *  @param digits the 3 digit lottery number
     *
     *  @return award the string mathching the lottery number.
     */
    std::string exe_3_15(int digits);

    /**
     * @brief Random point.
     *
     * Write a program that displays a random coordinate in a rectangle.
     * The rectangle is centered at (0, 0) with width 100 and height 200.
     */
    void exe_3_16();

    /**
     * @brief Game: scissor, rock, paper.
     *
     *  Write a program that plays the popular scissor-rock-paper game.
     *   (A scissor can cut a paper, a rock can knock a scissor, and a paper canwrap a rock.)
     *   The program randomly generates a number 0 , 1 , or 2 representing scissor,
     *    rock, and paper. The program prompts the user to enter a number 0 , 1 , or 2
     *    and displays a message indicating whether the user or the computer wins, loses, or draws.
     *
     */
    void exe_3_17();


    /**
     * @brief Compute the perimeter of a triangle
     *
     * Write a program that reads three edges for
     * a triangle and computes the perimeter if the input is valid.
     * Otherwise, display that the input is invalid.
     *  The input is valid if the sum of every pair of two edges is
     *  greater than the remaining edge.
     *
     *  @note
     *
     *  The distance between \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is
     *            \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.
     *
     *  @param x1     the triangle co-ordinates
     *  @param y1  co-ordinate
     *  @param x2  co-ordinate
     *  @param y2  co-ordinate
     *  @param x3  co-ordinate
     *  @param y3  co-ordinate
     *
     *  @return the perimeter
     */
    double exe_3_18(int x1, int y1, int x2, int y2, int x3, int y3);

    /**
     * @brief SCience : wind chill temparature
     *
     *  Programming Exercise 2.17 gives a formula to compute the wind-chill temperature.
     *  The formula is valid for temperatures in the range between −58ºF and 41ºF
     *   and wind speed greater than or equal to 2 .
     *   Write a program that prompts the user to enter a temperature and a wind speed.
     *   The program displays the wind-chill temperature if the input is valid; otherwise,
     *   it displays a message indicating whether the temperature and/or wind speed is invalid/
     */
    void exe_3_20();

    /**
     * @brief Science: day of the week.
     *
     *  Zeller’s congruence is an algorithm developed by Christian Zeller to calculate the day of the week.
     *
     *  @note:
     *      the division in the formula performs an integer division
     *      j is the century i.e (year /100 )
     *
     *      \f$ h = ( q + \frac{26(m + 1)}{10} + k + \frac{k}{4} + \frac{j}{4} + 5j ) % 7\f$
     *
     *  @param k is the year of the century (i.e., year % 100).
     *
     *  @param m is the month (3: March, 4: April, …, 12: December).
     *            January and February are counted as months 13 and 14 of the previous year.
     *
     *  @param q is the day of the month.
     *
     *  @returns h is the day of the week
     *            (0: Saturday, 1: Sunday, 2: Monday, 3: Tuesday, 4: Wednesday, 5: Thursday, 6: Friday).
     *
     */
    int exe_3_21(int k, int m, int q);

    /**
     * @brief Geometry: point in a circle
     *
     * Write a program that inputs a point ( x , y ) and checks whether the point
     * is within the circle centered at ( 0 , 0 ) with radius 10.
     * A point is in the circle if its distance to ( 0 , 0 ) is less than or equal to 10 .
     * formulae:
     *          d = \f$\sqrt{(x_2 - x_1)^2 + (y_2 - y_1)}\f$
     *
     * @note
     *      For example, ( 4 , 5 ) is inside the circle and ( 9 , 9 ) is outside the circle
     *
     *  @param x The x-axis of the circle.
     *  @param y The y- axis of the circle.
     *
     *  @returns true/false if the point is i the circle.
     */
    bool exe_3_22(double x, double y);

    /**
     * @brief Geometry: point in a rectangle?.
     *
     *  Write a program that inputs a point (x, y)
     *  and checks whether the point is within the
     *  rectangle centered at ( 0 , 0 ) with width 10 and height 5
     *
     *  @note
     *    A point is in the rectangle if its horizontal distance to
     *     ( 0 , 0 ) is less than or equal to 10 / 2 and its
     *     vertical distance to ( 0 , 0 ) is less than or equal to 5.0 / 2
     *
     *  @param x
     *  @param y
     *
     *  @returns true/false if the point is within the rectangle.
     */
    bool exe_3_23(double x, double y);

    /**
     * @brief Geometry: intersecting point.
     *
     *  Two points on line 1 are given as ( x1 , y1 ) and ( x2 ,y2 )
     *  and on line 2 as ( x3 , y3 ) and ( x4 , y4 ). T
     *  his linear equation can be solved using Cramer’s rule
     *
     *  @note The intersecting point of the two lines can be found
     *  by solving the following linear equation:
     *    \f$ x(y_1 - y_2) - y(x_1 - x_2) = x_1(y_1 - y_2) - y_1(x_1 - x_2) \f$
     *    \f$ x(y_3 - y_4) - y(x_3 - x_4) = x_3(y_3 - y_4) - y_3(x_3 - x_4) \f$
     *
     *  @param x1 The first point of the first line.
     *  @param y1
     *  @param x2 The second point of the first line
     *  @param y2
     *  @param x3 The first point of the second line.
     *  @param y3
     *  @param x4 The second point of the second line.
     *  @param y4
     *
     *  Displays the point of intersection, parallel otherwise
     */
    void exe_3_25(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    /**
     *  @brief Game: pick a card.
     *
     *  Write a program that simulates picking a card from a deck of 52 cards.
     *   Your program should display the rank
     *   ( Ace , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , Jack , Queen , King )
     *    and suit ( Clubs , Diamonds , Hearts , Spades ) of the card.
     */
    void exe_3_24();

    /**
     * @brief Use the && , || and ^ operators.
     *
     *  Write a program that prompts the user to enter an integer and determines
     *  whether it is divisible by 5 and 6, whether it is divisible by 5 or 6,
     *   and whether it is divisible by 5 or 6, but not both.
     */
    void exe_3_26();


  }
}

#endif // CH3_HPP
