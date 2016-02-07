#include <gtest/gtest.h>
#include "../vec.hpp"


TEST(at, default) {
    Vec<int, 3> v = {1, 2, 3};
    EXPECT_EQ(v.at<1>(), 2);
    EXPECT_EQ(v.at<2>(), 3);
}

TEST(set, default) {
    Vec<int, 3> v = {1, 2, 3};
    v.set<1>(4);
    EXPECT_EQ(v.at<1>(), 4);
}

TEST(append, success) {
    Vec<char, 3> v1 = {'a', 'b', 'c'};
    Vec<char, 2> v2 = {'d', 'e'};
    auto v3 =  v1.append(v2);
    EXPECT_EQ(v3.at<0>(), 'a');
    EXPECT_EQ(v3.at<4>(), 'e');
}

TEST(zipWith, default) {
    Vec<int, 3> v1 = {1, 2, 3};
    Vec<int, 3> v2 = {1, 2, 3};
    std::function<int(int,int)> fun = [](int a, int b) { return a * b; };
    auto v3 =  v1.zipWith(v2, fun);
    Vec<int, 3> v4 = {1, 4, 9};
    EXPECT_EQ(v3, v4);
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
