#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/data_x.h>
#include <libgeometry/data_y.h>
#include <libgeometry/error.h>
#include <libgeometry/parser.h>
#include <libgeometry/radius_data.h>

#define BLUE "\e[1;36m"
#define END "\e[0m"
#define MAX 100

int main()
{
    char enter[MAX], shape[MAX];
    int num = 0;

    printf("Enter the name and coordinates of the shape (or press Enter for "
           "exit):\n");
    fgets(enter, MAX, stdin);

    for (int i = 0; i < strlen(enter); i++) {
        if (enter[i] == '(' || enter[i] == ' ') {
            to_lower(shape, num);
            if (strcmp(shape, "circle") == 0) {
                struct point Center = find_center(enter, &num);
                struct circle CIRCLE = find_out_circle(&Center, enter, &num);
                empty(enter, &num);
                output_circle_message(&CIRCLE);
                break;
            } else {
                show_bugs(BUG_NAME, 0, NULL);
                exit(1);
            }
        } else if (enter[i] == ')') {
            show_bugs(BUG_STAPLES, num, &enter[i]);
            exit(1);
        }

        shape[num] = enter[i];
        num++;
    }

    return 0;
}
