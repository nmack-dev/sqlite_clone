#include <gtest/gtest.h>
#include <ostream>
#include <iostream>

#include "ReplExecutor.h"

ReplExecutor* repl;

class ReplExecutorTest : public ::testing::Test 
{
protected:
    ReplExecutorTest()
    {
        repl = new ReplExecutor();
    }

    ~ReplExecutorTest()
    {
        delete repl;
    }
};

TEST(ReplExecutorTest, ReplExecutorReturns)
{
    EXPECT_EQ(repl->Run(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}