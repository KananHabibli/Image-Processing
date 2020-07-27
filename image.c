#include "image.h"

void I_print(struct color img[] , int nb_pixels){
	for (int i = 0; i < nb_pixels; ++i)
		{
			C_print(img[i]);
		}	
}

void I_coef(struct color img[] , int nb_pixels, float coef){
	for (int i = 0; i < nb_pixels; ++i)
	{
		img[i] = C_multiply(img[i],coef);
		// C_print(img[i]);
	}
}


void I_negative(struct color img[] , int nb_pixels){
	for (int i = 0; i < nb_pixels; ++i)
	{
		img[i] = C_negative(img[i]);
		// C_print(img[i]);
	}
}



void I_permute(struct color img[] , int nb_pixels){
	for (int i = 0; i < nb_pixels; ++i)
	{
		img[i] = C_permute(img[i]);
        // C_print(img[i]);

	}
}


void I_grayScale(struct color img[] , int nb_pixels){
	for (int i = 0; i < nb_pixels; ++i)
	{
		img[i] = C_grayScale(img[i]);
		// C_print(img[i]);
	}
}


void I_threshold(struct color img[] , int nb_pixels, int th){
	for (int i = 0; i < nb_pixels; ++i)
	{
		printf("%d\n", C_threshold(img[i],th));
	}
}

void I_compose(struct color img1[], struct color img2[], int nb_pixels,
struct color target){
	for (int i = 0; i < nb_pixels; ++i)
	{
		if(C_areEqual(img1[i],target) == 1){
			img2[i].red = target.red;
			img2[i].green = target.green;
			img2[i].blue = target.blue;
		}
	}
}

void I_addColor(struct color img[], int nb_pixels, struct color c){
	for (int i = 0; i < nb_pixels; ++i)
	{
		img[i].red += c.red;
		img[i].blue += c.blue;
		img[i].green += c.green;
	}
}

void I_gradient(struct color img_in[], struct color img_out[], int nb_pixels){
	img_out[0] = C_new(127,127,127);
	for (int i = 1; i < nb_pixels; ++i)
	{
		img_out[i].red = clamp(img_in[i].red - img_in[i-1].red + 127);
		img_out[i].green = clamp(img_in[i].green - img_in[i-1].green + 127);
		img_out[i].blue = clamp(img_in[i].blue - img_in[i-1].blue + 127);
	}
}

void I_gradient1(struct color img_in[], struct color img_out[], int nb_pixels){
	img_out[0] = C_new(255,255,255);
	for (int i = 1; i < nb_pixels; ++i)
	{
		img_out[i].red = clamp(img_in[i].red - img_in[i-1].red + 127);
		img_out[i].green = clamp(img_in[i].green - img_in[i-1].green + 127);
		img_out[i].blue = clamp(img_in[i].blue - img_in[i-1].blue + 127);
	}
}

struct color I_average(struct color img[], int nb_pixels, int fromhere,
int nb_pixels_average){
	struct color sum;
	sum.red = 0;
	sum.green = 0;
	sum.blue = 0;
	if(fromhere+nb_pixels_average >= nb_pixels){
		nb_pixels_average = nb_pixels - fromhere -1;
	}
	for (int i = fromhere; i < fromhere+nb_pixels_average; ++i)
	{
		sum.red += img[i].red;
		sum.green += img[i].green;
		sum.blue += img[i].blue ;
	
	}
	sum.red = clamp(sum.red);
	sum.green = clamp(sum.green);
	sum.blue = clamp(sum.blue);
	return sum;
	
}

void I_motionBlur(struct color img[], struct color img_out[],
int nb_pixels, int strength){
	for (int i = 0; i < nb_pixels; ++i)
	{	
		img_out[i] = I_average(img, nb_pixels,i,strength);
	}
}