#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    std::ifstream file("Binary_Search_input_10000.txt");
    if (!file) {
        std::cerr << "Failed to open input file.\n";
        return 1;
    }

    std::vector<int> arr;
    int num;
    while (file >> num) {
        arr.push_back(num);
    }

    // Ensure the array is sorted
    std::sort(arr.begin(), arr.end());

    int target;
    std::cout << "Enter the number to search for: ";
    std::cin >> target;

    auto start = std::chrono::high_resolution_clock::now();
    int index = binarySearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    if (index != -1)
        std::cout << "Element found at index " << index << ".\n";
    else
        std::cout << "Element not found.\n";

    std::cout << "Time taken: " << duration.count() << " milliseconds.\n";

    return 0;
}
