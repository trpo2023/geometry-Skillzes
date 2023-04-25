#include <ctype.h>
#include <stdlib.h>

#include <libgeometry/error.h>
#include <libgeometry/parser.h>
#include <libgeometry/lexer.h>

double search_num(char* arr, int* num, char ch)
{
    char* exp = malloc(20 * sizeof(char));
    int i = 0;
    while (isdigit(arr[*num]) || arr[*num] == '-' || arr[*num] == '.') {
        if (arr[*num] == '.' && arr[*num + 1] == '.') {
            show_bugs(BUG_NUMBER, *num + 1, NULL);
            exit(1);
        }
        exp[i] = arr[*num];
        i++;
        *num += 1;
    }
    if (arr[*num] != ' ' && arr[*num] != ch && isdigit(arr[*num - 1])
        && isdigit(arr[*num + 1])) {
        show_bugs(BUG_EXTRA_POINT, *num, NULL);
        exit(1);
    }
    char* dumpster;
    double Number = strtod(exp, &dumpster);
    free(exp);
    return Number;
}
