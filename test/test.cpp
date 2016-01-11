#include <gtest/gtest.h>
#include "../vec.hpp"


TEST(testAt, happy)
{
    Vec<int, 3> v = {1, 2, 3};
    EXPECT_EQ(v.at<1>(), 2);
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
