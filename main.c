#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stats_lib.h"
#define MAX_DATA 200

int main()
{
    int i=0;
    FILE* fdata;
    float data[MAX_DATA];
    fdata=fopen("data.txt","r");
    if (fdata == NULL) {
        printf("File not found");
    }

    while (fscanf(fdata,"%f",&data[i])!=EOF){
        i++;
    }

    printf("Maximum: %f\n", maximum(data,i));
    printf("Minimum: %f\n", minimum(data,i));
    printf("Mean: %f\n", mean(data,i));
    printf("Median: %f\n", median(data,i));
    printf("Variance: %f\n", variance(data,i));
    printf("Standard Deviation: %f\n", standard_deviation(data,i));

    return 0;
}
