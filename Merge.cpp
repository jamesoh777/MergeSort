#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <algorithm>
#define SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

vector<int> concat(int head, vector<int> list) {
	vector<int> concatList;
	concatList.push_back(head);
	for (int i = 0; i < list.size(); i++) {
		concatList.push_back(list[i]);
	}
	return concatList;
}

vector<int> merge(vector<int> A, vector<int> B) {
	if (A.empty())
		return B;
	if (B.empty())
		return A;
	if (A[0] < B[0]) {
		vector<int> newVectorA;
		for (int i = 1; i < A.size(); i++) {
			newVectorA.push_back(A[i]);
		}
		return concat(A[0], merge(newVectorA, B));
	} else {
		vector<int> newVectorB;
		for (int i = 1; i < B.size(); i++) {
			newVectorB.push_back(B[i]);
		}
		return concat(B[0], merge(A, newVectorB));
	}
}

vector<int> mergeSort(vector<int> list, int length) {
	if (length == 1) 
		return list; // Already sorted
	int middle = floor(length/2);
	// Split the list into two halves
	vector<int> firstHalf;
	vector<int> secondHalf;
	for(int i = 0; i < middle; i++) {
		firstHalf.push_back(list[i]);
	}
	for(int i = middle; i < list.size(); i++) {
		secondHalf.push_back(list[i]);
	}
	// Break the list into individual elements, then start merging them
	return merge(mergeSort(firstHalf, middle), mergeSort(secondHalf, length - middle));
}

int main() {
	// Testing
	int arr1[] = {1, 5, 2, 0, 3, 9, 13, 6, 4, 22, 11, 15, 17, 14}; // Test list
	vector<int> A (arr1, arr1 + SIZE(arr1));

	vector<int> answer;
	answer = mergeSort(A, A.size());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}



