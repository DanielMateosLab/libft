
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

extern "C" {
#include "libft.h"
}

class QuickSortTest : public ::testing::TestWithParam<std::vector<int>> {
protected:
    std::vector<int> input_array;
    std::vector<int> expected_sorted;

    void SetUp() override {
        input_array = GetParam();
        expected_sorted = input_array;
        std::sort(expected_sorted.begin(), expected_sorted.end());
    }
};

TEST_P(QuickSortTest, SortsCorrectly) {
    // Create a copy of the input array as a C array
    std::vector<int> c_array = input_array;
    size_t size = c_array.size();
    if (size > 0) {
        ft_quick_sort(c_array.data(), 0, static_cast<int>(size) - 1);
    }

    // Check if the array is sorted correctly
    ASSERT_EQ(c_array.size(), expected_sorted.size());
    for (size_t i = 0; i < c_array.size(); ++i) {
        EXPECT_EQ(c_array[i], expected_sorted[i]);
    }
}

INSTANTIATE_TEST_SUITE_P(
    QuickSortTests,
    QuickSortTest,
    ::testing::Values(
        std::vector<int>{},                       // Empty array
        std::vector<int>{1},                      // Single element
        std::vector<int>{2, 1},                   // Two elements
        std::vector<int>{3, 1, 2},                // Odd number of elements
        std::vector<int>{5, -1, 3, 2, 4},         // Mixed positive and negative
        std::vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1} // Reverse sorted
    )
);

TEST(QuickSortTest, ReverseOrder) {
    std::vector<int> input_array = {1, 2, 3, 4, 5};
    std::vector<int> expected_sorted = {5, 4, 3, 2, 1};

    ft_reverse_order(input_array.data(), 0, static_cast<int>(input_array.size()) - 1);

    ASSERT_EQ(input_array.size(), expected_sorted.size());
    for (size_t i = 0; i < input_array.size(); ++i) {
        EXPECT_EQ(input_array[i], expected_sorted[i]);
    }
}
