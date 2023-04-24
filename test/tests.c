#include <ctest.h>
#include <string.h>

#include <libgeometry/data_x.h>
#include <libgeometry/data_y.h>
#include <libgeometry/radius_data.h>
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

CTEST(parser, empty)
{
    char string_1[] = "circle(   10  1, 20)";
    int num = 7;
    empty(string_1, &num, '0');
    int expected = 10;
    int result = num;
    ASSERT_EQUAL(expected, result);

    char string_2[] = "circle(123.432 3123.        , 10.95)";
    num = 20;
    empty(string_2, &num, ',');
    expected = 28;
    result = num;
    ASSERT_EQUAL(expected, result);

    char string_3[] = "circle(1 1,1              )";
    num = 12;
    empty(string_3, &num, ')');
    expected = 26;
    result = num;
    ASSERT_EQUAL(expected, result);
}

CTEST(data_x, x_data)
{
    int num = 8;
    char string[] = "circle( 10.5  -2.3674, 20. )\0";
    double tol = 1e-4;
    double result_x = data_x(string, &num, ' ');
    double expect_x = 10.50;
    ASSERT_DBL_NEAR_TOL(expect_x, result_x, tol);
}

CTEST(data_y, y_data)
{
    int num = 14;
    char string[] = "circle( 10.5  -2.3674, 20. )\0";
    double tol = 1e-4;
    double result_y = data_y(string, &num, ',');
    double expect_y = -2.3674;
    ASSERT_DBL_NEAR_TOL(expect_y, result_y, tol);
}

CTEST(radius_data, radius_data)
{
    int num = 23;
    char string[] = "circle( 10.5  -2.3674, 20. )\0";
    double tol = 1e-4;
    double result_radius = radius_data(string, &num, ')');
    double expect_radius = 20.00;
    ASSERT_DBL_NEAR_TOL(expect_radius, result_radius, tol);
}
