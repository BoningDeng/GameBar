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
void merge(vector<Game*> arr, int left, int middle, int right){
    int const leftSub = middle - left + 1;
    int const rightSub = right - middle;
 
    // Create temp arrays for left and right 
    vector<Game> L, R;
    
    L.resize(leftSub);
    R.resize(rightSub);
 
    // Copy data from our game Array into the temporary arrays.
    for (int i = 0; i < leftSub; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < rightSub; i++)
        R[i] = arr[middle + 1 + i];
 
    //Declare indexes for the temporary arrays, those will be updated while merging
    int leftIndex = 0;
    int rightIndex = 0;
    int merged = 0;
 
    // Merge both temp arrays into a single 
    while (leftIndex < leftSub && rightIndex < rightSub) {
        if (L[leftIndex] <= R[rightIndex]) {
            arr[merged] = L[leftIndex];
            leftIndex++;
        }
        else {
            arr[merged] = R[rightIndex];
            rightIndex++;
        }
        merged++;
    }
                    
    // Copy the remaining elements of left and right
    while (leftIndex < leftSub) {
        arr[merged] = L[leftIndex];
        leftIndex++;
        merged++;
    }
    while (rightIndex < rightSub) {
        arr[merged] = R[rightIndex];
        rightIndex++;
        merged++;
    }
    
}
                    

//MergeSort main function
void mergeSort(vector<Game*> arr, int start, int end){ 
  //Return if left element is bigger than rightmost
    if (start >= end)
        return; 
 
    int middle = start + (end - start) / 2;
  
    //Recursively call mergeSort for left array (left to middle) and right array (middle to right)
    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);
  
    
    merge(arr, start, middle, end);
  
}  
