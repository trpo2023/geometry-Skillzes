#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/calculator.h>
#include <libgeometry/error.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

void to_lower(char* str, int ch)
{
    for (int i = 0; i < ch; i++) {
        str[i] = tolower(str[i]);
    }
}

void first_character(char* str, char ch)
{
    char exp[MAX];
    for (int j = 0; j < strlen(exp); j++) {
        exp[j] = '\0';
    }
    exp[0] = ch;
    for (int j = 0; j < strlen(exp); j++) {
        exp[j + 1] = str[j];
    }
    for (int j = 0; j < strlen(exp); j++) {
        str[j] = exp[j];
    }
}

void skip_space(char* arr, int* num, char ch)
{
    while (arr[*num] != ch) {
        if (arr[*num] == ' ') {
            *num += 1;
        } else if (
                (ch == '0')
                && (isdigit(arr[*num]) || arr[*num] == '-'
                    || arr[*num] == '.')) {
            break;
        } else if (ch == ',') {
            show_bugs(BUG_EXPECT_COMMA, *num, NULL);
            exit(1);
        } else if (ch == ')') {
            show_bugs(BUG_STAPLES, *num, &arr[*num]);
            exit(1);
        } else if (ch == '\n') {
            show_bugs(BUG_UNIDENTIFIED_VARIABLES, *num, NULL);
            exit(1);
        } else {
            show_bugs(BUG_UNIDENTIFIED_VARIABLES, *num, NULL);
            exit(1);
        }
    }
}

struct circle find_center(char* arr, int* num)
{
    struct circle Center;

    *num += 1;
    skip_space(arr, num, '0');
    Center.center.x = search_num(arr, num, ' ');

    skip_space(arr, num, '0');
    Center.center.y = search_num(arr, num, ',');
    skip_space(arr, num, ',');
    *num += 1;

    skip_space(arr, num, '0');
    Center.radius = search_num(arr, num, ')');
    if (Center.radius <= 0) {
        show_bugs(BUG_INCORRECT_RADIUS, *num, NULL);
        exit(1);
    }
    skip_space(arr, num, ')');
    *num += 1;
    skip_space(arr, num, '\n');

    return Center;
}

void output_circle_message(struct circle* CIRCLE, char* form)
{
    printf("\n%s(%.2f %.2f, %.2f)\nPerimeter: %.2f\nArea: %.2f\n\n",
           form,
           CIRCLE->center.x,
           CIRCLE->center.y,
           CIRCLE->radius,
           CIRCLE->perimeter,
           CIRCLE->area);
}

void show_intersection(struct circle circles[NUM_OF_LAPS], int count)
{
    if ((count == NUM_OF_LAPS) && (intersection(&circles[0], &circles[1]))) {
        printf("These circles intersect\n");
    } else {
        printf("These circles don't intersect\n");
    }
}
