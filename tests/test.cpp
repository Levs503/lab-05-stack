// Copyright 2020 Lev Semkov

#include <gtest/gtest.h>

#include "Stack1.h"

class doubleWord {
 public:
  std::string first;
  std::string second;
};

TEST(Stack, pushHeadPop) {
  Stack1<doubleWord> a;
  doubleWord f{"hello", "world"};
  a.push(f);
  a.push({"double", "float"});
  ASSERT_EQ(a.head().first, "double");
  ASSERT_EQ(a.head().second, "float");
  a.pop();
  ASSERT_EQ(a.head().first, "hello");
  ASSERT_EQ(a.head().second, "world");
}

class doubleWordNoCopy {
 public:
  std::string first;
  std::string second;
  doubleWordNoCopy(std::string a, std::string b)
      : first(std::move(a)), second(std::move(b)) {}
  doubleWordNoCopy(const doubleWordNoCopy&) = delete;
  doubleWordNoCopy(doubleWordNoCopy&& a)
      : first(std::move(a.first)), second(std::move(a.second)) {}
};

TEST(Stack, pushHeadPopNoCopy) {
  doubleWordNoCopy b("hello", "world");
  Stack1<doubleWordNoCopy> a;
  a.push(std::move(b));
  a.push_emplace("double", "float");
  ASSERT_EQ(a.head().first, "double");
  ASSERT_EQ(a.head().second, "float");
  a.pop();
  ASSERT_EQ(a.head().first, "hello");
  ASSERT_EQ(a.head().second, "world");
  a.pop();
  ASSERT_THROW(a.pop(), std::out_of_range);
  ASSERT_THROW(a.head(), std::out_of_range);
}

TEST(Stack, MoveStack) {
  Stack1<doubleWord> b;
  doubleWord f{"hello", "world"};
  b.push(f);
  b.push({"double", "float"});
  Stack1<doubleWord> a(std::move(b));
  ASSERT_THROW(b.pop(), std::out_of_range);
  ASSERT_THROW(b.head(), std::out_of_range);
  ASSERT_EQ(a.head().first, "double");
  ASSERT_EQ(a.head().second, "float");
  a.pop();
  ASSERT_EQ(a.head().first, "hello");
  ASSERT_EQ(a.head().second, "world");
  a.pop();
  ASSERT_THROW(a.pop(), std::out_of_range);
  ASSERT_THROW(a.head(), std::out_of_range);
}
