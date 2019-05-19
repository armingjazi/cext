#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include <include/gmock/gmock.h>
#include <include/gtest/gtest.h>

#include <Stack.h>

using namespace testing;

namespace all {
class UnitTest_Stack : public testing::Test {
 public:
  void SetUp() override {

  }

  void TearDown() override {

  }
};
TEST_F(UnitTest_Stack, pushes_top_one_element_of_type_float) {
  Stack<float> stack(1);
  stack.push(34.5f);
  EXPECT_EQ(34.5f, stack.top());
}

TEST_F(UnitTest_Stack, pushes_multiple_floats_top_one_element) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);
  EXPECT_EQ(333.1f, stack.top());
}

TEST_F(UnitTest_Stack, pushes_multiple_floats_top_multiple_elements) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);
  EXPECT_EQ(333.1f, stack.top());
  stack.pop();
  EXPECT_EQ(34.5f, stack.top());
}

TEST_F(UnitTest_Stack, pushes_more_than_capacity_of_stack) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);
  stack.push(33.1f);

  EXPECT_EQ(33.1f, stack.top());
  stack.pop();
  EXPECT_EQ(333.1f, stack.top());
  stack.pop();
  EXPECT_EQ(34.5f, stack.top());
}

TEST_F(UnitTest_Stack, copies_stack) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);

  Stack<float> stackCopy(stack);
  EXPECT_EQ(333.1f, stackCopy.top());
  stackCopy.pop();
  EXPECT_EQ(34.5f, stackCopy.top());
}

TEST_F(UnitTest_Stack, assigns_stack) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);

  Stack<float> stackAssignment(4);
  stackAssignment = stack;

  EXPECT_EQ(333.1f, stackAssignment.top());
  stackAssignment.pop();
  EXPECT_EQ(34.5f, stackAssignment.top());
}

TEST_F(UnitTest_Stack, count) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);
  EXPECT_EQ(2, stack.count());
}

TEST_F(UnitTest_Stack, pop_more_than_push) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);

  stack.pop();
  stack.pop();
  EXPECT_THROW(stack.pop(), std::runtime_error);
}
}

#pragma clang diagnostic pop