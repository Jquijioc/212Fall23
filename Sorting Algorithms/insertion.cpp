#include <iostream>
#include <vector>
#include <fstream>

void insertionSort(std::vector<float>& arr, int& comparisons) {
    // get arr length
    int n = arr.size();
    
    // loop through arr to compare each element
    for (int i = 1; i < n; i++) {
        float curr = arr[i];
        int j = i - 1;

        // count the number of comparisons
        comparisons++;

       // move element greater than curr ahead
        while (j >= 0 && arr[j] > curr) {
            // count the number of comparisons
            comparisons++;
            // move curr to the right
            arr[j + 1] = arr[j];
            // move to next element
            j = j - 1;
        }
        // move curr to the right position
        arr[j + 1] = curr;
    }
}

int main(int argc, char *argv[]) {
    std::string fname = argv[1];
    // initialize vector
    std::vector<float> arr;
    // open file
    std::ifstream file(fname);
    
    // read file
    float value;
    while (file >> value) {
        arr.push_back(value);
    }
    
    file.close();
    // intialize comparisons
    int comparisons = 0;
    // call insertion sort
    insertionSort(arr, comparisons);

    // print the sorted list
    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    // print comparisons
    std::cout << "Number of comparisons: " << comparisons << std::endl;

    return 0;
    
}
