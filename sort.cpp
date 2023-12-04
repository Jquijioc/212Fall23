#include <iostream>
#include <vector>
#include <string>
#include "sort.h"


//MergeSort

// merges two subarrays of array[].
void Sort::merge(std::vector<float> &arr, int start, int middle, int end) {

    std::vector<float> leftArray(middle - start + 1);
    std::vector<float> rightArray(end - middle);

    // fill in left array
    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

    // fill in right array
    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

    /* Merge the temp arrays */

    // initial indexes of first and second subarrays
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subarrays back into the main array
    int currentIndex = start;

    // compare each index of the subarrays adding the lowest value to the currentIndex
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    // copy remaining elements of leftArray[] if any
    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    // copy remaining elements of rightArray[] if any
    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

// main function that sorts array[start..end] using merge()
void Sort::mergeSort(std::vector<float> &arr, int start, int end) {
    // base case
    if (start < end) {
        // find the middle point
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle); // sort first half
        mergeSort(arr, middle + 1, end);  // sort second half

        // merge the sorted halves
        merge(arr, start, middle, end);
    }
}

//bubble sort

void Sort::bubbleSort(std::vector<float>& arr, int& comparisons) {
    int n = arr.size();
    comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


//quicksort

void Sort::quicksort(std::vector<float>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int Sort::partition(std::vector<float>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int Sort::menu(){
    bool test = false;
    int numChose;

    while(test == false){
        //ask what to do
        std::cout << "Please pick a number for a sorting algo:" <<std::endl;
        std::cout << "1. Bubble Sort 2. Quick Sort 3. Merge Sort 4. Insertion Sort" << std::endl;

        std::string input;
        std::cin >> input;

        numChose = std::stoi(input);


        if(numChose > 4 || numChose < 1){

            std::cout << "Wrong number selected" << std::endl;
        } else{
            test = true;
        }

    }
    return numChose;
}