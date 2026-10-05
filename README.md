# Surampudi_Coursera

**Author:** Pranav Surampudi

## Description

Repository for the Coursera course *Introduction to Embedded Systems Software
and Development Environments* (University of Colorado Boulder), Module 1
assessment (C1M1).

The project is a small C program (`stats.c` / `stats.h`) that analyzes an
array of `unsigned char` data. It reports the maximum, minimum, mean, and
median of the data set, sorts it from largest to smallest, and prints the
results to the screen. All statistics are rounded down to the nearest integer.

## Files

- `stats.c` - Implementation file with `main()` and the statistics functions
- `stats.h` - Header file with function declarations and documentation
- `README.md` - This file

## Build and Run

```
gcc -o stats stats.c
./stats
```
