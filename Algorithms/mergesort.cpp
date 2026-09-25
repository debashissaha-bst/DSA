#include <iostream>
#include <vector>

// Merge two sorted sub-arrays into a single sorted range
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary vectors to hold split data
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge temporary arrays back into arr
    int i = 0; // Initial index of left sub-array
    int j = 0; // Initial index of right sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy remaining elements of leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy remaining elements of rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Main recursive Merge Sort function
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; // Base case: 1 or 0 elements
    }

    int mid = left + (right - left) / 2; // Prevents overflow compared to (left + right) / 2

    // Divide and conquer
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combine
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> numbers = {38, 27, 43, 3, 9, 82, 10, 5, 60};

    mergeSort(numbers, 0, numbers.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}