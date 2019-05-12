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
TEST_F(UnitTest_Stack, pushes_pops_one_element_of_type_float) {
  Stack<float> stack(1);
  stack.push(34.5f);
  EXPECT_EQ(34.5f, stack.pop());
}

TEST_F(UnitTest_Stack, pushes_multiple_floats_pops_one_element) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);
  EXPECT_EQ(333.1f, stack.pop());
}

TEST_F(UnitTest_Stack, pushes_multiple_floats_pops_multiple_elements) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);
  EXPECT_EQ(333.1f, stack.pop());
  EXPECT_EQ(34.5f, stack.pop());
}

TEST_F(UnitTest_Stack, pushes_more_than_capacity_of_stack_should_throws_exception) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);
  EXPECT_THROW(stack.push(333.1f), std::runtime_error);
}

TEST_F(UnitTest_Stack, copies_stack) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);

  Stack<float> stackCopy(stack);
  EXPECT_EQ(333.1f, stackCopy.pop());
  EXPECT_EQ(34.5f, stackCopy.pop());
}

TEST_F(UnitTest_Stack, assigns_stack) {
  Stack<float> stack(2);
  stack.push(34.5f);
  stack.push(333.1f);

  Stack<float> stackAssignment(4);
  stackAssignment = stack;

  EXPECT_EQ(333.1f, stackAssignment.pop());
  EXPECT_EQ(34.5f, stackAssignment.pop());
}
}
