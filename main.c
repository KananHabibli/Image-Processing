#include "color.h"
#include "image.h"
#include "ppm.h"




void main(){
	struct ppm p = PPM_new("merida.ppm");
	int nbpixels = PPM_nbPixels(p);
	struct color *img = PPM_pixels(p);

	// struct ppm p1 = PPM_new("merida.ppm");
	// int nbpixels1 = PPM_nbPixels(p1);
	// struct color *img1 = PPM_pixels(p);
	// I_gradient1(img, img, nbpixels);
	// I_addColor(img, nbpixels, C_new(127,127,127));
	// I_compose(img, img1, nbpixels,C_new(0,111,92));
	I_motionBlur(img,img, nbpixels, 3);
	PPM_save(p,img,"motionblur.ppm");

	struct color c = I_average(img, nbpixels, 1000000,5);
	C_print(c);



	
}


// struct color c1 = C_new(10,50,200);
// struct color c2 = C_new(20,50,200);
// struct color c3 = C_new(10,50,200);
// int a = C_areEqual(c1,c2);
// printf("%d\n", a);
// // a is 0
// int b = C_areEqual(c1,c3);
// printf("%d\n", b);
// // b is 1




	// struct ppm p = PPM_new("merida.ppm");
	// int nbpixels = PPM_nbPixels(p);
	// struct color *img = PPM_pixels(p);
	// // I_coef(img , nbpixels, 2);
	// // I_negative(img , nbpixels);
	// // I_permute(img , nbpixels);
	// I_grayScale(img , nbpixels);
	// PPM_save(p,img,"res_grayScale.ppm");









//  struct color img[8];
// 	img[0] = C_new(0,0,0); // black
// 	img[1] = C_new(255,0,0); // red
// 	img[2] = C_new(0,255,0); // green
// 	img[3] = C_new(0,0,255); // blue
// 	img[4] = C_new(255,255,0); // yellow
// 	img[5] = C_new(255,0,255); // magenta
// 	img[6] = C_new(0,255,255); // cyan
// 	img[7] = C_new(255,255,255); // white
// 	I_print(img ,8);
// 	printf("----------------Multiply--------------------\n");
// 	I_coef(img , 8 , 5);
// 	printf("----------------Negative--------------------\n");
// 	I_negative(img , 8);
// 	printf("----------------Permute--------------------\n");
// 	I_permute(img , 8);
// 	printf("----------------GrayScale--------------------\n");
// 	I_grayScale(img , 8);
// 	printf("----------------Threshold--------------------\n");
// 	I_threshold(img , 8 , 85);







// struct color c;
// 	c.red = 255;
// 	c.blue = 168;
// 	c.green = 12;
// 	C_print(c);


// 	// struct color orange = C_new(255,100,0);
// 	// C_print(orange);

// 	struct color orange = C_new(300,12,50);
// 	C_print(orange);
// 	orange = C_multiply(orange,5.0);
// 	C_print(orange);
// 	orange = C_negative(orange);
// 	C_print(orange);
// 	orange = C_permute(orange);
// 	C_print(orange);
// 	int a = C_intensity(orange);
// 	printf("%d\n", a);
// 	struct color gray = C_grayScale(orange);
// 	C_print(gray);
// 	int b = C_threshold(orange,10);
// 	printf("%d\n", b);