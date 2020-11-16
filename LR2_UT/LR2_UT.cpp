#include "pch.h"
#include "CppUnitTest.h"
#include "..\sortings.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LR2UT
{
	TEST_CLASS(LR2UT)
	{
	public:
		
		TEST_METHOD(TestBinarySearch)
		{
			srand(time(NULL)); // Setting new rand() seed to get different random values each run
			long *arr = NULL, target = 0, targetIndex = 0, foundIndex = 0, size = 0;
			
			size = rand() % 100 + 1; // Randomly generating size for our new array
			arr = new long[size]; // Allocating memory for the array

			for (long j = 0; j < size; j++)
				arr[j] = rand() % 1000 + 1; // Filling array with random value

			quickSort(arr, 0, size - 1); // Sorting the array

			targetIndex = rand() % size; // Randomly generating target index
			target = arr[targetIndex]; // Getting target value

			foundIndex = binarySearch(arr, target, size); // Searching for target value
			Assert::IsTrue(foundIndex == targetIndex); // Checking if binary search function worked correctly
			delete[] arr; // Deallocating memory for our array
		}

		TEST_METHOD(TestQuickSort)
		{
			srand(time(NULL)); // Setting new rand() seed to get different random values each run
			long *arr = NULL, size = 0;

			size = rand() % 100 + 1; // Randomly generating size for our new array
			arr = new long[size]; // Allocating memory for the array

			for (long j = 0; j < size; j++)
				arr[j] = rand() % 1000 + 1; // Filling array with random value

			quickSort(arr, 0, size - 1); // Sorting the array
			Assert::IsTrue(isSorted(arr, size)); // Checking if quick sort function worked correctly
			delete[] arr; // Deallocating memory for our array
		}

		TEST_METHOD(TestBubbleSort)
		{
			srand(time(NULL)); // Setting new rand() seed to get different random values each run
			long *arr = NULL, size = 0;

			size = rand() % 100 + 1; // Randomly generating size for our new array
			arr = new long[size]; // Allocating memory for the array

			for (long j = 0; j < size; j++)
				arr[j] = rand() % 1000 + 1; // Filling array with random value

			bubbleSort(arr, size); // Sorting the array
			Assert::IsTrue(isSorted(arr, size)); // Checking if bubble sort function worked correctly
			delete[] arr; // Deallocating memory for our array
		}

		TEST_METHOD(TestBogoSort)
		{
			srand(time(NULL)); // Setting new rand() seed to get different random values each run
			long *arr = NULL, target = 0, targetIndex = 0, size = 0;

			size = rand() % 10 + 1; // Randomly generating size for our new array (just 10 in this case because bogo sort is really, really slow)
			arr = new long[size]; // Allocating memory for the array

			for (long j = 0; j < size; j++)
				arr[j] = rand() % 1000 + 1; // Filling array with random value

			bogoSort(arr, size); // Sorting the array
			Assert::IsTrue(isSorted(arr, size)); // Checking if bubble sort function worked correctly
			delete[] arr; // Deallocating memory for our array
		}

		TEST_METHOD(TestCountingSort)
		{
			srand(time(NULL)); // Setting new rand() seed to get different random values each run
			char *arr = NULL, target = 0, targetIndex = 0, size = 0;

			size = rand() % 100 + 1; // Randomly generating size for our new array
			arr = new char[size]; // Allocating memory for the array

			for (long j = 0; j < size; j++)
				arr[j] = rand() % 127; // Filling array with random value

			countingSort(arr, size); // Sorting the array
			Assert::IsTrue(isSorted(arr, size)); // Checking if bubble sort function worked correctly
			delete[] arr; // Deallocating memory for our array
		}
	};
}
