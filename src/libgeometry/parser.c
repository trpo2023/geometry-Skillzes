#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/data_x.h>
#include <libgeometry/data_y.h>
#include <libgeometry/error.h>
#include <libgeometry/parser.h>
#include <libgeometry/radius_data.h>

void to_lower(char* str, int ch)
{
    for (int i = 0; i < ch; i++) {
        str[i] = tolower(str[i]);
    }
}

void empty(char* arr, int* num)
{
    *num += 1;
    while (arr[*num] != '\n' && arr[*num] != EOF) {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            show_bugs(BUG_UNIDENTIFIED_VARIABLES, *num, NULL);
            exit(1);
        }
    }
}

struct point find_center(char* arr, int* num)
{
    struct point Center;

    Center.x = x_data(arr, num);
    Center.y = y_data(arr, num);

    return Center;
}

struct circle find_out_circle(struct point* Center, char* arr, int* num)
{
    struct circle CIRCLE;

    CIRCLE.center.x = Center->x;
    CIRCLE.center.y = Center->y;
    CIRCLE.radius = radius_data(arr, num);

    return CIRCLE;
}

void output_circle_message(struct circle* CIRCLE)
{
    printf("\ncircle(%.2f %.2f, %.2f)\n",
           CIRCLE->center.x,
           CIRCLE->center.y,
           CIRCLE->radius);
    printf("perimeter: %.4f\n", (2 * 3.1415926535 * CIRCLE->radius));
    printf("area: %.4f\n", ((CIRCLE->radius * CIRCLE->radius) * 3.1415926535));
}
