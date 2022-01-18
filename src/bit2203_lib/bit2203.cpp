#include "bit2203/bit2203.hpp"

#include <iostream>

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

}
