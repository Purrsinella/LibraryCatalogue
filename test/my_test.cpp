#include <gtest/gtest.h>

TEST(FirstTry, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 7, 49);

}