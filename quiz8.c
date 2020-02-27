#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
        int a, b, max;
        max = strlen(argv[0]);
        for (a=0; a<argc; a++)
                if (strlen(argv[a]) > max) max = strlen(argv[a]);
        for (a=0; a<max; a++) {
                for (b=0; b<argc; b++)
                        if ( a < strlen(argv[b]) )
                                printf("%c ", argv[b][a]);
                        else
                                printf("  ");
                printf("\n");
        }
        return 0;
}
