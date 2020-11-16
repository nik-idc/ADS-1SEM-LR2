#pragma once
#include <iostream>
#include <ctime>

#ifndef SORTINGS_H
#define SORTINGS_H

// Searches for target's index in an array by constantly splitting the array in half and comparing the middle element of the current search range to the target value
int binarySearch(long *arr, long target, long size);

// Swapping two values
void swap(long &el_1, long &el_2);

// Side function for quick sort, takes the 'pivot' element and puts all elements of the array <= pivot to the left of the pivot, the rest to the right of it
long partition(long *arr, long start, long end);

// Recursive sorting algorithm that partitions the array and then does the same procedure for left and right sub-arrays
void quickSort(long *arr, long start, long end);

// Bubble sorting algorithm, sort of like a bubble swimming to the top, will push the smaller elements to the start of the array and the larger to the end
void bubbleSort(long *arr, long size);

// Checks whether the array has been/is sorted
bool isSorted(long *arr, long size);

// Checks whether the array has been/is sorted but for char arrays
bool isSorted(char *arr, long size);

// Randomly changes the order of array's elements
void shuffle(long *arr, long size);

// Bogo sort or stupid sort, randomly shuffles the array until it is sorted. Extremely inefficient
void bogoSort(long *arr, long size);

// Sorting algorithm that uses arithmetic rather than comparisons to sort an array
void countingSort(char *arr, long size);
#endif