#define BOOST_TEST_MODULE test1

#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MAIN

#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

#include "tut/ch4.hpp"

BOOST_AUTO_TEST_SUITE(CH4_TEST_SUITE)

BOOST_AUTO_TEST_CASE(area_of_a_pentagon_test)
{

  BOOST_TEST(tut::ch4::exe_4_01(5.5), 71.92);
}

BOOST_AUTO_TEST_SUITE_END()
