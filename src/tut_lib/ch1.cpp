#include <iostream>
#include <boost/log/trivial.hpp>

#include "tut/ch1.hpp"

namespace tut {
  namespace ch1 {

void exe_1_1() {
  std::cout << "Welcome to c++" << std::endl;
  std::cout << "Welcome to computer science " << std::endl;
  std::cout << "Programming is fun " << std::endl;
}

void exe_1_2(){
  std::cout << "Welcome to c++" << std::endl;
  std::cout << "Welcome to c++" << std::endl;
  std::cout << "Welcome to c++" << std::endl;
  std::cout << "Welcome to c++" << std::endl;
  std::cout << "Welcome to c++" << std::endl;
}

void exe_1_3(){
  std::cout << "      CCCC       " << std::endl;
  std::cout << "     C           " << std::endl;
  std::cout << "     C      + +  " << std::endl;
  std::cout << "     C           " << std::endl;
  std::cout << "       CCCC      " << std::endl;
}

void exe_1_4() {
  std::cout << "a     a^2     a^3  " << std::endl;
  std::cout << "1     1       1    " << std::endl;
  std::cout << "2     4       8    " << std::endl;
  std::cout << "3     9       27   " << std::endl;
  std::cout << "4     16      64   " << std::endl;
}

void exe_1_5() {
  std::cout << (9.5 * 4.5) - (2.5 * 3) / (45.5 - 3.5) << std::endl;
}

void exe_1_6() {
  std::cout << 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 << std::endl;
}

int exe_1_7() { // BODMAS
  double x {4.0 * ( 1.0 - ( (1.0/3.0) + (1.0/5.0) ) - ( (1.0/7.0) + (1.0/9.0) ) - (1.0/11.0) )};
  double y {4.0 * ( 1.0 - ( (1.0/3.0) + (1.0/5.0) ) - ( (1.0/7.0) + (1.0/9.0) ) - ( (1.0/11.0) + (1.0/13.0) ))};
  BOOST_LOG_TRIVIAL(debug) << "Aprox val of pie: x=" << x << " : y ="<< y<< ": "<< x * y;
 return x;
}

  }

}
