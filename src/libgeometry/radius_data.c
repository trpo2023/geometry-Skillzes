#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/error.h>
#include <libgeometry/radius_data.h>


double radius_data(char* arr, int* num)
{
    char free_space[20];
    int i = 0;
    int extra_point_count = 0;

    while (!isdigit(arr[*num])) {
        if (arr[*num] == ' ' || arr[*num] == ',') {
            *num += 1;
        } else {
            show_bugs(BUG_NUMBER, *num, NULL);
            exit(1);
        }
    }

    while (isdigit(arr[*num]) || arr[*num] == '.') {
        free_space[i] = arr[*num];
        i++;
        *num += 1;
        if (arr[*num] == '.') {
            extra_point_count += 1;
        }
        if (extra_point_count >= 2) {
            show_bugs(BUG_EXTRA_POINT, *num, &arr[*num]);
            exit(1);
        }
    }

    while (arr[*num] != ')') {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            if (arr[*num] == '(') {
                show_bugs(BUG_STAPLES, *num, &arr[*num]);
                exit(1);
            } else {
                show_bugs(BUG_STAPLES_2, *num, &arr[*num]);
                exit(1);
            }
        }
    }
    char* dumpster;
    return strtod(free_space, &dumpster);
}
