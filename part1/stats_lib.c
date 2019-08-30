#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stats_lib.h"


float maximum (float nums[],int n)
{
    float max = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > max)
            max = nums[i];
    }
    return max;
}

float minimum (float nums[],int n) {
    float min = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] < min)
            min = nums[i];
    }
    return min;
}

float mean (float nums[],int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        //printf("%f\n",sum);
    }

    return (sum / (float)n);
}

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort(float nums[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1])
                swap(&nums[j], &nums[j + 1]);
        }
    }
}

float median (float nums[],int n) {
    sort(nums, n);

    if (n % 2 == 0)
        return (nums[(n - 1) / 2] + nums[n / 2]) / 2.0;
    else
        return nums[n / 2];
}

float variance (float nums[],int n)
{
    float average = mean(nums, n);
    float var = 0;
    for (int i = 0; i < n; i++) {
        var += (nums[i] - average) * (nums[i] - average);
    }
    return var / (n - 1);
}

float standard_deviation (float nums[],int n)
{
    return sqrt((double)variance(nums, n));
}
