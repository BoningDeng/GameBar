#pragma once
#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>  
using namespace std;

//Helper merge function
void merge(vector<Game*> v, int s, int m, int e){
    vector<Game*> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i]->getUser_score <= v[j]->getUser_Score) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

    
}

void merge2(vector<Game*> v, int s, int m, int e){
    vector<Game*> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i]->getUser_score <= v[j]->getUser_Score) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}
                    

//MergeSort main function
void mergeSort(vector<Game*> arr, int start, int end, int input){ 
        if (start < end){
            if (input == 1) {
                int middle = (start + end) / 2;
  
            //Recursively call mergeSort for left array (left to middle) and right array (middle to right)
                mergeSort(arr, start, middle, input);
                mergeSort(arr, middle + 1, end, input);
                merge(arr, start, middle, end);
            } else if (input == 2) {
 
                int middle = (start + end) / 2;
                mergeSort(arr, start, middle, input);
                mergeSort(arr, middle + 1, end, input);
                merge2(arr, start, middle, end);
            }   
        }
 
  
}  
