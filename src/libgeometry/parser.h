#pragma once

struct point {
    double x;
    double y;
};

struct circle {
    struct point center;
    double radius;
};

void to_lower(char* str, int ch);
void empty(char* arr, int* num);

struct point find_center(char* arr, int* num);
struct circle find_out_circle(struct point* Center, char* arr, int* num);

void output_circle_message(struct circle* CIRCLE);
