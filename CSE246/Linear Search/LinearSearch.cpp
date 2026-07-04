#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    std::ifstream file("Linear_Search_input_10000.txt");
    if (!file) {
        std::cerr << "Failed to open input file.\n";
        return 1;
    }

    std::vector<int> arr;
    int num;
    while (file >> num) {
        arr.push_back(num);
    }

    int target;
    std::cout << "Enter the number to search for: ";
    std::cin >> target;

    auto start = std::chrono::high_resolution_clock::now();
    int index = linearSearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    if (index != -1)
        std::cout << "Element found at index " << index << ".\n";
    else
        std::cout << "Element not found.\n";

    std::cout << "Time taken: " << duration.count() << " milliseconds.\n";

    return 0;
}
