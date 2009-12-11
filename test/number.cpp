//  (C) Copyright Johan Ditmar, Paul O'Neill & Luke Stedman 2009.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>  

using boost::unit_test::test_suite;    

#include <protean/variant.hpp>
using namespace protean;

void test_Int32()
{
    boost::int32_t arg(0xFFFFFFFF);

    variant v1(arg);
    BOOST_CHECK(v1.is<variant::Int32>());
    BOOST_CHECK(v1.is<variant::Integer>());
    BOOST_CHECK(v1.is<variant::Number>());
    BOOST_CHECK(v1.is<variant::Primitive>());
    BOOST_CHECK_EQUAL(v1.as<boost::int32_t>(), arg);
    
    variant v2;
    v2 = arg;
    BOOST_CHECK_EQUAL(v2.as<boost::int32_t>(), arg);

    variant v3(v2);
    BOOST_CHECK_EQUAL(v3.as<boost::int32_t>(), arg);

    variant v4;
    v4 = v3;
    BOOST_CHECK_EQUAL(v3.as<boost::int32_t>(), arg);

    variant v5(variant::Int32);
    BOOST_CHECK(v5.is<variant::Int32>());
    BOOST_CHECK_EQUAL(v5.as<boost::int32_t>(), 0);

    BOOST_CHECK_THROW(v1.as<boost::uint32_t>(), variant_error);
}

void test_UInt32()
{
    boost::uint32_t arg(0xFFFFFFFF);

    variant v1(arg);
    BOOST_CHECK(v1.is<variant::UInt32>());
    BOOST_CHECK(v1.is<variant::Integer>());
    BOOST_CHECK(v1.is<variant::Number>());
    BOOST_CHECK(v1.is<variant::Primitive>());
    BOOST_CHECK_EQUAL(v1.as<boost::uint32_t>(), arg);
    
    variant v2;
    v2 = arg;
    BOOST_CHECK_EQUAL(v2.as<boost::uint32_t>(), arg);

    variant v3(v2);
    BOOST_CHECK_EQUAL(v3.as<boost::uint32_t>(), arg);

    variant v4;
    v4 = v3;
    BOOST_CHECK_EQUAL(v3.as<boost::uint32_t>(), arg);

    variant v5(variant::UInt32);
    BOOST_CHECK(v5.is<variant::UInt32>());
    BOOST_CHECK_EQUAL(v5.as<boost::uint32_t>(), 0);

    BOOST_CHECK_THROW(v1.as<boost::int32_t>(), variant_error);
}

void test_Int64()
{
    boost::int64_t arg(0xFFFFFFFFFFFFFFFF);

    variant v1(arg);
    BOOST_CHECK(v1.is<variant::Int64>());
    BOOST_CHECK(v1.is<variant::Integer>());
    BOOST_CHECK(v1.is<variant::Number>());
    BOOST_CHECK(v1.is<variant::Primitive>());
    BOOST_CHECK_EQUAL(v1.as<boost::int64_t>(), arg);
    
    variant v2;
    v2 = arg;
    BOOST_CHECK_EQUAL(v2.as<boost::int64_t>(), arg);

    variant v3(v2);
    BOOST_CHECK_EQUAL(v3.as<boost::int64_t>(), arg);

    variant v4;
    v4 = v3;
    BOOST_CHECK_EQUAL(v3.as<boost::int64_t>(), arg);

    variant v5(variant::Int64);
    BOOST_CHECK(v5.is<variant::Int64>());
    BOOST_CHECK_EQUAL(v5.as<boost::int64_t>(), 0);

    BOOST_CHECK_THROW(v1.as<boost::uint64_t>(), variant_error);
}

void test_UInt64()
{
    boost::uint64_t arg(0xFFFFFFFFFFFFFFFF);

    variant v1(arg);
    BOOST_CHECK(v1.is<variant::UInt64>());
    BOOST_CHECK(v1.is<variant::Integer>());
    BOOST_CHECK(v1.is<variant::Number>());
    BOOST_CHECK(v1.is<variant::Primitive>());
    BOOST_CHECK_EQUAL(v1.as<boost::uint64_t>(), arg);
    
    variant v2;
    v2 = arg;
    BOOST_CHECK_EQUAL(v2.as<boost::uint64_t>(), arg);

    variant v3(v2);
    BOOST_CHECK_EQUAL(v3.as<boost::uint64_t>(), arg);

    variant v4;
    v4 = v3;
    BOOST_CHECK_EQUAL(v3.as<boost::uint64_t>(), arg);

    variant v5(variant::UInt64);
    BOOST_CHECK(v5.is<variant::UInt64>());
    BOOST_CHECK_EQUAL(v5.as<boost::uint64_t>(), 0);

    BOOST_CHECK_THROW(v1.as<boost::int64_t>(), variant_error);
}

void test_Float()
{
    float arg(std::numeric_limits<float>::max());

    variant v1(arg);
    BOOST_CHECK(v1.is<variant::Float>());
    BOOST_CHECK(!v1.is<variant::Integer>());
    BOOST_CHECK(v1.is<variant::Number>());
    BOOST_CHECK(v1.is<variant::Primitive>());
    BOOST_CHECK_EQUAL(v1.as<float>(), arg);
    
    variant v2;
    v2 = arg;
    BOOST_CHECK_EQUAL(v2.as<float>(), arg);

    variant v3(v2);
    BOOST_CHECK_EQUAL(v3.as<float>(), arg);

    variant v4;
    v4 = v3;
    BOOST_CHECK_EQUAL(v3.as<float>(), arg);

    variant v5(variant::Float);
    BOOST_CHECK(v5.is<variant::Float>());
    BOOST_CHECK_EQUAL(v5.as<float>(), 0.);
}

void test_Double()
{
    double arg(std::numeric_limits<double>::max());

    variant v1(arg);
    BOOST_CHECK(v1.is<variant::Double>());
    BOOST_CHECK(!v1.is<variant::Integer>());
    BOOST_CHECK(v1.is<variant::Number>());
    BOOST_CHECK(v1.is<variant::Primitive>());
    BOOST_CHECK_EQUAL(v1.as<double>(), arg);
    
    variant v2;
    v2 = arg;
    BOOST_CHECK_EQUAL(v2.as<double>(), arg);

    variant v3(v2);
    BOOST_CHECK_EQUAL(v3.as<double>(), arg);

    variant v4;
    v4 = v3;
    BOOST_CHECK_EQUAL(v3.as<double>(), arg);

    variant v5(variant::Double);
    BOOST_CHECK(v5.is<variant::Double>());
    BOOST_CHECK_EQUAL(v5.as<double>(), 0.);
}

void test_Boolean()
{
    bool arg(true);

    variant v1(arg);
    BOOST_CHECK(v1.is<variant::Boolean>());
    BOOST_CHECK(!v1.is<variant::Integer>());
    BOOST_CHECK(v1.is<variant::Number>());
    BOOST_CHECK(v1.is<variant::Primitive>());
    BOOST_CHECK_EQUAL(v1.as<bool>(), arg);
    
    variant v2;
    v2 = arg;
    BOOST_CHECK_EQUAL(v2.as<bool>(), arg);

    variant v3(v2);
    BOOST_CHECK_EQUAL(v3.as<bool>(), arg);

    variant v4;
    v4 = v3;
    BOOST_CHECK_EQUAL(v3.as<bool>(), arg);

    variant v5(variant::Boolean);
    BOOST_CHECK(v5.is<variant::Boolean>());
    BOOST_CHECK_EQUAL(v5.as<bool>(), false);
}

test_suite* init_unit_test_suite(int, char* []) 
{
    test_suite* test = BOOST_TEST_SUITE("number types");
    test->add(BOOST_TEST_CASE(&test_Int32));
    test->add(BOOST_TEST_CASE(&test_UInt32));
    test->add(BOOST_TEST_CASE(&test_Int64));
    test->add(BOOST_TEST_CASE(&test_UInt64));
    test->add(BOOST_TEST_CASE(&test_Float));
    test->add(BOOST_TEST_CASE(&test_Double));
    test->add(BOOST_TEST_CASE(&test_Boolean));

    return test;
}