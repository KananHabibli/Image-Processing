#include "color.h"


void C_print(struct color c){
	printf("(%d,%d,%d)\n", c.red , c.green , c.blue);
}

int clamp(int n){
	if(n < 0) return 0;
	if(n > 255) return 255;
	return n;

}

struct color C_new(int r, int g, int b){
	struct color c;
	c.red = clamp(r);
	c.blue = clamp(b);
	c.green = clamp(g);
	return c;
}


struct color C_multiply(struct color c, float coef){
	if(coef <= 0) exit(1);
	c.red = clamp(c.red * coef);
	c.blue = clamp(c.blue * coef);
	c.green = clamp(c.green * coef);
	return c;
}

struct color C_negative(struct color c){
	c.red = clamp(255 - c.red);
	c.blue = clamp(255 - c.blue);
	c.green = clamp(255 - c.green);
	return c;
}


struct color C_permute(struct color c){
	struct color new;
	new.red = c.green;
	new.green = c.blue;
	new.blue = c.red;
	return new;
}

int C_intensity(struct color c){
	return (c.red + c.blue + c.green)/3 ;
}

struct color C_grayScale(struct color c){
	int a = C_intensity(c);
	struct color gray = C_new(a,a,a);
	return gray;
}

int C_threshold(struct color c, int th){
	if(C_intensity(c) > th){
		return 255;
	}
	return 0;
}

int C_areEqual(struct color c1, struct color c2){
	if(c1.red == c2.red && c1.blue == c2.blue && c1.green == c2.green){
		return 1;
	}
	return 0;
}

struct color C_addCoef(struct color c1, struct color c2, float coef){
	c1.red   +=  c2.red*coef;
	c1.blue  +=  c2.blue*coef;
	c1.green +=  c2.green*coef;
	return c1;
}