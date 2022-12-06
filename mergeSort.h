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
void merge(vector<Game*> &v, int start, int middle, int end){
    vector<Game*> temp;

	int i, j;
	i = start;
	j = middle + 1;

	while (i <= middle && j <= end) {

		if (v[i]->getUser_review() <= v[j]->getUser_review()) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= middle) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= end) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = start; i <= end; ++i)
		v[i] = temp[i - start];

    
}

void merge2(vector<Game*> &v, int start, int middle, int end){
    vector<Game*> temp;

	int i, j;
	i = start;
	j = middle + 1;

	while (i <= middle && j <= end) {

		if (v[i]->getMeta_score() <= v[j]->getMeta_score()) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= middle) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= end) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = start; i <= end; ++i)
		v[i] = temp[i - start];
}
                    

//MergeSort main function
void mergeSort(vector<Game*> &arr, int start, int end, int input){ 
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
  

