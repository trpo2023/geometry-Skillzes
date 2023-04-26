#pragma once

#define NUM_OF_LAPS 2
#define MAX 100

struct point {
    double x;
    double y;
};

struct circle {
    struct point center;
    double radius;
    double perimeter;
    double area;
};

void to_lower(char* str, int ch);
void first_character(char* str, char ch);
void skip_space(char* arr, int* num, char ch);

struct circle find_center(char* arr, int* num);

void output_circle_message(struct circle* CIRCLE, char* form);
void show_intersection(struct circle circles[NUM_OF_LAPS], int count);
