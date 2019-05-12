#include <include/gmock/gmock.h>
#include <include/gtest/gtest.h>

#include <Library.h>

using namespace testing;

namespace all {
class UnitTest_Library : public testing::Test {
 public:
  void SetUp() override {

  }

  void TearDown() override {

  }
};

TEST_F(UnitTest_Library, get_set_equal) {
  Library library;

  library.set(10);

  EXPECT_EQ(10, library.get());
}

TEST_F(UnitTest_Library, get_set_not_equal) {
  Library library;

  library.set(11);

  EXPECT_NE(10, library.get());
}
}
