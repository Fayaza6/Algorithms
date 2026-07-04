#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];   
}

int main() {
    const std::string filename = "Knapsack_input_1.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open input file: " << filename << "\n";
        return 1;
    }

    int n, W;
    file >> n >> W;

    std::vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {
        file >> weights[i] >> values[i];
    }

    std::cout << "Running 0/1 Knapsack on file: " << filename << "\n";

    auto start = std::chrono::high_resolution_clock::now();
    int maxValue = knapsack(W, weights, values, n);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Maximum value achievable: " << maxValue << "\n";
    std::cout << "Time taken: " << duration.count() << " milliseconds.\n";

    return 0;
}
