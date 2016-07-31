// CLRS4.1-3.cpp : Defines the entry point for the console application.
//
// havnt worked on anylizing code yet

#include "stdafx.h"
#include <iostream>
#include <limits>
using namespace std;

struct Answer{
	int left, right, sum;
	
	Answer(int left, int right, int sum) : left(left) , right(right) , sum(sum){}
};

Answer bruteFindMaximumSubarray(int[], int, int);
Answer findMaxCrossingSubarray(int[], int, int, int);
Answer findMaximumSubarray(int[], int, int);


int main(){
	int a[] = { 1,2,3,4,5,6 };
	int chart[16]{ 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	
	Answer result = findMaximumSubarray(chart, 0, 15);
	cout << result.left << "\n";
	cout << result.right << "\n";
	cout << result.sum << "\n";
	Answer result2 = bruteFindMaximumSubarray(chart, 0, 15);
	cout << result2.left << "\n";
	cout << result2.right << "\n";
	cout << result2.sum;

		
	   
	
	return 0;

}
   

Answer findMaxCrossingSubarray(int A[], int low, int mid, int high) {

	
	int leftSum{ -1 * numeric_limits<int>::max() };
	int rightSum{ leftSum };
	int sum{ 0 };
	int maxLeft;
	int maxRight;
	for (auto i = mid; i >= low; --i) {
		sum += A[i];
		if (sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
	}
	sum = 0;
	for (auto j = mid + 1; j <= high; ++j) {
		sum += A[j];
		if (sum > rightSum) {
			rightSum = sum;
			maxRight = j;
		}
	}

	return Answer(maxLeft, maxRight, leftSum + rightSum);

}

Answer findMaximumSubarray(int A[], int low, int high) {
	int mid = (low + high) / 2;
	if (low == high) {
		return Answer(low, high, A[low]);
	}
	else {  
		
		Answer left = findMaximumSubarray(A, low, mid);
		Answer right = findMaximumSubarray(A, mid + 1, high);
		Answer middle = findMaxCrossingSubarray(A, low, mid, high);
	
		if (left.sum >= right.sum && left.sum >= middle.sum){
			return Answer(left.left, left.right, left.sum);
		}  
		else if (right.sum >= left.sum && right.sum >= middle.sum) {
			return Answer(right.left, right.right, right.sum);
		}
		else {
			return middle;
		}
	
	
	
	}


}

Answer bruteFindMaximumSubarray(int A[], int low, int high) {

	int running{ 0 };
	int sum{ 0 };
	int start, end;

	for (auto i = low; i < high; ++i) {
		for (auto v = i; v < high; ++v) {
			running += A[v];
			if (running > sum) {
				sum = running;
				start = i;
				end = v;
			}
		}
		running = 0;
	}

	return Answer(start, end, sum);








}





