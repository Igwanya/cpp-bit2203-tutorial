#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MAIN

#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test1)

    BOOST_AUTO_TEST_CASE(test1__test) {
        BOOST_CHECK_EQUAL(1, 1);
    }

BOOST_AUTO_TEST_SUITE_END()
