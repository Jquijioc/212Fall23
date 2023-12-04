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
    void merge(std::vector<float> &arr, int start, int middle, int end, int &comparisons);
    void mergeSort(std::vector<float> &arr, int start, int end, int &comparisons);


    //bubble
    void bubbleSort(std::vector<float>& arr, int& comparisons);

    //quicksort
    void quickSort(std::vector<float>& arr, int low, int high, int& comparisons);
    int partition(std::vector<float>& arr, int low, int high, int& comparisons);


};
