#pragma once
#define BLUE "\e[1;36m"
#define END "\e[0m"

enum BUGS {
    BUG_NAME,
    BUG_STAPLES,
    BUG_STAPLES_2,
    BUG_NUMBER,
    BUG_UNIDENTIFIED_VARIABLES,
    BUG_EXPECT_COMMA,
    BUG_EXTRA_POINT
};

void show_bugs(int error, int num, char* ch);
