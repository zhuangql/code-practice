#define BOOST_TEST_MODULE zhuang-test
#include "boost/test/included/unit_test.hpp"
#include "iostream"
BOOST_AUTO_TEST_SUITE(test_suit)
BOOST_AUTO_TEST_CASE(test_case)
{
	int a=1;
	std::cout << "1111111111111111111" << std::endl;
	BOOST_CHECK_EQUAL(a,1);
}

BOOST_AUTO_TEST_CASE(test_case2)
{
        int a=2;
        std::cout << "2222222222222222222" << std::endl;
        BOOST_CHECK_EQUAL(a,1);
}


BOOST_AUTO_TEST_SUITE_END()


