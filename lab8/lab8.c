#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int, int);
void initMatrix(int **, int, int);
int findRange(int **, int, int);
double findAverage(int **, int, int);
void printCorners(int **, int, int);

int main(int argc, char *argv[]) {
	int **data;
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);

	data = allocateMatrix(row, col);
	initMatrix(data, row, col);
	printf("The range of values is %d\n", findRange(data, row, col) );
	printf("The average of all values is %lf\n", findAverage(data, row, col) );
	printCorners(data, row, col);

	return 0;
}

int **allocateMatrix(int r, int c) {
  int **matrix = malloc ( sizeof(int*)*r );
        for (int a=0; a<r; a++)
                matrix[a] = malloc ( sizeof(int) * c );
  // allocate a two-dimensional array of integers
	//	array has r rows and c columns
	//	do NOT initialize any of the values in the matrix
	//	return a pointer to this newly allocated matrix
	return matrix;
}

void initMatrix(int **array, int r, int c) {
	srand(0);
  for (int i=0; i < r; i++) {
    for (int j=0; j < c; j++) {
      array[i][j] = rand()%1000;
    }
  }
return;
  // initialize your random number generator with srand(0)
	// using a nested loop, put a value 0-999 in each element of the array, rand()%1000
}

int findRange(int **array, int r, int c) {
	int max = array[0][0];
  int min = array[0][0];
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      if (array[i][j] > max) max = array[i][j];
      if (array[i][j] < min) min = array[i][j];
    }
  }
  int range = max -min;
  // find the range of all values in the matrix
	//	find the maximum value and minimum values
	//	range is simply max - min
	return range;
}


double findAverage(int **array, int r, int c) {
  int sum =0, count = 0;
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
        sum = sum + array[i][j];
        count++;
    }
  }
  double average;
  average = (double)(sum)/count;// find the average of all values in the matrix
	return average;
}

void printCorners(int **array, int r, int c) {
    printf("%d ", array[0][0]);
    printf("%d\n", array[0][c-1]);
    printf("%d ", array[r-1][0]);
    printf("%d\n", array[r-1][c-1]);

  // print the four corners of the matrix
	//	print format
	//		upper-left upper-right
	//		lower-left lower-right
	// for a 1x1 matrix, print the single value four times
return;
}
