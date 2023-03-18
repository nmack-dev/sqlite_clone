#include "Pager.h"
#include "Row.h"
#include "gtest/gtest.h"

#include <string>
#include <cstring>
#include <iostream>

class PagerTest : public ::testing::Test 
{
protected:
    Pager* pager;

    PagerTest() 
    {
        Pager = new pager();
    }

    ~PagerTest() override 
    {
        delete pager;
    }
};

TEST_F(PagerTest, PagerOpen)
{
    EXPECT_NE(-1, pager->Open("testFile"));
    EXPECT_NE(nullptr, pager->GetPage(1))
}