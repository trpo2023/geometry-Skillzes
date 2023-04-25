#pragma once

#include <stdbool.h>

struct circle;
double perimeter_circle(struct circle* Circle);
double area_circle(struct circle* Circle);
struct circle shape_characteristics(struct circle* Circle);
bool intersection(struct circle* first, struct circle* second);
