#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sort.h"
#include <chrono> 
#include <iomanip> 

int main(int argc, char *argv[]) {

    Sort sort;

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

    //menu to a sort
    int picked = sort.menu();
    int comparisons= 0;

    std::chrono::steady_clock::time_point start_time;

    if(picked == 1){
        auto start_time = std::chrono::high_resolution_clock::now();
        sort.bubbleSort(arr, comparisons);
    } 
    else if (picked == 2){
        auto start_time = std::chrono::high_resolution_clock::now();
        sort.quickSort(arr,0, arr.size()-1,comparisons);
    } 
    else if (picked == 3){
        auto start_time = std::chrono::high_resolution_clock::now();
        sort.mergeSort(arr, 0, static_cast<int>(arr.size()-1),comparisons);
    }
    else if (picked == 4) {
        auto start_time = std::chrono::high_resolution_clock::now();
        sort.insertionSort(arr,comparisons);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
    std::cout << "Number of comparisons: " << comparisons <<std::endl;
    std::cout << "Time taken by the sorting algorithm: " << duration.count() << " seconds" << std::endl;

    std::ofstream outputFile("sorted.txt");
    if (!outputFile) {
        std::cerr << "Unable to create output file." << std::endl;
        return 1;
    }

    outputFile << std::fixed << std::setprecision(2);

    for (int i = 0; i < arr.size(); i++) {
        outputFile << arr[i] << std::endl;
        std::cout << arr[i];
    }
    
    std::cout << "Sorted array has been written to sorted.txt." << std::endl;

    return 0;
    
}
