#ifndef CH2_HPP
#define CH2_HPP

namespace tut {
  namespace ch2 {

    /**
     *  @brief Convert Celsius to Fahrenheit.
     *
     *  Write a program that reads a Celsius degree ina double value from the console,
     *  then converts it to Fahrenheit and displays the result.
     *
     *  @note The formula for the conversion is as follows:
     *              fahrenheit = (9 / 5) * celsius + 32
     *
     *  @param celsius the temp in degree Celsius
     *
     *  @return temp in degree Fahrenheit
     */
    double exe2_1(int celsius);

    /**
     * @brief Compute the volume of a cylinder.
     *
     *  Write a program that reads in the radius and length of a cylinder and computes
     *  the area and volume.
     *
     *  @note using the following formulas:
     *              area = radius * radius * p
     *              volume = area * length
     *
     *  @param area of the cylinder
     *  @param length of the cylinder
     *
     *  @return volume of the cylinder.
     */
    double exe_2_2_volume(double area, double length);

    /**
     * @brief Compute the area of a cylinder.
     *
     * @param radius of the cylinder
     *
     * @return area
     */
    double exe_2_2_area(double radius);

    /**
     * @brief Convert feet into meters.
     *
     *  Write a program that reads a number in feet, converts it
     *  to meters, and displays the result.
     *
     *  @note One foot is 0.305 meter.
     *
     *  @param feet
     *
     *  @return metres
     */
    double exe_2_3(double feet);

    /**
     * @brief Convert pounds into kilograms.
     *
     *  Write a program that converts pounds into kilograms.
     *  The program prompts the user to enter a number in pounds,
     *  converts it to kilograms, and displays the result.
     *
     *  @note  One pound is 0.454 kilograms.
     *
     *  @param pound
     */
    double exe_2_4(double pound);

    /**
      * @brief Financial application: calculate tips.
      *
      *  Write a program that reads the subtotal
      *  and the gratuity rate, then computes the gratuity and total.
      *
      *  @param subtotal
      *  @param rate
      *
      *  @return void
      */
    void exe_2_5(double subtotal, double rate);

    /**
      * @brief Sum the digits in an integer.
      *
      * Write a program that reads an integer between 0 and 1000 and
      *  adds all the digits in the integer.
      *
      *  @param number
      *
      *  @return sum
      */
    int exe_2_6(int number);


    /**
      *
      * @brief Find the number of years.
      *
      * Write a program that prompts the user to enter the minutes
      * and displays the number of years and days for the minutes.
      *
      * @note assume a year has 365 days
      *
      * @param minutes
      *
      */
    void exe_2_7(int minutes);

    /**
      * @brief Current time.
      *
      * A program that displays the current time in GMT.
      * Revise the program so that the time zone offset to
      * GMT and displays the time in the specified time zone.
      *
      * @param timezone_offset
      *
      */
    void exe_2_8(int timezone_offset);

    /**
      * @brief Physics: acceleration.
      *
      *   Average acceleration is defined as the change of velocity
      *   divided by the time taken to make the change,
      *   as shown in the following formula:
      *
      *   @note a = (v1 - v0) / t
      *
      *    Write a program that the starting velocity v0 in meters/second,
      *    the ending velocity v1 in meters/second, and the time span t in seconds,
      *    and displays the average acceleration.
      *
      *   @param v0 the velocity in meters/second
      *   @param v1 the velocity in meters/second
      *   @param t the time in seconds
      *
      *   @return accelearation
      */
    double exe2_9(double v0, double v1, double t);

    /**
      * @brief Science: calculating energy.
      *
      * Write a program that calculates the energy needed to heat water from an
      * initial temperature to a final temperature. The amount of water in kilograms
      * and the initial and final temperatures of the water.
      *
      * @note The formula to compute the energy is
      *
      *           Q = M * (finalTemperature – initialTemperature) * 4184
      *   where M is the weight of water in kilograms, temperatures are in degrees Celsius,
      *   and energy Q is measured in joules
      *
      *   @param M the weight of water in kg
      *   @param initial_temp the initial temp
      *   @param final_temp the final temp
      *
      *   @return the energy needed in joules
      */
    double exe_2_10(double M, double initial_temp, double final_temp);

    /**
      * Population projection.
      *
      * Rewrite Programming Exercise 1.11 to prompt the user to enter the number
      * of years and displays the population after the number of years.
      * Use the hint in Programming Exercise 1.11 for this program.
      *
      *  @note The population should be cast into an integer.
      *
      *  @param years
      *
      *  @return population
      */
    int exe_2_11(int years);

    /**
      * (Physics: finding runway length)
      *
      * Given an airplane’s acceleration a and take-off speed v,
      * you can compute the minimum runway length needed for an
      *  airplane to take off.
      *
      *  using the following formula:
      *         length = (v*v) / (2*a)
      *     v in metres/second
      *     a in metre/second squared
      *
      *  @param v
      *  @param a
      *
      *  @return the minimum runway length
      */
    double exe_2_12(double v, double a);

    /**
      * Financial application: compound value.
      *
      * Write a program that expects monthly saving amount and
      * displays the account value after the specific month
      *
      * @param ammount the savings ammount
      * @param years the number of years.
      *
      * @return the account value
      */
    double exe_2_13(double ammount, int years);

    /**
      *
      * @brief Health application: computing BMI.
      *
      *  Body Mass Index (BMI) is a measure of health on weight.
      *  It can be calculated by taking your weight in kilograms and
      *  dividing by the square of your height in meters.
      *  Write a program that prompts the user to enter a weight
      *   in pounds and height in inches and displays the BMI.
      *
      *   @note that one pound is 0.45359237 kilograms and
      *    one inch is 0.0254 meters.
      *
      *   @param weight the weight in pounds
      *   @param inches the height in inches
      *
      *   @return the body mass index
      */
    double exe_2_14(double weight, double inches);

    /**
      *
      * @brief Geometry: distance of two points.
      *
      * Write a program that two points (x1, y1) and (x2, y2)
      *  and displays their distance between them.
      *
      *  @param   x1
      *  @param   y1
      *
      *  @param   x2
      *  @param   y2
      *
      *  @return distance
      */
    double exe_2_15(double x1, double x2, double y1, double y2);

    /**
      *
      * @brief Geometry: area of a hexagon.
      *
      * side of a hexagon and displays its area
      *
      * @param length of the hexagon
      *
      * @return the area of the hexagon
      *
      */
    double exe_2_16(double length);

    /**
      * @brief Science: wind-chill temperature.
      *
      * How cold is it outside? The temperature alone is not enough
      *  to provide the answer. Other factors including wind speed,
      *   relative humidity, and sunshine play important roles in
      *   determining coldness outside.
      *   In 2001, the National Weather Service (NWS) implemented
      *   the new wind-chill temperature to measure the coldness
      *   using temperature and wind speed.
      *
      *   @param temp the temparature in Fahrenheit
      *   @param speed the wind speedin miles per hour
      *
      *   @return the wind chill index
      */
    double exe_2_17(double temp, double speed);

    /**
      * @brief Print a table.
      *
      * Write a program that displays the following table.
      *  Cast floating-point numbers into integers
      *
      * @return void
      */
    void exe_2_18();

    /**
      * @brief Geometry: area of a triangle.
      *
      * Write a program that prompts the user to enter three points
      * (x1, y1) , (x2, y2) , (x3, y3) of a triangle and displays
      * its area.
      *
      * @param x1
      * @param y1
      * @param x2
      * @param y2
      * @param x3
      * @param y3
      *
      * @return the area of the triangle.
      *
      */
    double exe_2_19(double x1,double y1,double x2, double y2, double x3,double y3);

    /**
      * @brief Financial application: calculate interest.
      *
      * If you know the balance and the annual percentage interest rate,
      *  you can compute the interest on the next monthly pament using the
      *   following formula:
      *
      *   interest = balance * (annualInterestRate/1200)
      *
      *   @param balance
      *   @param intrest_rate
      *
      *   @return the intrest
      *
      */
    double exe_2_20(double balance, double intrest_rate);

    /**
      * Financial application: calculate future investment value.
      *
      * Write a program that reads in investment amount, annual
      * interest rate, and number of years, and displays the
      *  future investment value
      *
      *  @note:
      *       futureInvestmentValue = investmentAmount * (1 + monthlyInterestRate) ^numberOfYears*12
      *
      *  @param investmentAmount the ammount
      *  @param monthlyInterestRate the intrest rate
      *  @param numberOfYears the number of years
      *
      *  @return double the future_investment_value
      */
    double exe_2_21(double investmentAmount, double monthlyInterestRate, int numberOfYears);


  }
}

#endif // CH2_HPP
