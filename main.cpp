#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <iomanip>

#include "src/diffusion.hpp"

int main() {
    std::random_device rd;
    std::mt19937 rand(rd());

    std::vector<int> nValues = {10,100, 1000, 10000, 100000};
    const int M = 10;

    std::cout << std::left << std::setw(20) << "Number of Steps (N)"
    << std::setw(20) << "Trial Number (M)"
    << std::setw(20) << "Final Position (D)"
    << std::setw(20) << "Time Taken in ms (T)" << "\n";

    for (int N : nValues)
    {
        for  (int i = 1; i <= M; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            int finalPosition = randomWalk(N, rand);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            std::cout << std::setw(20) << N
            << std::setw(20) << i
            << std::setw(20) << finalPosition
            << std::setw(20) << std::fixed << std::setprecision(5) << duration.count() << "\n";
        }
    }
    return 0;
}