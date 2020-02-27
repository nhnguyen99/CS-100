#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct info {
        double lat;
        double lon;
        int temp;
} Info;

typedef struct dataset {
        int month;
        int day;
        int year;
        int observations;
        Info *data;     // pointer to an array of "Info" items
} Dataset;

Dataset *readData();
int findMaxTemp(Dataset *);
void printData(Dataset *);

int main(void) {
        Dataset *d1;
        d1 = readData();
        printData(d1);
        int max = findMaxTemp(d1);
        printf("The maximum temp is %d\n", max);
        return 0;
}

Dataset *readData(void) {
        Dataset *myData;
        myData = malloc( sizeof(Dataset) );
        printf("Enter basic dataset information:\n");
        printf("\tMonth : ");
        scanf("%d", &myData->month);
        printf("\tDay : ");
        scanf("%d", &myData->day);
        printf("\tYear : ");
        scanf("%d", &myData->year);
        printf("\tNumber of observations : ");
        scanf("%d", &myData->observations);
        myData->data = malloc( sizeof(Info) * myData->observations );
        int a;
        for (a=0; a<myData->observations; a++) {
                printf("Enter latitude for observation %d\n", a);
                scanf("%lf", &myData->data[a].lat);
                printf("Enter longitude for observation %d\n", a);
                scanf("%lf", &myData->data[a].lon);
                printf("Enter temperature for observation %d\n", a);
                scanf("%d", &myData->data[a].temp);
        }
        return myData;
}

int findMaxTemp( Dataset *d ) {
        int a;
        int max = d->data[0].temp;
        for (a=1; a<d->observations; a++)
                if ( d->data[a].temp > max )
                        max = d->data[a].temp;
        return max;
}

void printData( Dataset *d ) {
        printf("This dataset is from %d/%d/%d has %d observations\n",
                d->month, d->day, d->year, d->observations);
        int a;
        printf("The observations are :\n");
        for (a=0; a < d->observations; a++)
                printf("\tLat: %lf Long: %lf Temp: %d\n",
                        d->data[a].lat, d->data[a].lon, d->data[a].temp);
        return;
}
