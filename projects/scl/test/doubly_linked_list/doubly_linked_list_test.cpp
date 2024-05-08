#include <gtest/gtest.h>
#include "doubly_linked_list.hpp"

using namespace KLikhosherstova;

TEST(DoublyLinkedListTest, DefaultConstructor) {
    DoublyLinkedList<int> dll;
    EXPECT_EQ(dll.size(), 0);
}

TEST(DoublyLinkedListTest, PushBack) {
    DoublyLinkedList<int> dll;
    dll.push_back(5);
    dll.push_back(7);
    dll.push_back(13);
    ASSERT_TRUE(dll.size() == 3);
}

TEST(DoublyLinkedListTest, HasItem) {
    DoublyLinkedList<int> dll;
    dll.push_back(16);
    dll.push_back(3);
    dll.push_back(54);
    dll.push_back(230);
    dll.push_back(12);
    EXPECT_TRUE(dll.has_item(54));
    EXPECT_FALSE(dll.has_item(200));
}

TEST(DoublyLinkedListTest, RemoveFirst) {
    DoublyLinkedList<int> dll;
    dll.push_back(54);
    dll.push_back(192);
    dll.push_back(10);
    dll.remove_first(192);
    EXPECT_EQ(dll.size(), 2);
    EXPECT_FALSE(dll.remove_first(190));
}