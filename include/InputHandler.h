#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

#include <string>

#include "Table.h"

typedef enum 
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

typedef enum 
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
    PREPARE_SYNTAX_ERROR,
    PREPARE_FAILURE
} PrepareResult;

typedef enum
{
    STATEMENT_INSERT, 
    STATEMENT_SELECT
} StatementType;

typedef struct 
{
    StatementType type;
    Row rowToInsert;
} Statement;

typedef enum 
{
    EXECUTE_SUCCESS,
    EXECUTE_FAILURE,
    EXECUTE_TABLE_FULL
} StatementResult;

class InputHandler
{
public:
    InputHandler() {}
    ~InputHandler() {}

    static MetaCommandResult DoMetaCommand(std::string& metaCommand);
    static bool IsMetaCommand(std::string& input);
    
    static PrepareResult PrepareStatement(std::string& input, Statement& statement);

    static StatementResult ExecuteInsert(Statement& statement, Table* table);
    static StatementResult ExecuteSelect(Statement& statement, Table* table);
};

#endif // _INPUTHANDLER_