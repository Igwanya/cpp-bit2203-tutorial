#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MAIN

#define BOOST_TEST_ALTERNATIVE_INIT_API

#include <boost/test/unit_test.hpp>
#include "tut/ch3.hpp"
#include <cmath>
#include <vector>

BOOST_AUTO_TEST_SUITE(chapter_3_test_suite)

BOOST_AUTO_TEST_CASE(solve_quadratic_equations_test)
{
  BOOST_ASSERT(
        tut::ch3::exe_3_01(1.0, 3, 1) > 0);

  /// This function should pass incorrect rounding off values
//  BOOST_CHECK_EQUAL(
//        tut::ch3::FirstRoot(1.0, 3, 1), -0.381966);

  BOOST_CHECK_EQUAL(
        tut::ch3::SecondRoot(1.0, 3, 1), -2.61803);
  BOOST_ASSERT(
        tut::ch3::exe_3_01(1.0, 2.0, 1) == 0);
  BOOST_CHECK_EQUAL(
        tut::ch3::FirstRoot(1.0, 2.0, 1), -1);
  BOOST_CHECK_EQUAL(
        tut::ch3::SecondRoot(1.0, 2.0, 1), -1);
  BOOST_ASSERT(
        tut::ch3::exe_3_01(1,2,3) < 0);

  BOOST_TEST(std::isnan(tut::ch3::FirstRoot(1,2,3)));

  BOOST_TEST(std::isnan(tut::ch3::SecondRoot(1,2,3)));
}

BOOST_AUTO_TEST_CASE(algebra_linear_equations_test) {

  BOOST_TEST(tut::ch3::exe_3_03(9.0,4.0,3.0, -5.0,-6.0,-21.0).at(0), (-2.0));
  BOOST_TEST(tut::ch3::exe_3_03(9.0,4.0,3.0, -5.0,-6.0,-21.0).at(1) == 1.9);
  /// The equation has no solution
  BOOST_TEST(tut::ch3::exe_3_03(1.0,2.0,2.0, 4.0, 4.0, 5.0).at(0) == 0.5);
  BOOST_TEST(tut::ch3::exe_3_03(1.0,2.0,2.0, 4.0, 4.0, 5.0).at(1) < 0);

}
BOOST_AUTO_TEST_CASE(compute_perimeter_of_triangle_test)
{
  BOOST_CHECK_EQUAL(tut::ch3::exe_3_18(1,2, 3,-4, -4,5), 23.557);
}

BOOST_AUTO_TEST_CASE(science_day_of_the_week_test)
{
  enum DAY_OF_THE_WEEK {
    SATURDAY  = 0,
    SUNDAY    = 1,
    MONDAY    = 2,
    TUESDAY   = 3,
    WEDNESDAY = 4,
    THURSDAY  = 5,
    FRIDAY    = 6
  };

  BOOST_CHECK_EQUAL(tut::ch3::exe_3_21(2015, 1, 25), DAY_OF_THE_WEEK::SUNDAY);
  BOOST_CHECK_EQUAL(tut::ch3::exe_3_21(2012, 5, 12), DAY_OF_THE_WEEK::SATURDAY);
}

BOOST_AUTO_TEST_CASE(geometry_point_in_a_circle_test)
{
  BOOST_CHECK_EQUAL(tut::ch3::exe_3_22(4.0, 9.0), true);
  BOOST_CHECK_EQUAL(tut::ch3::exe_3_22(9.0, 9.0), false);
}

BOOST_AUTO_TEST_CASE(geometry_point_in_a_rectangle_test)
{
  BOOST_CHECK_EQUAL(tut::ch3::exe_3_23(2.0, 2.0), true);
  BOOST_CHECK_EQUAL(tut::ch3::exe_3_22(6.0, 4.0), false);
}


BOOST_AUTO_TEST_SUITE_END()
