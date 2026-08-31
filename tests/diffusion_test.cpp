#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <random>

#include "../src/diffusion.hpp"

TEST_CASE("Random Walk Constraints") {
    std::random_device rd;
    std::mt19937 rand(rd());

    REQUIRE(std::abs(randomWalk(1, rand)) == 1);

    int N = 100;
    REQUIRE(std::abs(randomWalk(N, rand)) <= N);
}

TEST_CASE("Random Walk Benchmarks") {
    std::random_device rd;
    std::mt19937 rand(rd());

    BENCHMARK("randomWalk(10)") {
        return randomWalk(10, rand);
    };

    BENCHMARK("randomWalk(100)") {
        return randomWalk(100, rand);
    };

    BENCHMARK("randomWalk(1000)") {
        return randomWalk(1000, rand);
    };

    BENCHMARK("randomWalk(10000)") {
        return randomWalk(10000, rand);
    };

    BENCHMARK("randomWalk(100000)") {
        return randomWalk(100000, rand);
    };
}
