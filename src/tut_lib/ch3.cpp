#include "tut/ch3.hpp"

#include <math.h>
#include <cmath>
#include <random>
#include <ctime>
#include <iostream>
#include <chrono>

#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/log/trivial.hpp>

using namespace boost::gregorian;

namespace tut {
  namespace ch3 {
    double exe_3_01(double a, double b, double c);

    double FirstRoot(double a, double b, double c)
    {
      double r1 {(-b + sqrt(exe_3_01(a,b,c))) / (2 * a) };
      BOOST_LOG_TRIVIAL(debug) << "The first root: " << r1;
      return std::round( (r1 / 100000) * 10000000000 ) / 100000 ;
    }
    double SecondRoot(double a, double b, double c) {
      double r2 { (-b - sqrt(exe_3_01(a,b,c))) / (2 * a)};
      BOOST_LOG_TRIVIAL(debug) << "The second root: " << r2;
      return std::round( (r2 / 100000) * 10000000000 ) / 100000;
    }

    double exe_3_01(double a, double b, double c) {
      double discriminant { pow(b, 2) - (4 * a * c)};
      discriminant = std::round( (discriminant / 100000) * 10000000000 ) / 100000;
      if (discriminant > 0 ) {
          BOOST_LOG_TRIVIAL(debug) << "The equation has 2 real roots\n";
          return discriminant;
        }
      if (discriminant == 0) {
          BOOST_LOG_TRIVIAL(debug) << "The equation has one root\n";
          return discriminant;
        }
      if (discriminant < 0) {
          BOOST_LOG_TRIVIAL(debug) << "The equation has no real roots\n";
          return discriminant;
        }
      return discriminant;
    }

    void exe_3_02() {
      // Initialize our mersenne twister with a random seed based on the clock
      std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
      // Create a reusable random number generator that generates uniform numbers between 1 and 6
      std::uniform_int_distribution random_number{ 1, 10 };
      int num1 {random_number(mersenne)};
      int num2 {random_number(mersenne)};
      int num3 {random_number(mersenne)};
      std::cout << "what is : " << num1 << " + " << num2 << " + " << num3 <<"\n";
      std::cout << "Enter your answer: ";
      int answer{0};
      std::cin >> answer;
      int sum{ num1 + num2 + num3 };
      if (answer == sum ) {
          std::cout << "Correct , the answer is: "<< sum <<"\n";
        } else {
          std::cout << "Incorrect , the answer is: " << sum << "\n";
        }
    }

    std::vector<double> exe_3_03(double x1, double y1, double z1, double x2, double y2,double z2) {
      double x {( ((z1*y2) - (y1*z2)) / ((x1*y2) - (y1*x2)) )};
      x = std::round( (x / 10) * 100 ) / 10;
      double y { ( ((x1*z2) - (z1*x2)) / ((x1*y2) - (y1*x1)) ) };
      y = std::round( (y / 10) * 100 ) / 10;
      std::vector<double> sol;
      double exp {x1*y2 - y1*x2};
      if (exp == 0) {
          BOOST_LOG_TRIVIAL(debug) << "The equation has no solution \n";
          BOOST_LOG_TRIVIAL(debug) << "x is : " << x << " and y is: " << y << "\n";
          sol.push_back(x);
          sol.push_back(y);
          return sol;
        } else {
          BOOST_LOG_TRIVIAL(debug) << "x is : " << x << " and y is: " << y << "\n";
          sol.push_back(x);
          sol.push_back(y);
          return sol;
        }
      return sol;
    }

    void exe_3_04() {
      // Initialize our mersenne twister with a random seed based on the clock
      std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
      // Create a reusable random number generator that generates uniform numbers between 1 and 6
      std::uniform_int_distribution random_number{ 1, 12 };
      BOOST_LOG_TRIVIAL(debug) << "The english month name: " << greg_month(random_number(mersenne));
    }

    void exe_3_05() {
      std::cout << "Enter today's day[ 0 - 6]: ";
      int today;
      std::cin >> today;
      if (today > 6) {
          std::cout << "Incorrect date, enter again: ";
          std::cin >> today;
        }
      std::cout << "Enter the number of days elapsed since today[1 - 31]: ";
      int elapsed_days;
      std::cin >> elapsed_days;
      if (elapsed_days > 31) {
          std::cout << "Incorrect date, enter again: ";
          std::cin >> elapsed_days;
        }
      days future_day{ days{today} + days {elapsed_days} };
      /// todo:: solution incomplete.
      std::cout << "Today is " << greg_weekday(today) << " and the future day is: "<< future_day.days() <<std::endl;
      BOOST_LOG_TRIVIAL(warning) << " The furture date is incorrect.\n";
    }

    void exe_3_06() {
      std::cout << "Enter the weight in pounds: ";
      double weight{0.0};
      std::cin >> weight;
      std::cout << "Enter feet: ";
      double feet{0.0};
      std::cin >> feet;
      std::cout << "Enter inches: ";
      double height{0.0};
      std::cin >> height;

      constexpr double KILOGRAMS_PER_POUND = 0.45359237; // Constant
      constexpr double METERS_PER_INCH = 0.0254;

      double weightInKilograms = weight * KILOGRAMS_PER_POUND;
      double heightInMeters = height * METERS_PER_INCH;
      double bmi = weightInKilograms /
          (heightInMeters * heightInMeters);

      std::cout << "BMI is : " << bmi << std::endl;
      if (bmi < 18.5) {
          std::cout << "Underweight\n";
        } else if(bmi < 25) {
          std::cout << "Normal\n";
        } else if(bmi < 30) {
          std::cout << "Overweight\n";
        } else {
          std::cout << "Obese\n";
        }
    }

    void exe_3_07() {
      std::cout << "Enter an amount, for example 11.56:";
      double ammount;
      std::cin >> ammount;
      int remainingAmmount{ static_cast<int>(ammount * 100)};
      int numberOfDollars { static_cast<int>(remainingAmmount / 100) };
      remainingAmmount = remainingAmmount % 100;
      int numberOfQuarters = remainingAmmount / 25;
      remainingAmmount = remainingAmmount % 25;
      int numberOfDimes = remainingAmmount / 10;
      remainingAmmount = remainingAmmount % 10;
      int numberOfNickels = remainingAmmount / 5;
      remainingAmmount = remainingAmmount % 5;
      int numberOfPenies = remainingAmmount;
      std::cout << "The ammount " << ammount << std::endl;

      if (numberOfDollars > 0) {
          std::cout << "Number of dollars: " << numberOfDollars << "s\n";
        } else {
          std::cout << "Number of dollar: " << numberOfDollars << std::endl;
        }
      if (numberOfQuarters > 0) {
          std::cout << "Number of quarters: " << numberOfQuarters << "s\n";
        } else {
          std::cout << "Number of quarter: " << numberOfQuarters << std::endl;
        }
      if (numberOfDimes > 0) {
          std::cout << "Number of dimes: " << numberOfDimes << "s\n";
        } else {
          std::cout << "Number of dime: " << numberOfDimes << std::endl;
        }
      if (numberOfNickels > 0) {
          std::cout << "Number of nickels: " << numberOfNickels << "s\n";
        } else {
          std::cout << "Number of nickel: " << numberOfNickels << std::endl;
        }
      if (numberOfPenies > 0) {
          std::cout << "Number of penies: " << numberOfPenies << "s\n";
        } else {
          std::cout << "Number of penies: " << numberOfPenies << std::endl;
        }

    }

    void exe_3_08() {
      int numbers, thousands, hundreds, tens;
      std::cout << "Enter the 3 numbers: ";
      std::cin >> numbers; // 432

      tens = numbers % 10; // 2
      int hundredsAndThousands = numbers / 10; // 43
      hundreds = hundredsAndThousands % 10; // 3
      thousands = hundredsAndThousands / 10;
      BOOST_LOG_TRIVIAL(debug) << "Thousands: " << thousands << " hundreds: " << hundreds << " tens: " << tens <<"\n";
      if (thousands == hundreds && hundreds == tens
          && thousands == tens) {
          std::cout << "Numbers already sorted\n";
        }
      std::vector<int> sort; // 345 435
      int temp;
      if (hundreds < thousands || tens < thousands) // 259
        {
          if (hundreds < thousands)
            {
              temp = thousands;
              thousands = hundreds;
              hundreds = temp;
            }
          if (tens < thousands)
            {
              temp = thousands;
              thousands = tens;
              tens = temp;
            }
        }
      if (tens < hundreds)
        {
          temp = hundreds;
          hundreds = tens;
          tens = temp;
        }
      std::cout << "Sort : " << tens << " " << hundreds << " " << thousands << std::endl;
    }

    void exe_3_09()
    {
      std::cout << "Enter the first 9 digits of an ISBN: ";
      int isbn{0};
      std::cin >> isbn;
      int d9{ isbn % 10 };
      int rem {isbn / 10};
      int d8{ rem % 10 };
      rem = rem / 10;
      int d7{ rem % 10 };
      rem =rem / 10;
      int d6{rem % 10};
      rem = rem / 10;
      int d5{rem % 10};
      rem = rem / 10;
      int d4{rem % 10};
      rem = rem / 10;
      int d3{rem % 10};
      rem = rem / 10;
      int d2{ rem % 10};
      rem = rem /10;
      int d1{ rem };
      int d10{ (d1*1) + (d2*2) + (d3*3) + (d4*4) + (d5*5) + (d6*6) + (d7*7) + (d8*8) + (d9*9) };
      d10 = d10 % 11;

      std::string s{ std::to_string(isbn)};

      if (d10 == 10) {
          s.append("X");
          std::cout << "The ISBN-10 number is: "<< s << std::endl;
        } else {
          s.append(std::to_string(d10));
          std::cout << "The ISBN-10 number is: "<< s << std::endl;
        }
    }

    void exe_3_10() {
      auto seed = std::chrono::system_clock::now().time_since_epoch().count();
      auto mtgen = std::mt19937{static_cast<unsigned int>(seed) };
      auto ud = std::uniform_int_distribution<>{1, 100};
      auto number1 = ud(mtgen);
      auto number2 = ud(mtgen);
      std::cout << "What is " << number1 << " + " << number2 << "? ";
      int answer{0};
      std::cin >> answer;
      if (number1+number2 == answer) {
          std::cout << "You are correct !\n";
        } else {
          std::cout << "Your answer is wrong, "<< number1 << " + " << number2 << " should be " << number1 + number2 << std::endl;

        }
    }

    void exe_3_11() {
      std::cout << "Enter a month [1 -12]: ";
      int month{0};
      std::cin >> month;
      std::cout << "Enter a year, i,e 2022: ";
      int year;
      std::cin >> year;
      using namespace boost::gregorian;
      auto end_of_month_day = gregorian_calendar::end_of_month_day(year, month);
      std::cout << " "<< greg_month(month) << " had " << end_of_month_day << " days." << std::endl;
    }

    void exe_3_12() {
      std::cout << "Enter a three digit integer: ";
      int number;
      std::cin >> number;
      int number3 { number % 10 } ;
      int rem { rem / 10 };
      int number2{ rem % 10 };
      rem =rem / 10;
      int number1{ rem % 10 };
      if (number1 == number3) {
          std::cout << " " << number << " is a palindrome\n";
        } else {
          std::cout << number << " is not a palindrome\n";
        }

    }

    void exe_3_13() {


      // Prompt the user to enter filing status
      std::cout << "(0-single filter, 1-married jointly or " <<
                   "qualifying widow(er), 2-married separately, 3-head of " <<
                   "houshold) Enter the filing status: ";
      int status{0};
      std::cin >> status;

      // Prompt the user to enter taxable income
      std::cout << "Enter the taxable income: ";
      double income{0};
      std::cin >> income;

      // Compute tax
      double tax = 0;
      switch (status)
        {
        case 0 : // Compute tax for single filers
          tax += (income <= 8350) ? income * 0.10 : 8350 * 0.10;
          if (income > 8350)
            tax += (income <= 33950) ? (income - 8350) * 0.15 :
                                       25600 * 0.15;
          if (income > 33950)
            tax += (income <= 82250) ? (income - 33950) * 0.25 :
                                       48300 * 0.25;
          if (income > 82250)
            tax += (income <= 171550) ? (income - 82250) * 0.28 :
                                        89300 * 0.28;
          if (income > 171550)
            tax += (income <= 372950) ? (income - 171550) * 0.33 :
                                        201400 * 0.33;
          if (income > 372950)
            tax += (income - 372950) * 0.35;
          break;
        case 1 : // Compute tax for married file jointly or qualifying widow(er)
          tax += (income <= 16700) ? income * 0.10 : 16700 * 0.10;
          if (income > 16700)
            tax += (income <= 67900) ? (income - 16700) * 0.15 :
                                       (67900 - 16700) * 0.15;
          if (income > 67900)
            tax += (income <= 137050) ? (income - 67900) * 0.25 :
                                        (137050 - 67900) * 0.25;
          if (income > 137050)
            tax += (income <= 208850) ? (income - 137050) * 0.28 :
                                        (208850 - 137050) * 0.28;
          if (income > 208850)
            tax += (income <= 372950) ? (income - 208850) * 0.33 :
                                        (372950 - 208850) * 0.33;
          if (income > 372950)
            tax += (income - 372950) * 0.35;
          break;
        case 2 : // Compute tax for married separately
          tax += (income <= 8350) ? income * 0.10 : 8350 * 0.10;
          if (income > 8350)
            tax += (income <= 33950) ? (income - 8350) * 0.15 :
                                       (33950 - 8350) * 0.15;
          if (income > 33950)
            tax += (income <= 68525) ? (income - 33950) * 0.25 :
                                       (68525 - 33950) * 0.25;
          if (income > 68525)
            tax += (income <= 104425) ? (income - 68525) * 0.28 :
                                        (104425 - 68525) * 0.28;
          if (income > 104425)
            tax += (income <= 186475) ? (income - 104425) * 0.33 :
                                        (186475 - 104425) * 0.33;
          if (income > 186475)
            tax += (income - 186475) * 0.35;
          break;
        case 3 : // Compute tax for head of household
          tax += (income <= 11950) ? income * 0.10 : 11950 * 0.10;
          if (income > 11950)
            tax += (income <= 45500) ? (income - 11950) * 0.15 :
                                       (45500 - 11950) * 0.15;
          if (income > 45500)
            tax += (income <= 117450) ? (income - 45500) * 0.25 :
                                        (117450 - 45500) * 0.25;
          if (income > 117450)
            tax += (income <= 190200) ? (income - 117450) * 0.28 :
                                        (190200 - 117450) * 0.28;
          if (income > 190200)
            tax += (income <= 372950) ? (income - 190200) * 0.33 :
                                        (372950 - 190200) * 0.33;
          if (income > 372950)
            tax += (income - 372950) * 0.35;
          break;
        default : std::cout << "Error: invalid status\n";
          quick_exit(1);
        }
      // Display the result
      std::cout << "Tax is " << (int)(tax * 100) / 100.0 << std::endl;
    }

    void exe_3_14() {
      auto seed = std::chrono::system_clock::now().time_since_epoch().count();
      auto mtgen = std::mt19937{static_cast<unsigned int>(seed)};
      auto ud = std::uniform_int_distribution<>{0, 1};
      auto coin_side { ud(mtgen) };
      std::cout << "Guess the coin flip [ 0= heads, 1=Tails ]: ";
      int guess{0};
      std::cin >> guess;

      if (guess == 0 && coin_side == 0) {
          std::cout << "Correct guess, Heads\n";
        } else {
          std::cout << "Incorrect guess, Tails\n";
        }
    }

    std::string exe_3_15(int digits) {
      auto seed {std::chrono::steady_clock::now().time_since_epoch().count()};
      auto mtgen {std::mt19937{static_cast<unsigned int >(seed)}};
      auto ud {std::uniform_int_distribution<>(100, 999)};

      std::string response1{"Exact match: you win $10,000"};
      std::string response2{"Match all digits: you win $3,000"};
      std::string response3{"Match one digit: you win $1,000"};
      std::string response4{"Sorry, no match"};

      int lottery { ud(mtgen) }; // genereate the lottery number
      int lottery1{}, lottery2{}, lottery3{}, lrem{};
      lottery3 = lottery % 10;
      lrem = lottery / 10;
      lottery2 = lrem % 10;
      lottery3 = lrem / 10;


      int guess1{}, guess2{}, guess3{}, rem{};
      guess3 = digits % 10;
      rem = digits / 10;
      guess2 = rem % 10;
      guess1 = rem / 10;

      if (guess1 == lottery1 && guess2 == lottery2 && guess3 == lottery3) {
          BOOST_LOG_TRIVIAL(debug) << "Lottery: "<< lottery << " guess: "<< response1;
          return response1;
        } else if(digits == lottery) {
          BOOST_LOG_TRIVIAL(debug) << "Lottery: "<< lottery << " guess: "<< response2;
          return response2;
        } else if(guess1 == lottery1 || guess2 == lottery2 || guess3 == lottery3) {
          BOOST_LOG_TRIVIAL(debug) << "Lottery: "<< lottery << " guess: "<< response3;
          return response3;
        } else {
          BOOST_LOG_TRIVIAL(debug) << "Lottery: "<< lottery << " guess: "<< response4;
          return response4;
        }

      return response4;
    }

    void exe_3_16() {
      auto seed = std::chrono::system_clock::now().time_since_epoch().count();
      auto mtgen = std::mt19937{ static_cast<unsigned int >(seed)};
      auto ud = std::uniform_int_distribution<>(0, 100);
      auto ud1 = std::uniform_int_distribution<>(0, 200);
      int x{ ud(mtgen) }, y{ ud1(mtgen) };
      std::cout << "The random coordinate of the recatangle start: x1=" << x << " y1=" << y << std::endl;
    }

    void exe_3_17() {
      auto seed = std::chrono::system_clock::now().time_since_epoch().count();
      auto mtgen = std::mt19937{static_cast<unsigned int >(seed)};
      auto ud = std::uniform_int_distribution(1,2);
      int guess = ud(mtgen);

      std::cout << "scissor (0), rock (1), paper (2): ";
      int ans{};
      std::cin >> ans;

      if (ans == 1 && guess == 0) {
          std::cout << "The computer is scissor. You are rock. You won\n";
        }
      if (ans == 1 && guess == 1) {
          std::cout << "The computer is rock. You are rock too. It is a draw\n";
        }
      if (ans == 0 && guess == 2){
          std::cout << "The computer is paper. You are scissor. You won\n";
        }
      if(ans == 0 && guess == 0) {
          std::cout << "The computer is scissor. You are scissor too. It is a draw.\n";
        }
      if (ans == 2 && guess == 1) {
          std::cout << "The computer is rock. You are paper. You win\n.";
        }
      if (ans == 2 && guess == 2) {
          std::cout << "The computer is paper. You are paper. It is a draw\n";
        }
    }

    double exe_3_18(int x1, int y1, int x2, int y2, int x3, int y3)
    {
      if (x1 + y1 > x3 && x3 + y3 > x2 + y2 ||
          (x1 + y1 > x2 + y2 && x3 + y3 > x2 + y2) ||
          (x3 + y3 > x1 + y1 && x2 + y2 > x1 + y1)) {
          std::cout << "The input is valid \n";
        } else {
          std::cout << "The inputs are invalid!\n";
          std::exit(0);
        }
      double perimeter{0.0};
      double l1 = sqrt(pow((x2-x1), 2) + pow(y2-y1, 2));
      double l2 = sqrt(pow(x3 - x2, 2) + pow(y3 -y2, 2));
      double l3 = sqrt(pow(x3 - x1, 2) + pow(y3 -y1, 2));
      std::cout << " The perimeter is: " << l1 + l2 + l3;
      perimeter = l1 + l2 + l3;
      return std::round(perimeter * 1000) / 1000.0;
    }

    void exe_3_20()
    {
      // Prompt the user to enter a temperature and a wind speed
      std::cout << "Enter the temperature in Fahrenheit "
                   "between -58F and 41F: ";
      double temperature{0.0};
      std::cin >> temperature;
      std::cout << "Enter the wind speed (>= 2) in miles per hour: ";
      double speed{0.0};
      std::cin >> speed;

      if (temperature <= -58 || temperature >= 41 || speed < 2)
        {
          std::cout << "The ";
          if (temperature <= -58 || temperature >= 41)
            std::cout << "temperature ";
          if ((temperature <= -58 || temperature >= 41) && speed < 2)
            std::cout << "and ";
          if (speed < 2)
            std::cout << "wind speed ";
          std::cout << "is invalid";
          std::exit(1);
        }

      // Compute the wind chill index
      double windChill = 35.74 + 0.6215 * temperature -
          35.75 * pow(speed, 0.16) +
          0.4275 * temperature * pow(speed, 0.16);

      // Display result
      std::cout << "The wind chill index is " << windChill;
    }

  }
}
