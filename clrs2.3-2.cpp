// clrs2.3-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
using namespace std;

void print(int[], int);
void merge(int[], int, int, int);
void merge_sort(int[], int, int);

int main() {
	int arr[] = { 1,4,5,7,1,8,9,12,16,6 };

	merge_sort(arr, 0, 9);
	print(arr, 10);
	
	return 0;
}

void print(int arr[], int length) {
	
	for (int i = 0; i < length; i++) {
		
		cout << arr[i];
		cout << endl;
	
	}

}

void merge(int a[], int p, int q, int r) {
	int i, j, k;

	int n1 = q - p + 1 ;
	int n2 = r - q ;

 int *left = new int[n1];
 int *right = new int[n2];

	for (i = 0; i < n1; i++)
		left[i] = a[p + i];
	for (j = 0; j < n2; j++)
		right[j] = a[q + j + 1];

	for (i = 0, j = 0, k = p; k <= r; k++) {
		if (i == n1) {
			a[k] = right[j++];
		}
		else if (j == n2) {
			a[k] = left[i++];
		}
		else if (left[i] <= right[j]) {
			a[k] = left[i++];
		}
		else {
			a[k] = right[j++];
		}
	}
	delete [] left;
	delete [] right;

}

void merge_sort(int a[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}


