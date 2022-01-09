#include "tut/ch2.hpp"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

#include <boost/log/trivial.hpp>


namespace tut {
  namespace ch2 {

    double exe2_1(int celsius) {
      return (9.0/ 5.0) * static_cast<double>(celsius) + 32;
    }

    double exe_2_2_area(double radius) {

      BOOST_LOG_TRIVIAL(debug) << "Computed area: " << std::round(((radius * radius * M_PI) / 10000) *100000000)/10000;
      return std::round(((radius * radius * M_PI) / 10000) *100000000)/10000;
    }

    double exe_2_2_volume(double area, double length) {
      BOOST_LOG_TRIVIAL(debug) << "Computed volume: " << area * length;
      return std::round(((area * length) / 100) * 10000) / 100;
    }

    double exe_2_3(double feet) {
      return std::round(((feet * 0.305) / 10000) * 100000000) / 10000;
    }

    double exe_2_4(double pound) {
      return std::round(((pound * 0.454) / 1000) * 1000000) / 1000;
    }

    void exe_2_5(double subtotal, double rate) {
      double gratuity{ ((subtotal * (rate / 100)) * 100) / 100 };
      double total{ ((subtotal + rate) * 100) / 100 };
      std::cout << std::fixed << std::setprecision(1) << "The gratuity is: " << gratuity << " and total: "<< total;
    }

    int exe_2_6(int number) {
      int tens{number % 10}; // 2
      int rem1{number / 10}; // 93
      int rem2{rem1 % 10 }; // 3
      int rem3{rem1 / 10 }; // 9
      BOOST_LOG_TRIVIAL(debug) << "[ sum ] " << tens + rem2 + rem3;
      return tens + rem2 + rem3;
    }

    void exe_2_7(int minutes) {
      int years{minutes / 525600};
      int days{(minutes % 525600) / 1440};
      std::cout << "[ * ] " << minutes << " minutes is approximately: " << years << " and " << days << " days.";
    }

    void exe_2_8(int timezone_offset) {
      BOOST_LOG_TRIVIAL(warning) << "The timezone offset variable is not utilized.";
      std::time_t current_time = std::time(nullptr);
      BOOST_LOG_TRIVIAL(info) << "The current time is: " << std::put_time(std::gmtime(&current_time), "%H:%M:%S %Z");
    }

    double exe2_9(double v0, double v1, double t) {
      return std::round((((v1 - v0) / t) / 10000) * 100000000) / 10000;
    }

    double exe_2_10(double M, double initial_temp, double final_temp) {
      return std::round(((M * (final_temp - initial_temp) * 4184) / 100000) * 10000000000) / 100000;
    }

    int exe_2_11(int years) {
      int population{312032486 + (((31536000 / 7) - (31536000 / 13)
                     + (31536000 / 45)) * years)};
      return population;
    }
    double exe_2_12(double v, double a){
      return std::round(((std::pow(v, 2) / (2 * a)) / 1000) * 1000000) / 1000;
    }

    double exe_2_13(double ammount, int years) {
      double previous_month_account_bal{0.0};
      for (int x = 1; x <= years; ++x){
          previous_month_account_bal = (ammount + previous_month_account_bal) * (1 + (0.00417));
        }
      return std::round((previous_month_account_bal / 1000) * 1000000) / 1000;
    }

    double exe_2_14(double weight, double inches) {
      double bmi{ (weight * 0.45359237) / std::pow((inches *  0.0254), 2) };
      return  std::round((bmi / 10000) * 100000000) / 10000;
    }

    double exe_2_15(double x1, double x2, double y1, double y2) {
      double exp1{ (x2 - x1) * (x2 - x1) };
      double exp2{ (y2 - y1) * ( y2 - y1) };
      double exp3{ exp1 + exp2 };
      double distance{std::pow(exp3, 0.5)};
      return std::round((distance / 10000) * 100000000) / 10000;
    }

    double exe_2_16(double length) {
      double exp1 { (std::pow(length, 2) * 3) * std::pow(3, 0.5) };
      double exp2 { exp1 / 2  };
      return std::round((exp2 / 10000) * 100000000) / 10000;
    }

    double exe_2_17(double temp, double speed) {
      double index { 35.74 + 0.6215 * temp - 35.75 * std::pow(speed, 0.16) + 0.4275 * temp * std::pow(speed, 0.16) };
      return std::round((index / 100000) * 10000000000) / 100000;
    }

    void exe_2_18(){
      std::cout << "a\t b\t pow(a,b)\n";
      int a =0, b =1;
      for(int x=1; x <= 5; x++) {
          a++;
          b++;
          std::cout << a <<"\t "<< b << "\t " << std::pow(a,b) << "\n";
        }
    }

    double exe_2_19(double x1,double y1,double x2, double y2, double x3,double y3){
      double side1 = std::pow(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2), 0.5);
      double side2 = std::pow(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2), 0.5);
      double side3 = std::pow(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2), 0.5);
      double s = (side1 + side2 + side3) / 2;
      double area = std::pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);
      return std::round((area / 10) * 100 ) / 10;
    }

    double exe_2_20(double balance, double intrest_rate) {
      double intrest { balance  * ( intrest_rate / 1200 ) };
      return std::round((intrest / 100000) * 10000000000 ) / 100000;
    }

    double exe_2_21(double investmentAmount, double monthlyInterestRate, int numberOfYears){
      monthlyInterestRate /= 1200;
      double futureInvestmentValue { investmentAmount * std::pow(1 + monthlyInterestRate, numberOfYears * 12) };
      return futureInvestmentValue = std::round( (futureInvestmentValue / 100) * 10000 ) / 100;
    }

  }
}
