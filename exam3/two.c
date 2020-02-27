#include <stdio.h>
#include <stdlib.h>

typedef struct pixel {
    int red, green, blue;
} Pixel;

typedef struct ppm {
    int rows, cols, colors;
    Pixel **pixels;
} ppmPic;

void writeGrayScale(ppmPic *, char *);

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  ppmPic *pic = malloc(sizeof(ppmPic));
  char str[10];
  fscanf(fp, "%s", str);
  fscanf(fp, "%d %d", &pic->cols, &pic->rows);
  fscanf(fp, "%d", &pic->colors);
  pic->pixels = malloc(sizeof(Pixel *) * pic->rows);
  for (int i=0; i<pic->rows; i++)
      pic->pixels[i] = malloc(sizeof(Pixel) * pic->cols);
  for (int i = 0; i < pic->rows; i++) {
      for (int j=0; j < pic->cols; j++) {
          fscanf(fp, "%d", &pic->pixels[i][j].red);
          fscanf(fp, "%d", &pic->pixels[i][j].green);
          fscanf(fp, "%d", &pic->pixels[i][j].blue);
      }
  }
  fclose(fp);
  writeGrayScale(pic, argv[2]);
  return 0;
}

void writeGrayScale(ppmPic *myPic, char *fileName) {
  FILE *pic = fopen(fileName, "w");
  fprintf(pic, "P2\n%d %d %d\n", myPic->cols, myPic->rows, myPic->colors);
  int grayscale = 0;
  for (int a = 0; a < myPic->rows; a++) {
    for (int b = 0; b < myPic->cols; b++) {
      grayscale = 0.3*myPic->pixels[a][b].red + 0.59*myPic->pixels[a][b].green + 0.11 * myPic->pixels[a][b].blue;
      fprintf(pic, "%d ", grayscale);
    }
    fprintf(pic,"\n");
  }
  fclose(pic);
  return;
}
