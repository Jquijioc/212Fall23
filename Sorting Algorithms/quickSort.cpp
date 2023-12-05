#include <iostream>
#include <vector>
#include <fstream>

// Function declarations
void quicksort(std::vector<float>& arr, int low, int high, int& comparisons);
int partition(std::vector<float>& arr, int low, int high, int& comparisons);

int main(int argc, char *argv[]) {
    // Check for proper usage and command line arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    // Reading the input file
    std::string filename = argv[1];
    std::vector<float> arr;
    std::ifstream file(filename);

    // Check if file opening was successful
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }

    // Reading values from file into vector
    float value;
    while (file >> value) {
        arr.push_back(value);
    }
    file.close();

    // Initialize a counter for the number of comparisons
    int comparisons = 0;
    // Perform quicksort on the array
    quicksort(arr, 0, arr.size() - 1, comparisons);

    // Output the sorted array
    std::cout << "Sorted array: ";
    for (float i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Output the number of comparisons made during sorting
    std::cout << "Number of comparisons: " << comparisons << std::endl;

    return 0;
}

// Quicksort function
void quicksort(std::vector<float>& arr, int low, int high, int& comparisons) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high, comparisons);

        quicksort(arr, low, pi - 1, comparisons);
        quicksort(arr, pi + 1, high, comparisons);
    }
}

int partition(std::vector<float>& arr, int low, int high, int& comparisons) {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;  // Increment comparison count
        if (arr[j] < pivot) {
            i++;  // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}
