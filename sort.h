#include <iostream>
#include <vector>
#include <string>

class Sort{
private:
    //int input;


public:
    int menu();

    //insertion
    void insertionSort(std::vector<float>& arr, int& comparisons);

    //merge
    void merge(std::vector<float> &arr, int start, int middle, int end);
    void mergeSort(std::vector<float> &arr,int start, int end);


    //bubble
    void bubbleSort(std::vector<float>& arr, int& comparisons);

    //quicksort
    void quicksort(std::vector<float>& arr, int low, int high);
    int partition(std::vector<float>& arr, int low, int high);


};
