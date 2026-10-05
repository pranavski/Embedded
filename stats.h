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
 * @brief Declarations for statistics functions on an unsigned char data set
 *
 * This header declares functions that compute the maximum, minimum, mean,
 * and median of an array of unsigned char values, sort that array from
 * largest to smallest, and print the array and its statistics to the screen.
 * All statistics are rounded down to the nearest integer.
 *
 * @author Pranav Surampudi
 * @date 2026-10-05
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of a data array
 *
 * Computes and prints the minimum, maximum, mean, and median of the given
 * data array, with a label for each value. Computing the median sorts the
 * array in place (largest to smallest).
 *
 * @param data Pointer to an n-element unsigned char data array
 * @param length Number of elements in the array
 *
 * @return void
 */
void print_statistics(unsigned char * data, unsigned int length);

/**
 * @brief Prints a data array to the screen
 *
 * Prints every element of the array along with its index, several
 * elements per line.
 *
 * @param data Pointer to an n-element unsigned char data array
 * @param length Number of elements in the array
 *
 * @return void
 */
void print_array(unsigned char * data, unsigned int length);

/**
 * @brief Finds the median of a data array
 *
 * Sorts the array in place (largest to smallest) and returns the middle
 * value. For an even number of elements, returns the average of the two
 * middle values rounded down.
 *
 * @param data Pointer to an n-element unsigned char data array
 * @param length Number of elements in the array
 *
 * @return The median value, rounded down (0 if length is 0)
 */
unsigned char find_median(unsigned char * data, unsigned int length);

/**
 * @brief Finds the mean of a data array
 *
 * Sums all elements and divides by the number of elements. The result is
 * rounded down to the nearest integer.
 *
 * @param data Pointer to an n-element unsigned char data array
 * @param length Number of elements in the array
 *
 * @return The mean value, rounded down (0 if length is 0)
 */
unsigned char find_mean(unsigned char * data, unsigned int length);

/**
 * @brief Finds the maximum of a data array
 *
 * Scans every element and returns the largest value.
 *
 * @param data Pointer to an n-element unsigned char data array
 * @param length Number of elements in the array
 *
 * @return The maximum value (0 if length is 0)
 */
unsigned char find_maximum(unsigned char * data, unsigned int length);

/**
 * @brief Finds the minimum of a data array
 *
 * Scans every element and returns the smallest value.
 *
 * @param data Pointer to an n-element unsigned char data array
 * @param length Number of elements in the array
 *
 * @return The minimum value (0 if length is 0)
 */
unsigned char find_minimum(unsigned char * data, unsigned int length);

/**
 * @brief Sorts a data array from largest to smallest
 *
 * Sorts the array in place so that element 0 holds the largest value and
 * element n-1 holds the smallest value.
 *
 * @param data Pointer to an n-element unsigned char data array
 * @param length Number of elements in the array
 *
 * @return void
 */
void sort_array(unsigned char * data, unsigned int length);

#endif /* __STATS_H__ */
