#include <iostream>
#include <string>
#pragma warning (disable: 4996)
using namespace std;

//function merge 
inline void merge(int Arr[], int left, int mid, int right) 
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Creating temp arrays
	int* L, * R;
	L = new int[n1];
	R = new int[n2];

	// Copy data to temp arrays
	for (i = 0; i < n1; i++)
		L[i] = Arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = Arr[mid + 1 + j];

	// Merging back to arr[left..right]
	i = j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			Arr[k] = L[i];
			i++;
		}

		else 
		{
			Arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements
	while (i < n1) 
	{
		Arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		Arr[k] = R[j];
		j++;
		k++;
	}
}

//function mergeSort
inline void mergeSort(int arr[], int left, int right) 
{
	if (left < right) 
	{
		// Find the middle
		int mid = (left + right) / 2;

		// Recursion
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// Merging
		merge(arr, left, mid, right);
	}
}

//function to read array 
inline void read(int* Arr, int size)
{
	cout << endl << "read an elements in the array " << endl;
	for (int k = 1; k <= size; ++k)
	{
		cout << "enter number(" << k << "): ";
		cin >> Arr[k];
	}
}

// function display array 
inline void printArray(int Arr[], int size)
{
	for (register int i = 1; i <= size; i++)
		cout << Arr[i] << "	";
}


int main(void) {
	int size;
	cout << endl << "Enter the size of the array :";
	cin >> size;
	int* array = new int[size];
	read(array, size);
	cout << endl << endl << "sorting array using (merge Sort) " << endl;
	mergeSort(array, 0, size);
	printArray(array, size);
	cout << endl;
}