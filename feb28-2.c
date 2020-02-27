#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[ ] ) {
	if (argc != 3) {
		printf("Usage: ./a.out file1 file2\n");
		return 0;
	}
	FILE *in = fopen( argv[1], "r");
	if ( in == NULL ) {
		printf("Input file %s does not exist\n", argv[1]);
		return 0;
	}
	FILE *out = fopen( argv[2], "w");

	char ch;
	fscanf( in, "%c", &ch );
	while ( ! feof( in ) ) {
		fprintf( out, "%c", ch );
		fscanf( in, "%c", &ch );
	}
	fclose(in);
	fclose(out);
	return 0;
}
