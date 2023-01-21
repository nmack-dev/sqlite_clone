#include <gtest/gtest.h>

#include "ReplExecutor.h"

class ReplExecutorTest : public ::testing::Test 
{
protected:
    ReplExecutorTest()
    {
        ReplExecutor repl = new ReplExecutor();
    }

    ~ReplExecutorTest()
    {
        delete repl;
    }
}

TEST(ReplExecutorTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}