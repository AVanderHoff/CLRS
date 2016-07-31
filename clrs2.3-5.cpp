// clrs2.3-5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>     
#include <math.h> 
#include <iostream>
#include <array>
using namespace std;

void print(int[],int);
int binarySearch(int[], int,int,int);
int binarySearch2(int[], int, int, int);

int main()
{
	int list[] = { 1,2,3,4,5,6,7,8,9,10 };
	
	cout << binarySearch2(list, 5,0,9);
	return 0;
}

void print( int arr[],int length) {

	for (int i = 0; i < length;i++) {
		cout << arr[i];
		cout <<  endl;
	}
}

int binarySearch(int arr[], int value, int left, int right) {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (arr[middle] == value)
			return middle;
		else if (arr[middle] > value)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}




























int binarySearch2(int arr[], int val, int left, int right) {

		while (left <= right) {
			int middle = (left + right) / 2;
			if (arr[middle] == val) {
				return middle;
			}
			else if (val < arr[middle]) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		return -1;

}



