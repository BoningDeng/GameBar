#include <bits/stdc++. h>
using namespace std;
#include Game.h

//Helper merge function
void merge(Game* arr[], int left, int middle, int right){
    int const leftSub = mid - left + 1;
    int const rightSub = right - middle;
 
    // Create temp arrays for left and right 
    
    auto *leftArr = new Game[leftSub],
    auto  *rightArr = new Game[rightSub];
 
    // Copy data from our game Array into the temporary arrays.
    for (int i = 0; i < leftSub; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSub; i++)
        rightArr[j] = arr[middle + 1 + i];
 
    //Declare indexes for the temporary arrays, those will be updated while merging
    int leftIndex = 0;
    int rightIndex = 0;
    int merged = 0;
 
    // Merge both temp arrays into a single 
    while (leftIndex < leftSub && rightIndex < rightSub) {
        if (leftArr[leftIndex <= rightArr[rightIndex]) {
            arr[merged] = leftArr[leftIndex];
            leftIndex++;
        }
        else {
            arr[merged] = rightArr[rightIndex];
            rightIndex++;
        }
        merged++;
    }
                    
    // Copy the remaining elements of left and right
    while (leftIndex < leftSub) {
        arr[merged] = leftArr[leftIndex];
        leftIndex++;
        merged++;
    }
    while (rightIndex < rightSub) {
        arr[merged] = rightArr[rightIndex];
        rightIndex++;
        merged++;
    }
    
    //delete our temp arrays to free up space
    delete[] leftArr;
    delete[] rightArr;
}
                    
//print function
void printArray(Game* arr[]){
  
  cout << "Presenting your game list trough Merge Sort algorithm: " << endl;
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i]->name << endl;
    cout << "Platform: " << arr[i]->platform << endl;
    cout << "Released in: " <<arr[i]->release_date << endl;
    cout << "Meta Score: "  << to_string(arr[i]->meta_score) << endl;
    cout << "User Review: " << to_string(arr[i]->user_review) << endl;
    cout << arr[i]->summary << endl;
  
  }
}

//MergeSort main function
void mergeSort(Game* arr[], int start, int end){ 
  //Return if left element is bigger than rightmost
    if (start >= end)
        return; 
 
    int middle = start + (end - begin) / 2;
  
    //Recursively call mergeSort for left array (left to middle) and right array (middle to right)
    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);
  
    
    merge(arr, begin, mid, end);
  
    printArray(arr);
}
