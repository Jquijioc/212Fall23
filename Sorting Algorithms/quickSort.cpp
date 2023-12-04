#include <iostream>
#include <vector>
#include <fstream>

void quicksort(std::vector<float>& arr, int low, int high, int& comparisons);
int partition(std::vector<float>& arr, int low, int high, int& comparisons);

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
    quicksort(arr, 0, arr.size() - 1, comparisons);

    std::cout << "Sorted array: ";
    for (float i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of comparisons: " << comparisons << std::endl;

    return 0;
}

void quicksort(std::vector<float>& arr, int low, int high, int& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quicksort(arr, low, pi - 1, comparisons);
        quicksort(arr, pi + 1, high, comparisons);
    }
}

int partition(std::vector<float>& arr, int low, int high, int& comparisons) {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;  // Increment comparisons for each comparison made
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
