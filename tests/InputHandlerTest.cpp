#include "InputHandler.h"
#include "gtest/gtest.h"

#include <string>

class InputHandlerTest : public ::testing::Test 
{
protected:

    InputHandlerTest() 
    {
    }

    ~InputHandlerTest() override 
    {
    }
};

TEST(InputHandlerTest, DoMetaCommandUnrecognized)
{
    std::string metaCommand = "unrecognized";
    EXPECT_EQ(META_COMMAND_UNRECOGNIZED, InputHandler::DoMetaCommand(metaCommand));
}

TEST(InputHandlerTest, DetectMetaCommand)
{
    std::string input = ".exit";
    EXPECT_TRUE(InputHandler::IsMetaCommand(input));

    input = "exit";
    EXPECT_FALSE(InputHandler::IsMetaCommand(input));
}

TEST(InputHandlerTest, PrepareStatementInsert) 
{
    std::string input = "insert 1 test test@test.com";
    Statement statement;
    EXPECT_EQ(PREPARE_SUCCESS, InputHandler::PrepareStatement(input, statement));
    EXPECT_EQ(STATEMENT_INSERT, statement.type);
}

TEST(InputHandlerTest, PrepareStatementSelect) 
{
    std::string input = "select";
    Statement statement;
    EXPECT_EQ(PREPARE_SUCCESS, InputHandler::PrepareStatement(input, statement));
    EXPECT_EQ(STATEMENT_SELECT, statement.type);
}

TEST(InputHandlerTest, PrepareStatementUnrecognized)
{
    std::string input = "unrecognized";
    Statement statement;
    EXPECT_EQ(PREPARE_UNRECOGNIZED_STATEMENT,  InputHandler::PrepareStatement(input, statement));
}

TEST(InputHandlerTest, PrepareStatementSyntaxError)
{
    std::string input = "insert 0";
    Statement statement;
    EXPECT_EQ(PREPARE_SYNTAX_ERROR,  InputHandler::PrepareStatement(input, statement));
}

TEST(InputHandlerTest, ExecuteInsert)
{
    Row row = {1, "testUser", "testUser@test.com"};
    Statement statement = {STATEMENT_INSERT, row};

    Table* table = new Table();

    EXPECT_EQ(EXECUTE_SUCCESS, InputHandler::ExecuteInsert(statement, table));

    statement.type = STATEMENT_SELECT;
    EXPECT_EQ(EXECUTE_FAILURE, InputHandler::ExecuteInsert(statement, table));
}

TEST(InputHandlerTest, ExecuteSelect)
{
    Row row = {1, "testUser", "testUser@test.com"};
    Statement statement = {STATEMENT_SELECT, row};

    Table* table = new Table();

    EXPECT_EQ(EXECUTE_SUCCESS, InputHandler::ExecuteSelect(statement, table));

    statement.type = STATEMENT_INSERT;
    EXPECT_EQ(EXECUTE_FAILURE, InputHandler::ExecuteSelect(statement, table));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
