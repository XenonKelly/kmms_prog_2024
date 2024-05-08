#include <gtest/gtest.h>
#include "vector.hpp"

using namespace KLikhosherstova;

TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, PushBack) {
    Vector<int> vec;
    vec.push_back(34);
    vec.push_back(38);
    vec.push_back(63);
    vec.push_back(125);
    vec.push_back(34);
    vec.push_back(30);
    vec.push_back(45);
    vec.push_back(65);
    vec.push_back(83);
    vec.push_back(9);
    vec.push_back(6);
    vec.push_back(1);
    EXPECT_EQ(vec.size(), 12);
    ASSERT_FALSE(vec.size() == 3);
}

TEST(VectorTest, HasItem) {
    Vector<int> vec;
    EXPECT_FALSE(vec.has_item(5));
    vec.push_back(78);
    vec.push_back(65);
    vec.push_back(5);
    vec.push_back(45);
    vec.push_back(65);
    vec.push_back(83);
    EXPECT_TRUE(vec.has_item(5));
    EXPECT_FALSE(vec.has_item(91));
}

TEST(VectorTest, Insert) {
    Vector<int> vec;
    vec.push_back(78);
    vec.push_back(65);
    vec.push_back(5);
    vec.push_back(83);
    EXPECT_EQ(vec.size(), 4);
    vec.insert(2, 45);
    vec.insert(2, 51);
    EXPECT_TRUE(vec.has_item(45));
    EXPECT_EQ(vec.size(), 6);
    EXPECT_TRUE(vec.insert(7, 87));
    EXPECT_FALSE(vec.insert(10, 90));
}

TEST(VectorTest, RemoveFirst) {
    Vector<int> vec;
    vec.push_back(78);
    vec.push_back(65);
    vec.push_back(5);
    vec.push_back(83);
    EXPECT_TRUE(vec.remove_first(65));
    EXPECT_EQ(vec.size(), 3);
    EXPECT_FALSE(vec.remove_first(28));
}
