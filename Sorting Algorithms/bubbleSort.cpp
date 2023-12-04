#include <iostream>
#include <vector>
#include <fstream>

void bubbleSort(std::vector<float>& arr, int& comparisons) {
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<float> arr;
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Unable to open file " << filename << std::endl;
        return 1;
    }

    float value;
    while (file >> value) {
        arr.push_back(value);
    }
    file.close();

    int comparisons;  
    bubbleSort(arr, comparisons);

    std::ofstream output_file("sorted_array.txt");
    if (!output_file) {
        std::cout << "Unable to open output file." << std::endl;
        return 1;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        output_file << arr[i] << std::endl;
    }
    output_file.close();

    std::cout << "Sorted array has been written to sorted_array.txt." << std::endl;
    std::cout << "Number of comparisons: " << comparisons << std::endl;

    return 0;
}
