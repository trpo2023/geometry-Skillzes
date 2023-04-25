#include <ctest.h>
#include <string.h>

#include <libgeometry/calculator.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

CTEST(parser, to_lower)
{
    char string_1[] = "Circle";
    char string_2[] = "CiRcLe";
    char string_3[] = "CIRCLE";
    const char expected[] = "circle";

    int len_str_1 = strlen(string_1);
    int len_str_2 = strlen(string_2);
    int len_str_3 = strlen(string_3);

    to_lower(string_1, len_str_1);
    to_lower(string_2, len_str_2);
    to_lower(string_3, len_str_3);

    ASSERT_STR(string_1, expected);
    ASSERT_STR(string_2, expected);
    ASSERT_STR(string_3, expected);
}

CTEST(parser, skip_space)
{
    char string_1[] = "circle(   10  1, 20)";
    int num = 7;
    skip_space(string_1, &num, '0');
    int expected = 10;
    int result = num;
    ASSERT_EQUAL(expected, result);

    char string_2[] = "circle(123.432 3123.        , 10.95)";
    num = 20;
    skip_space(string_2, &num, ',');
    expected = 28;
    result = num;
    ASSERT_EQUAL(expected, result);

    char string_3[] = "circle(1 1,1              )";
    num = 12;
    skip_space(string_3, &num, ')');
    expected = 26;
    result = num;
    ASSERT_EQUAL(expected, result);
}

CTEST(lexer, search_num)
{
    int num = 8;
    char string[] = "circle( 10.5  -2.3674, 20. )\0";
    double tol = 1e-4;
    double result_x = search_num(string, &num, ' ');
    double expect_x = 10.50;
    ASSERT_DBL_NEAR_TOL(expect_x, result_x, tol);

    num = 14;
    double result_y = search_num(string, &num, ',');
    double expect_y = -2.3674;
    ASSERT_DBL_NEAR_TOL(expect_y, result_y, tol);

    num = 23;
    double result_radius = search_num(string, &num, ')');
    double expect_radius = 20.00;
    ASSERT_DBL_NEAR_TOL(expect_radius, result_radius, tol);
}

CTEST(calculate, perimeter_circle)
{
    struct circle Circle;
    double tol = 1e-4;

    Circle.radius = 1;
    double expect = 6.2831853;
    double result = perimeter_circle(&Circle);
    ASSERT_DBL_NEAR_TOL(expect, result, tol);

    Circle.radius = 2.75;
    expect = 17.27876;
    result = perimeter_circle(&Circle);
    ASSERT_DBL_NEAR_TOL(expect, result, tol);

    Circle.radius = 10.21;
    expect = 64.151322;
    result = perimeter_circle(&Circle);
    ASSERT_DBL_NEAR_TOL(expect, result, tol);
}

CTEST(calculate, area_circle)
{
    struct circle Circle;
    double tol = 1e-4;

    Circle.radius = 1;
    double expect = 3.1415927;
    double result = area_circle(&Circle);
    ASSERT_DBL_NEAR_TOL(expect, result, tol);

    Circle.radius = 2.75;
    expect = 23.758294;
    result = area_circle(&Circle);
    ASSERT_DBL_NEAR_TOL(expect, result, tol);

    Circle.radius = 10.21;
    expect = 327.4925;
    result = area_circle(&Circle);
    ASSERT_DBL_NEAR_TOL(expect, result, tol);
}

CTEST(parser, intersection)
{
    struct circle Circle_1;
    Circle_1.center.x = 1;
    Circle_1.center.y = 1;
    Circle_1.radius = 1;

    struct circle Circle_2;
    Circle_2.center.x = 2.5;
    Circle_2.center.y = 0;
    Circle_2.radius = 1;

    bool expected = true;
    bool result = intersection(&Circle_1, &Circle_2);
    ASSERT_EQUAL(expected, result);

    Circle_1.center.x = 1;
    Circle_1.center.y = 3;
    Circle_1.radius = 2;

    expected = false;
    result = intersection(&Circle_1, &Circle_2);
    ASSERT_EQUAL(expected, result);
}
