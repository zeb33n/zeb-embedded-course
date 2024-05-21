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
 * @file stats.h
 * @brief various functios for comupting statistics on an array
 *
 * <Add Extended Description Here>
 *
 * @author zeb bond
 * @date 21/05/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdio.h>
#include <stdlib.h>
/* Add Your Declarations and Function Comments here */

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

void print_array(unsigned char array[]) {
  printf("[");
  while (*array != '\0') {
    printf("%u,", *array);
    array++;
  }
  printf("]\n");
}

int find_mean(int length, unsigned char array[]) {
  int sum = 0;
  while (*array != '\0') {
    sum += *array;
    array++;
  }
  return sum / length;
}

int find_maximum(unsigned char array[]) {
  int max = *array;
  while (*array != '\0') {
    if (*array > max) {
      max = *array;
    }
    array++;
  }
  return max;
}

int find_minimum(unsigned char array[]) {
  int min = *array;
  while (*array != '\0') {
    if (*array < min) {
      min = *array;
    }
    array++;
  }
  return min;
}

void pointer_swap(unsigned char *x, unsigned char *y) {
  int holder = *x;
  *x = *y;
  *y = holder;
}

int partition(unsigned char array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] >= pivot) {
      i++;
      pointer_swap(&array[i], &array[j]);
    }
  }
  pointer_swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quick_sort(unsigned char array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quick_sort(array, low, pi - 1);
    quick_sort(array, pi + 1, high);
  }
}

void sort_array(int length, unsigned char array[]) {
  quick_sort(array, 0, length - 1);
}

unsigned char find_median(int length, unsigned char array[]) {
  sort_array(length, array);
  if (length % 2 == 0) {
    return (array[length / 2 - 1] + array[length / 2]) / 2;
  }
  return array[length / 2 - 1];
}

extern void print_statistics(int length, unsigned char array[]) {
  printf("array: ");
  print_array(array);
  printf("mean: %u\n", find_mean(length, array));
  printf("median: %u\n", find_median(length, array));
  printf("maximum: %u\n", find_maximum(array));
  printf("minimum: %u\n", find_minimum(array));
  printf("array sorted: ");
  print_array(array);
}

#endif /* __STATS_H__ */
