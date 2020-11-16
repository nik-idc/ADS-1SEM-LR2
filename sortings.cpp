#include "sortings.h"

int binarySearch(long *arr, long target, long size)
{
	long left = 0, right = size - 1, index = 0; // 'left' and 'right' control in which are of the array we are searching

	while (left <= right) // As long as the left part of the search area doesn't overlap the right area we continue the search
	{
		index = (left + right) / 2; // Middle of current search area
		if (arr[index] > target)
			right = index - 1; // If target element is to the left of the center of the current search area, then shrinking search area by half to the right
		else if (arr[index] < target)
			left = index + 1; // If target element is to the right of the center of the current search area, then shrinking search area by half to the left
		else 
			return index; // Returning the found element
	}

	return index; // Returning the found element
}

void swap(long &el_1, long &el_2)
{
	long temp = el_2;
	el_2 = el_1;
	el_1 = temp;
}

long partition(long *arr, long start, long end)
{
	long pivot = arr[(start + end) / 2];
	long i = start - 1;
	long j = end + 1;
	while (1)
	{
		do
			i = i + 1;
		while (arr[i] < pivot);
		do
			j = j - 1;
		while (arr[j] > pivot);
		if (i >= j)
			return j;
		swap (arr[i], arr[j]);
	}

	//long pivotIndex = start, pivot = arr[(start + end) / 2]; // Setting the pivot index variable to the start of array and the pivot to the last element of array
	//for (long i = start; i < end; i++) // Going through the array from the start
	//{
	//	if (arr[i] <= pivot) // If current element is less or equal than the we swap the the current element with the element at index 'pivotIndex'
	//	{
	//		swap(arr[i], arr[pivotIndex]);
	//		pivotIndex++;
	//	}
	//}
	//swap(arr[pivotIndex], arr[end]); // Upon exiting the loop 'pivotIndex' represents the index of the pivot in a partitioned array, so this makes the final swap in the array
	//return pivotIndex; // Returning the final value
}

void quickSort(long *arr, long start, long end)
{
	if (start >= end) // Exit condition
		return;
	long index = partition(arr, start, end); // First partition the array, i.e. put all elements <= pivot to the left of the pivot, and elements > pivot to the right of the pivot

	//if (start < index) 
		quickSort(arr, start, index); //Sort sublist before the pivot
	//if (index + 1 < end)
		quickSort(arr, index + 1, end);	//Sort sublist after the pivot
	
}

void bubbleSort(long *arr, long size)
{
	bool flag = true; // Flag variable to check whether the array is already sorted
	for (long i = 0; i < size - 1 && flag == true; i++)
	{
		flag = false; // Flag variable to check whether the array is already sorted
		for (long j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) // If current element is larger than the element after it then we swap them, thus pushing the larger elements to the end
			{
				swap(arr[j], arr[j + 1]);
				flag = true; // Setting the flag to 'true' to signal that there has been a swap
			}
		}
	}
}

bool isSorted(long *arr, long size)
{
	for (long int i = 0; i < size - 1; i++)
		if (arr[i] > arr[i + 1]) // If the current element is larger than the next then the array is not sorted
			return false;
	
	return true;
}

bool isSorted(char *arr, long size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i] > arr[i + 1]) // If the current element is larger than the next then the array is not sorted
			return false;
	
	return true;
}

void shuffle(long *arr, long size)
{
	for (int i = 0; i < size; i++)
		swap(arr[i], arr[rand() % size]); // Shuffling the array
}

void bogoSort(long *arr, long size)
{
	while (!isSorted(arr, size)) // While the array is not sorted randomly change the order of elements and see if the array is sorted
		shuffle(arr, size);
}

void countingSort(char* arr, long size)
{
	const int countSize = 128; // Size of count array, in this case 128 because a 'char' variable can be any character from the ascii table which is comprised of 128 characters

	int count[countSize]; // Creating the count array
	for (long i = 0; i < countSize; i++)
		count[i] = 0;

	for (long i = 0; i < size; i++)
		count[arr[i]]++; // Filling count array with the amount of times each element is repeated in the array
	
	for (long i = 1; i < countSize; i++)	
		count[i] += count[i - 1]; // Doing the algorithm's arithmetic

	char *newArr = new char[size]; // Creating new array
	for (long i = 0; i < size; i++)
	{
		newArr[count[arr[i]] - 1] = arr[i]; // Filling new array
		count[arr[i]]--;
	}

	for (long i = 0; i < size; i++)
		arr[i] = newArr[i]; // Copying data from the new array to the old array

	delete[] newArr; // Deleting all the allocated memory
}