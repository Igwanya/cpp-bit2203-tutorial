#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MAIN

#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

#include "tut/ch2.hpp"

BOOST_AUTO_TEST_SUITE(chapter_2_test_suite)

BOOST_AUTO_TEST_CASE( convert_celsius_to_degree_fahrenheit_test )
{
  BOOST_CHECK_EQUAL(tut::ch2::exe2_1(43.0), 109.4);
}

BOOST_AUTO_TEST_CASE(compute_the_area_of_cylinder_test,
                     * boost::unit_test::label("compute_the_area_of_cylinder_test"))
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_2_area(5.5), 95.0332);
}

BOOST_AUTO_TEST_CASE(compute_the_volume_of_cylinder_test,
                     * boost::unit_test::depends_on("chapter_2_test_suite/compute_the_area_of_cylinder_test")
                     * boost::unit_test::description("The function depends on the area of the cylinder test")
                     )
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_2_volume(
                      tut::ch2::exe_2_2_area(5.5), 12), 1140.4);
}

BOOST_AUTO_TEST_CASE(convert_feet_to_metres_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_3(16.5), 5.0325);
}

BOOST_AUTO_TEST_CASE(convert_pounds_into_kilograms_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_4(55.5), 25.197);
}

BOOST_AUTO_TEST_CASE(sum_the_digits_in_an_integer_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_6(999), 27);
}

BOOST_AUTO_TEST_CASE(average_acceleration_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe2_9(5.5, 50.9, 4.5), 10.0889);
}

BOOST_AUTO_TEST_CASE(science_calculating_energy_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_10(55.5, 3.5, 10.5), 1625484);
}

BOOST_AUTO_TEST_CASE(population_projection_test) {
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_11(5), 325932966);
}

BOOST_AUTO_TEST_CASE(physics_finding_runway_length_test) {
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_12(60.0, 3.5), 514.286);
}

BOOST_AUTO_TEST_CASE(financial_application_compound_value_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_13(100.0, 6), 608.818);
}

BOOST_AUTO_TEST_CASE(health_application_computing_BMI_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_14(95.5, 50), 26.8573);
}

BOOST_AUTO_TEST_CASE(geometry_distance_of_two_points_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_15(1.5, -3.4, 4.0, 5.0), 5.001);
}

BOOST_AUTO_TEST_CASE(geometry_area_of_a_hexagon_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_16(5.5), 78.5918);
}

BOOST_AUTO_TEST_CASE(science_wind_chill_temperature_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_17(5.3, 6), -5.56707);
}

BOOST_AUTO_TEST_CASE(area_of_a_triangle_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_19(1.5, -3.4, 4.6, 5, 9.5, -3.4), 33.6);
}

BOOST_AUTO_TEST_CASE(calculate_interest_test) {
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_20(1000, 3.5), 2.91667);
}

BOOST_AUTO_TEST_CASE(calculate_future_investment_value_test)
{
  BOOST_CHECK_EQUAL(tut::ch2::exe_2_21(1000.56, 4.25, 1), 1043.92);
}

BOOST_AUTO_TEST_SUITE_END()
