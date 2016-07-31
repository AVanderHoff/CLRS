// CLRS4.1-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
using namespace std;

int main(){
	int chart[16]{ 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int sum{ -1 * numeric_limits<int>::max() };
	int running{ 0 };
	int start;
	int end;
	for (auto i = 0; i < 16; ++i) {
		for (auto v = i; v < 16; ++v) {
			running += chart[v];
			if (running > sum) {
				sum = running;
				start = i;
				end = v ;
			}
		}
		running = 0;
	}
	cout << start << "\n" << end << "\n" << sum;
	return 0;
}
