#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/calculator.h>
#include <libgeometry/error.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

int main()
{
    char ch;
    struct circle circles[NUM_OF_LAPS];
    int count = 0;
    while ((count < NUM_OF_LAPS)
           && printf("Enter a geometric figure (or press Q for exit):\n")
           && ((ch = getc(stdin)) != 'q')) {
        char enter[MAX], shape[MAX] = {};
        int num = 0;
        fgets(enter, MAX, stdin);
        first_character(enter, ch);
        for (int i = 0; i < strlen(enter); i++) {
            if (enter[i] == '(') {
                to_lower(shape, num);
                if (strcmp(shape, "circle") == 0) {
                    circles[count] = find_center(enter, &num);
                    shape_characteristics(&circles[count]);
                    output_circle_message(&circles[count++], shape);
                    break;
                } else {
                    show_bugs(BUG_NAME, 0, NULL);
                    exit(1);
                }
            } else if (enter[i] == ')' || enter[i] == ' ') {
                show_bugs(BUG_STAPLES, num, &enter[i]);
                exit(1);
            }
            shape[num] = enter[i];
            num++;
        }
    }
    show_intersection(circles, count);

    return 0;
}
