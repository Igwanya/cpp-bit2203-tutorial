#include "bit2203/bit2203.hpp"

#include <iostream>
#include <limits>

namespace bit2203 {

  void exe_01() {
    std::cout << "Enter the number of gallons: ";
    double gallons;
    std::cin >> gallons;
    std::cout << "The equivelent in cubic feet: " << ( gallons / 7.481) << std::endl;
  }

  void exe_09()
  {
    std::cout << "N\t10*N\t100*N\t1000*N" << std::endl;
    for(int N=1; N <= 5; ++N) {
        std::cout << N << " \t"<< 10 * N << "\t" << 100*N << "\t" << 1000*N << std::endl;
      }
  }

  void exe_02()
  {
    std::cout << "1990 135\n";
    std::cout << "1991 7290\n";
    std::cout << "1992 11300\n";
    std::cout << "1993 16200\n";
  }

  void exe_03()
  {
    std::cout << "Enter an ammount in dollars: ";
    double dollars;
    std::cin >> dollars;
    std::cout << dollars << " in british pounds: " << dollars / 1.487<< std::endl;
    std::cout << dollars << " in franc: " << dollars / 0.172 << std::endl;
    std::cout << dollars << " in deutschemark: " << dollars /0.584 << std::endl;
    std::cout << dollars << " in yen: " << dollars / 0.00955 << std::endl;
  }

  void exe_04 ()
  {
    std::cout << "Enter the temp in degrees: ";
    float deg{0.0};
    std::cin >> deg;
    float farh{0.0};
    std::cout << "Fahrenheit: " << deg * (9.0/ 5.0) + 32 << std::endl;
  }

  void ignoreLine()
  {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  void exe_05()
  {
    double comm{0.0};
    double ammount{0.0};
    std::cout << "Enter the number of items sold: ";
    int items{};
    std::cin >> items;

    for(int x= 1; x <= items; ++x) {
        std::cout << "Enter the ammount sold for item " << x << " : ";
        std::cin >> ammount;
        ammount += ammount;
      }
    std::cout << "Earnings: " << 2000 + (ammount * 0.09) << std::endl;

  }

  void exe_10() {
    for (int outter = 1; outter <= 10; ++outter) {
        for(int inner = 1; inner <= outter ; ++inner ) {
            std::cout << "*";
          }
        std::cout << "\n";
      }

    for(int x= 1; x <= 10; ++x) {
        for(int y = x; y <= 10; ++y) {
            std::cout << "*";
          }
        std::cout << "\n";
      }

    for(int x= 1; x <= 10; ++x) {
        for(int y = x; y <= 10; ++y) {
            std::cout << "*";
          }
        std::cout << "\n";
      }

    for (int outter = 1; outter <= 10; ++outter) {
        for(int inner = 1; inner <= outter ; ++inner ) {
            std::cout << "*";
          }
        std::cout << "\n";
      }
  }

  void exe_06_break()
  {
    while (true) {
        std::cout << "Enter 0 to exit or an int:";
        int x;
        std::cin >> x;

        if (x == 0) {
            break;
          }
      }
    std::cout << "Execution continues after the break\n";
  }

  void exe_06_continue()
  {

    for (int count{ 0 }; count < 10; ++count)
      {
        if ((count % 2) == 0) {
            std::cout << "The number " << count << " is even\n";
            continue;
          }
        std::cout << count << '\n';
      }
  }

  void exe_07()
  {
    int x{0};
    for(x =1; x<=15; ++x) {
        if (x % 2 != 0) {
            x *= x;
          }
      }
    std::cout << "The product of odd numbers [ 1 -15 ] is: " << x << std::endl;
  }

  void exe_08()
  {
    int n{15};
    long double factorial = 1.0;
    for(int i = 1; i <= n; ++i) {
        factorial *= i;
      }
    std::cout << "Factorial of " << n << " = " << factorial << std::endl;
  }

}
