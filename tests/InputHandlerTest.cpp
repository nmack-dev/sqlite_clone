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

TEST(InputHandlerTest, PrepareStatementInsert) 
{
    std::string input = "insert";
    Statement statement;
    InputHandler::PrepareStatement(input, statement);
    EXPECT_EQ(STATEMENT_INSERT, statement.type);
}

TEST(InputHandlerTest, PrepareStatementSelect) 
{
    std::string input = "select";
    Statement statement;
    InputHandler::PrepareStatement(input, statement);
    EXPECT_EQ(STATEMENT_SELECT, statement.type);
}

TEST(InputHandlerTest, PrepareStatementUnrecognized)
{
    std::string input = "unrecognized";
    Statement statement;
    EXPECT_EQ(PREPARE_UNRECOGNIZED_STATEMENT,  InputHandler::PrepareStatement(input, statement));
}

TEST(InputHandlerTest, DetectMetaCommand)
{
    std::string input = ".exit";
    EXPECT_TRUE(InputHandler::IsMetaCommand(input));

    input = "exit";
    EXPECT_FALSE(InputHandler::IsMetaCommand(input));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
