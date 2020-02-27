// My name is Nguyen Hung Nguyen and this my work for the project 5. The purpose of this project is to read an image under the ppm format, make changes to it and then print out a new image.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"

//////////////////////////////////////////////////////////////////////////////////////

ppmPic *readPic(char *fileName) {
	FILE *pic = fopen(fileName, "r");
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	char P3[5];
	fscanf(pic, "%s", P3);
	fscanf(pic, "%d", &myPic->cols);
	fscanf(pic, "%d", &myPic->rows);
	fscanf(pic, "%d", &myPic->colors);
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for (int i = 0; i < myPic->rows; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}
	for (int a = 0; a < myPic->rows; a++) {
		for (int b = 0; b < myPic->cols; b++) {
			fscanf(pic, "%d", &myPic->pixels[a][b].red);
			fscanf(pic, "%d", &myPic->pixels[a][b].green);
			fscanf(pic, "%d", &myPic->pixels[a][b].blue);
		}
	}
	fclose(pic);
	return myPic;
}

void writePic(ppmPic *myPic, char *fileName) {
	int x = strlen(fileName) - 4;
	fileName[x] = '\0';
	strcat(fileName, "-NEW.ppm");
	FILE *pic = fopen(fileName, "w");
	fprintf(pic, "P3 %d %d %d\n", myPic->cols, myPic->rows, myPic->colors);
	for (int a = 0; a < myPic->rows; a++) {
		for (int b = 0; b < myPic->cols; b++) {
			fprintf(pic, "%d ", myPic->pixels[a][b].red);
			fprintf(pic, "%d ", myPic->pixels[a][b].green);
			fprintf(pic, "%d ", myPic->pixels[a][b].blue);
		}
		fprintf(pic,"\n");
	}
	fclose(pic);
	return;
}

ppmPic *rotateLeft(ppmPic *thePic) {
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	myPic->cols = thePic->rows;
	myPic->rows = thePic->cols;
	myPic->colors = thePic->colors;
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for (int i = 0; i < myPic->rows; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}
	for (int a = 0; a < thePic->cols; a++) {
		for (int b = 0; b < thePic->rows; b++) {
			myPic->pixels[a][b].red = thePic->pixels[b][thePic->cols-a-1].red;
			myPic->pixels[a][b].green = thePic->pixels[b][thePic->cols-a-1].green;
			myPic->pixels[a][b].blue = thePic->pixels[b][thePic->cols-a-1].blue;
		}
	}
	return myPic;
}

ppmPic *rotateRight(ppmPic *thePic) {
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	myPic->cols = thePic->rows;
	myPic->rows = thePic->cols;
	myPic->colors = thePic->colors;
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for (int i = 0; i < myPic->rows; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}
	for (int a = 0; a < thePic->cols; a++) {
		for (int b = 0; b < thePic->rows; b++) {
			myPic->pixels[a][b] = thePic->pixels[thePic->rows-b-1][a];
		}
	}
	return myPic;
}

ppmPic *flipHorizontal(ppmPic *thePic) {
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	myPic->rows = thePic->rows;
	myPic->cols = thePic->cols;
	myPic->colors = thePic->colors;
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for (int i = 0; i < myPic->rows; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}
	for (int a = 0; a < thePic->rows; a++) {
		for (int b = 0; b < thePic->cols; b++) {
			myPic->pixels[a][b] = thePic->pixels[a][thePic->cols-b-1];
		}
	}
	return myPic;
}

ppmPic *flipVertical(ppmPic *thePic) {
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	myPic->rows = thePic->rows;
	myPic->cols = thePic->cols;
	myPic->colors = thePic->colors;
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for (int i = 0; i < myPic->rows; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}
	for (int a = 0; a < thePic->rows; a++) {
		for (int b = 0; b < thePic->cols; b++) {
			myPic->pixels[a][b] = thePic->pixels[thePic->rows-a-1][b];
		}
	}
	return myPic;
}

ppmPic *invert(ppmPic *thePic) {
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	myPic->rows = thePic->rows;
	myPic->cols = thePic->cols;
	myPic->colors = thePic->colors;
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for (int i = 0; i < myPic->rows; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}

	for (int a = 0; a < thePic->rows; a++) {
		for (int b = 0; b < thePic->cols; b++) {
			myPic->pixels[a][b].red = 255 - thePic->pixels[a][b].red;
			myPic->pixels[a][b].green = 255 - thePic->pixels[a][b].green;
			myPic->pixels[a][b].blue = 255 - thePic->pixels[a][b].blue;
		}
	}
	return myPic;
}

ppmPic *duplicate(ppmPic *thePic) {
	ppmPic *myPic = malloc ( sizeof (ppmPic) );
	myPic->rows = thePic->rows;
	myPic->cols = thePic->cols;
	myPic->colors = thePic->colors;
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for (int i = 0; i < myPic->rows; i++) {
		myPic->pixels[i] = malloc(sizeof(Pixel) * myPic->cols);
	}
	myPic = thePic;
	return myPic;
}
