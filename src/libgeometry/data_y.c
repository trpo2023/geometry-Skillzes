#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/data_y.h>
#include <libgeometry/error.h>

double y_data(char* arr, int* num)
{
    char free_space[20];
    int i = 0;

    while (!isdigit(arr[*num]) && arr[*num] != '-') {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            show_bugs(BUG_NUMBER, *num, NULL);
            exit(1);
        }
    }

    while (isdigit(arr[*num]) || arr[*num] == '-' || arr[*num] == '.') {
        free_space[i] = arr[*num];
        i++;
        *num += 1;
    }

    while (arr[*num] != ',') {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            show_bugs(BUG_EXPECT_COMMA, *num, NULL);
            exit(1);
        }
    }
    char* dumpster;
    return strtod(free_space, &dumpster);
}
