#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string.h>
using namespace std;


	////////////////////////////////////////////////
	//
	// How many numbers to make
	//
	///////////////////////////////////////////////

#define SIZE_OF_ARRAY 20

	///////////////////////////////////////////////
	//
	// Swapping first data[0] with second data[1]
	//
	//////////////////////////////////////////////

void swap(int *num1, int *num2)
{
	int buffer = *num1;

	*num1 = *num2;
	*num2 = buffer;

}

	////////////////////////////////////////////////
	//
	//	MAIN
	//
	///////////////////////////////////////////////

int main()
{

	////////////////////////////////////////////
	//
	//	Declaring Varibles
	//
	////////////////////////////////////////////

	const int n = SIZE_OF_ARRAY;
	int data[n] = { 10,5,6,4,8,7,1,3,9,2,11,12,13,14,16,15,17,18,19,20 };
	bool swapped = false;
	int L = 0;
	int R = n - 1;
	int wantedNumber = 10;
	int found = 0;
	int result = 0;
	int rounds = 0;

	///////////////////////////////////////////////////////
	//
	// BUBBLE SORT
	//
	//////////////////////////////////////////////////////

	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(&data[j], &data[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}


	//////////////////////////////////////////////
	//
	//	BINARY SEARCH
	//
	///////////////////////////////////////////////

	while (L <= R)
	{
		found = ((L + R) / 2);

		rounds++;

		if (data[found] == wantedNumber)
		{
			result = data[found];
			break;
		}
		if (data[found] < wantedNumber)
		{
			L = found + 1;
		}
		if (data[found] > wantedNumber)
		{
			R = found - 1;
		}
	}


	/////////////////////////////////////////////////////
	//
	//	Output sorted
	//
	////////////////////////////////////////////////////
	
	cout << "Sorted: ";
	for (int i = 0; i < n; i++)
	{
		cout << data[i] << ", ";
	}
	cout << endl << "Found " << wantedNumber << " in " << rounds << " loops"<< endl;;
	system("pause");
	return 0;
}