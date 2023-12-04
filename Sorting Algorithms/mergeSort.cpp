#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// merges two subarrays of array[].
void merge(std::vector<float> &arr, int start, int middle, int end, int& comparisons) {

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
        comparisons++;  // Increment comparisons for each comparison made
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
void mergeSort(std::vector<float> &arr, int start, int end, int& comparisons) {
    // base case
    if (start < end) {
        // find the middle point
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle, comparisons); // sort first half
        mergeSort(arr, middle + 1, end, comparisons);  // sort second half

        // merge the sorted halves
        merge(arr, start, middle, end, comparisons);
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<float> arr;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }

    float value;
    while (file >> value) {
        arr.push_back(value);
    }
    file.close();

    int comparisons = 0;  // Variable to store the number of comparisons
    mergeSort(arr, 0, static_cast<int>(arr.size() - 1), comparisons);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << " ";
    }

    std::cout << std::endl;
    std::cout << "Number of comparisons: " << comparisons << std::endl;

    return 0;
}
