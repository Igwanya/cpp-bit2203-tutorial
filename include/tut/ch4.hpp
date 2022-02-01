#ifndef CH4_HPP
#define CH4_HPP

namespace tut {
  namespace ch4 {

    /**
     * @brief Geometry: area of a pentagon.
     *
     * Write a program that prompts the user to enter
     * the length from the center of a pentagon to a
     * vertex and computes the area of the pentagon
     *
     * formulae:
     *    area = \f$ \frac{5 * s_2}{4 * tan(3.142/5)}\f$
     *    s = \f$ 2 * r * sin(pi/5) \f$
     *
     *    @param length from the center of the vertex
     *
     *    @returns area of the pentagon
     */
    double exe_4_01(double length);


  }

}

#endif // CH4_HPP
