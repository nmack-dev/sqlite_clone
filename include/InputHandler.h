#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

#include <string>

typedef enum 
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

typedef enum 
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum
{
    STATEMENT_INSERT, 
    STATEMENT_SELECT
} StatementType;

typedef struct {
    StatementType type;
} Statement;

class InputHandler
{
public:
    InputHandler() {}
    ~InputHandler() {}

    static MetaCommandResult DoMetaCommand(std::string& metaCommand);
    static PrepareResult PrepareStatement(std::string& input, Statement& statement);
    static bool IsMetaCommand(std::string& input);
};

#endif // __INPUTHANDLER_