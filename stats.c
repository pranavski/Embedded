/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Statistics analysis of an unsigned char data set
 *
 * Analyzes a 40-element array of unsigned char data and reports its
 * maximum, minimum, mean, and median, rounded down to the nearest integer.
 * The array is also sorted from largest to smallest and printed to the
 * screen.
 *
 * @author Pranav Surampudi
 * @date 2026-10-05
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("Original data set:\n");
  print_array(test, SIZE);

  print_statistics(test, SIZE);

  sort_array(test, SIZE);
  printf("\nSorted data set (largest to smallest):\n");
  print_array(test, SIZE);

  return 0;
}

void print_statistics(unsigned char * data, unsigned int length) {
  if (data == NULL || length == 0) {
    printf("No data to analyze.\n");
    return;
  }

  printf("\nStatistics (%u elements):\n", length);
  printf("  Minimum: %3u\n", find_minimum(data, length));
  printf("  Maximum: %3u\n", find_maximum(data, length));
  printf("  Mean:    %3u\n", find_mean(data, length));
  printf("  Median:  %3u\n", find_median(data, length));
}

void print_array(unsigned char * data, unsigned int length) {
  unsigned int i;

  if (data == NULL || length == 0) {
    printf("  (empty)\n");
    return;
  }

  for (i = 0; i < length; i++) {
    printf("  [%2u] = %3u", i, data[i]);
    if ((i + 1) % 8 == 0 || i == length - 1) {
      printf("\n");
    }
  }
}

unsigned char find_median(unsigned char * data, unsigned int length) {
  if (data == NULL || length == 0) {
    return 0;
  }

  sort_array(data, length);

  if (length % 2 == 0) {
    /* Average of the two middle values, rounded down */
    return (unsigned char)(((unsigned int)data[length / 2 - 1] +
                            data[length / 2]) / 2);
  }
  return data[length / 2];
}

unsigned char find_mean(unsigned char * data, unsigned int length) {
  unsigned long sum = 0;
  unsigned int i;

  if (data == NULL || length == 0) {
    return 0;
  }

  for (i = 0; i < length; i++) {
    sum += data[i];
  }
  /* Integer division rounds down */
  return (unsigned char)(sum / length);
}

unsigned char find_maximum(unsigned char * data, unsigned int length) {
  unsigned char max;
  unsigned int i;

  if (data == NULL || length == 0) {
    return 0;
  }

  max = data[0];
  for (i = 1; i < length; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char * data, unsigned int length) {
  unsigned char min;
  unsigned int i;

  if (data == NULL || length == 0) {
    return 0;
  }

  min = data[0];
  for (i = 1; i < length; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }
  return min;
}

void sort_array(unsigned char * data, unsigned int length) {
  unsigned int i;
  unsigned int j;
  unsigned char temp;

  if (data == NULL || length < 2) {
    return;
  }

  /* Insertion sort, largest to smallest */
  for (i = 1; i < length; i++) {
    temp = data[i];
    j = i;
    while (j > 0 && data[j - 1] < temp) {
      data[j] = data[j - 1];
      j--;
    }
    data[j] = temp;
  }
}
