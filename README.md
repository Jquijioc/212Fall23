# 212 Project- Sorting Algorithms
Term Project
Christine Adeyefa, Michael Baitch, Jason Li, Joseph Quijioc

## Program Description

Our Program seeks to analyze the efficiencies of these four sorting algorithms:

```
- `insertion sort`
- `mergesort`
- `quicksort`
- `bubblesort`
```

The project required our program to benchmark the algorithms the following sequence types:

```
- use different sequence sizes
- use different types of sequences:
  - sorted, reversed, random, partially sorted
```

# Instructions for Input and CLA

## File Structure

Our data was input via text file. The data in the text file was either sorted, reversed, random, or partially sorted. This required several files for each sequence to be made. 
While this made for more setup, it allowed for faster implementation on the users end.

## Command Line Arguments

The program's command line execution follow the form of:

```
g++ sort.cpp main.cpp -o test && ./test

```

Following this, the user will be prompted with inputting a number corresponding to a sorting algorithm

```
1. Bubble Sort 2. Quick Sort 3. Merge Sort 4. Insertion Sort

```

Finally, the data will be sorted and outputs shown:

```
Number of comparisons: 4535
Time taken by the sorting algorithm: 0.173 microseconds
Sorted array has been written to sorted.txt.

```

