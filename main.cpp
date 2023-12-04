#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sort.h"

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
        std::cout<< value <<std::endl;
    }
    file.close();

    //menu to a sort

    int picked = sort.menu();
    int comparisons= 0;

    if(picked == 1){
        sort.bubbleSort(arr, comparisons);
    } else if (picked == 2){
        sort.quicksort(arr,0, arr.size()-1);
    } else if (picked == 3){
        sort.mergeSort(arr, 0, static_cast<int>(arr.size()-1));
    }

    std::cout << "num comparisons: " << comparisons <<std::endl;

    //std::cout << "arr size is " << arr.size() << std::endl;

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << " ";
    }
}

