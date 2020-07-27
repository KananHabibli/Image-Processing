#ifndef _COLOR_
#define _COLOR_

#include <stdio.h>
#include <stdlib.h>

struct color{
	int red , green , blue;
};

void C_print(struct color c);
int clamp(int n);
struct color C_new(int r, int g, int b);
struct color C_multiply(struct color c, float coef);
struct color C_negative(struct color c);
struct color C_permute(struct color c);
int C_intensity(struct color c);
struct color C_grayScale(struct color c);
int C_threshold(struct color c, int th);
int C_areEqual(struct color c1, struct color c2);
struct color C_addCoef(struct color c1, struct color c2, float coef);

#endif 