#include <iostream>
#include <vector>
#include <fstream>

void bubblesort(std::vector<int>& arr);
void swap(int& a, int& b);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<int> arr;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }

    int value;
    while (file >> value) {
        arr.push_back(value);
    }
    file.close();

    bubblesort(arr);

    // Open a new file to write the sorted array
    std::ofstream output_file("sorted_array.txt");
    if (!output_file) {
        std::cerr << "Unable to open output file." << std::endl;
        return 1;
    }

    // Write the sorted array to the file
    for (size_t i = 0; i < arr.size(); i++) {
        output_file << arr[i] << " ";
    }
    output_file.close();

    std::cout << "Sorted array has been written to sorted_array.txt." << std::endl;

    return 0;
}

void bubblesort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}