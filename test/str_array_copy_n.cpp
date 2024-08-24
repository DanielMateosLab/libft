#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <cstring>

extern "C" {
#include "libft.h"
}

class StrArrayCopyNTest : public ::testing::TestWithParam<std::tuple<std::vector<std::string>, size_t>> {
protected:
    std::vector<char*> input_array;
    std::vector<char*> result_array;

    void SetUp() override {
        const auto& [strings, _] = GetParam();
        input_array = createStringArray(strings);
    }

    void TearDown() override {
        freeStringArray(input_array);
        freeStringArray(result_array);
    }

    std::vector<char*> createStringArray(const std::vector<std::string>& strings) {
        std::vector<char*> arr;
        arr.reserve(strings.size() + 1);
        for (const auto& str : strings) {
            arr.push_back(strdup(str.c_str()));
        }
        arr.push_back(nullptr);
        return arr;
    }

    void freeStringArray(std::vector<char*>& arr) {
        for (char* str : arr) {
            free(str);
        }
        arr.clear();
    }
};

TEST_P(StrArrayCopyNTest, CopyArrayNCorrectly) {
    const auto& [strings, n] = GetParam();

    char** result = str_array_copy_n(input_array.data(), n);
    ASSERT_NE(result, nullptr);

    // Convert result back to vector for easier management
    for (size_t i = 0; result[i] != nullptr; ++i) {
        result_array.push_back(result[i]);
    }
    result_array.push_back(nullptr);
    free(result);  // Free the array itself, but not its contents

    size_t expected_size = std::min(n, strings.size());
    EXPECT_EQ(result_array.size(), expected_size + 1);  // +1 for the NULL terminator

    for (size_t i = 0; i < expected_size; ++i) {
        ASSERT_NE(result_array[i], nullptr);
        EXPECT_STREQ(result_array[i], strings[i].c_str());
        EXPECT_NE(result_array[i], input_array[i]);  // Ensure deep copy
    }
    EXPECT_EQ(result_array[expected_size], nullptr);
}

INSTANTIATE_TEST_SUITE_P(
    VaryingArraySizesAndN,
    StrArrayCopyNTest,
    ::testing::Values(
        std::make_tuple(std::vector<std::string>{}, 0),  // Empty array, n = 0
        std::make_tuple(std::vector<std::string>{"Hello"}, 1),  // Single element, n = 1
        std::make_tuple(std::vector<std::string>{"Hello", "World"}, 1),  // Two elements, n = 1
        std::make_tuple(std::vector<std::string>{"Hello", "World"}, 2),  // Two elements, n = 2
        std::make_tuple(std::vector<std::string>{"One", "Two", "Three", "Four", "Five"}, 3),  // Multiple elements, n = 3
        std::make_tuple(std::vector<std::string>{"One", "Two", "Three"}, 5)  // n greater than array size
    )
);

TEST(StrArrayCopyNNullTest, CopyNullArray) {
    char** result = str_array_copy_n(NULL, 5);
    EXPECT_EQ(result, nullptr);
}

TEST(StrArrayCopyNZeroTest, CopyZeroElements) {
    const char* arr[] = {"Hello", "World", NULL};
    char** result = str_array_copy_n(const_cast<char**>(arr), 0);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], nullptr);
    free(result);
}
