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

//merge will sort based on user ratings.
void merge(vector<Game*> &v, int start, int middle, int end){
        vector<Game*> merged;

	int left = start;
        int right = middle + 1;

	while (left <= middle && right <= end) {

		if (v[left]->getUser_review() <= v[right]->getUser_review()) {
			merged.push_back(v[left]);
			left++;
		}
		else {
			merged.push_back(v[right]);
			right++;
		}

	}

	while (left <= middle) {
		merged.push_back(v[left]);
		left++;
	}

	while (right <= end) {
		merged.push_back(v[right]);
		right++;
	}

	for (int i = start; i <= end; i++)
		v[i] = merged[i - start];
}

//merge2 will sort based on critic rating (meta score).
void merge2(vector<Game*> &v, int start, int middle, int end){
        vector<Game*> merged;

	int left = start;
        int right = middle + 1;

	while (left <= middle && right <= end) {

		if (v[left]->getMeta_score() <= v[right]->getMeta_score()) {
			merged.push_back(v[left]);
			left++;
		}
		else {
			merged.push_back(v[right]);
			right++;
		}

	}

	while (left <= middle) {
		merged.push_back(v[left]);
		left++;
	}

	while (right <= end) {
		merged.push_back(v[right]);
		right++;
	}

	for (int i = start; i <= end; i++)
		v[i] = merged[i - start];
}
                    

//MergeSort main function
void mergeSort(vector<Game*> &v, int start, int end, int input){ 
        if (start < end){
            if (input == 1) {
                int middle = (start + end) / 2;
  
            //Recursively call mergeSort for left array (left to middle) and right array (middle to right)
                mergeSort(v, start, middle, input);
                mergeSort(v, middle + 1, end, input);
                merge(v, start, middle, end);
            } else if (input == 2) {
 
                int middle = (start + end) / 2;
                mergeSort(v, start, middle, input);
                mergeSort(v, middle + 1, end, input);
                merge2(v, start, middle, end);
            }   
        }
 
  
}  
  

