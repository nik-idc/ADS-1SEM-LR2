#include "sortings.h"
#include <iomanip>
#include <chrono>

void test(long *arr, long *arrCopy, long size)
{
	auto fin1 = std::chrono::nanoseconds(0), fin2 = std::chrono::nanoseconds(0);
	for (int k = 0; k < 10; k++)
	{
		for (long j = 0; j < size; j++)
		{
			arr[j] = rand() % 1000000;
			arrCopy[j] = arr[j];
		}

		auto start = std::chrono::high_resolution_clock::now();
		quickSort(arr, 0, size - 1);
		auto end = std::chrono::high_resolution_clock::now();
		auto finish = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		fin1 += finish;

		start = std::chrono::high_resolution_clock::now();
		bubbleSort(arrCopy, size);
		end = std::chrono::high_resolution_clock::now();
		finish = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		fin2 += finish;
	}

	fin1 /= 10, fin2 /= 10;
	std::cout << "The average timings for " << size << " elements are: for 'quick sort' the average time is - " 
	<< fin1.count() << "x10^-9 seconds and for 'bubble sort' - " << fin2.count() << "x10^-9 seconds" << std::endl;
}

int main()
{
	srand(time(NULL)); // Setting new rand() seed to get different random values each run

	long *arr, *arrCopy, k = 10;

	for (int i = 0; i < 5; i++)
	{
		arr = new long[k];
		arrCopy = new long[k];

		test(arr, arrCopy, k);

		delete[] arr;
		delete[] arrCopy;
		k *= 10;
	}
	return 0;
}