#include <stdio.h>
#include <stdlib.h>

#include <libgeometry/error.h>

void show_bugs(int error, int num, char* ch)
{
    for (int i = 0; i < num; i++) {
        putchar(' ');
    }
    printf("^\n");

    switch (error) {
    case BUG_NAME:
        printf("An error %d was found in the input line %s'circle'%s\n",
               num,
               BLUE,
               END);
        break;
    case BUG_STAPLES:
        if (*ch == ')') {
            printf("An error %d was found in the input line %s')'%s\n",
                   num,
                   BLUE,
                   END);
            break;
        } else {
            printf("An error %d was found in the input line %s'('%s\n",
                   num,
                   BLUE,
                   END);
            break;
        }
   case BUG_STAPLES_2:
        printf("An error %d was found in the input line %s'double'%s\n",
               num,
               BLUE,
               END);
        break;
    case BUG_NUMBER:
        printf("An error %d was found in the input line %s'double'%s\n",
               num,
               BLUE,
               END);
        break;
    case BUG_UNIDENTIFIED_VARIABLES:
        printf("An error %d was found in the input line %s'variable'%s\n",
               num,
               BLUE,
               END);
        break;
    case BUG_EXPECT_COMMA:
        printf("An error %d was found in the input line %s','%s\n",
               num,
               BLUE,
               END);
        break;
    case BUG_EXTRA_POINT:
        printf("An error %d was found in the input line %s','%s\n",
               num,
               BLUE,
               END);
        break;
    }
}
