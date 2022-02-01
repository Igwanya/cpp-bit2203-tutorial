#nclude <iostream>
#include <cmath>

#include "tut/ch4.hpp"

namespace tut {

  namespace ch4 {

    double exe_4_01(double length)
    {
      const double PI = std::acos(-1);
      double side{2 * length * std::sin(PI/5) };
      double area { (5 * std::pow(s, 2)) / (4 * std::tan(PI/5))  };
      return std::round(area * 100) / 100;
    }

  }

}
