#include <iostream>
#include <vector>
#include <cmath>

void jumpSort(std::vector<int>& arr) {
    int n = arr.size();
    int jump = static_cast<int>(sqrt(n));  // Jump distance

    // Perform jump sort
    for (int i = 0; i < n; i += jump) {
        // Find the insertion point for the current element
        int key = arr[i];
        int j = i - jump;
        while (j >= 0 && arr[j] > key) {
            arr[j + jump] = arr[j];
            j -= jump;
        }
        arr[j + jump] = key;
    }

    // Perform final insertion sort on the sorted blocks
    for (int i = jump; i < n; i++) {
        int key = arr[i];
        int j = i - jump;
        while (j >= 0 && arr[j] > key) {
            arr[j + jump] = arr[j];
            j -= jump;
        }
        arr[j + jump] = key;
    }
}

int main() {
    std::vector<int> arr = {29, 10, 14, 37, 13};
    std::cout << "Original array:";
    for (int num : arr)
        std::cout << " " << num;
    std::cout << std::endl;

    jumpSort(arr);

    std::cout << "Sorted array:";
    for (int num : arr)
        std::cout << " " << num;
    std::cout << std::endl;

    return 0;
}
