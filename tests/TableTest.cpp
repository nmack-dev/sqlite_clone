#include "Table.h"
#include "Row.h"
#include "gtest/gtest.h"

#include <string>
#include <cstring>
#include <iostream>

class TableTest : public ::testing::Test 
{
protected:
    Table* table;

    TableTest() 
    {
        table = new Table();
    }

    ~TableTest() override 
    {
        delete table;
    }
};

TEST_F(TableTest, AddGetRow)
{
    Row newRow = {1, "testUsername", "testEmail@test.com"};
    Row returnRow;
    
    table->AddRow(newRow);
    table->GetRow(0, returnRow);

    EXPECT_EQ(1, returnRow.id);
    EXPECT_TRUE(0 == std::strcmp("testUsername", returnRow.username));
    EXPECT_TRUE(0 == std::strcmp("testEmail@test.com", returnRow.email));
}