#include <include/gmock/gmock.h>
#include <include/gtest/gtest.h>

#include <AlignedCArray.h>

using namespace testing;

namespace all
{
    TEST(UnitTest_AlignedCArray, ctor_should_initialize_with_zeros)
    {
        AlignedCArray<float> array(10, 10);

        for (size_t i = 0; i < 10; ++i)
            for (size_t j = 0; j < 10; ++j)
                EXPECT_EQ(0.0, array[i][j]);
    }

    TEST(UnitTest_AlignedCArray, subscript_operator_should_set_get_correct_values)
    {
        AlignedCArray<float> array(10, 10);

        for (size_t i = 0; i < 10; ++i)
            for (size_t j = 0; j < 10; ++j)
                array[i][j] = static_cast<float>(i) * static_cast<float>(j);

        for (size_t i = 0; i < 10; ++i)
            for (size_t j = 0; j < 10; ++j)
                EXPECT_EQ(static_cast<float>(i) * static_cast<float>(j), array[i][j]);
    }
}
