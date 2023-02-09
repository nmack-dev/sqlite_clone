#include "InputHandler.h"

#include <iostream>

MetaCommandResult InputHandler::DoMetaCommand(std::string& metaCommand)
{
    if (0 == metaCommand.compare(".exit")) {
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED;
    }
}

PrepareResult InputHandler::PrepareStatement(std::string& input, Statement& statement)
{
    PrepareResult result = PREPARE_FAILURE;

    if (0 == input.compare(0, 6, "insert")) {
        statement.type = STATEMENT_INSERT;
        
        int args = sscanf(
            input.c_str(), "insert %u %s %s", 
            &statement.rowToInsert.id,
            statement.rowToInsert.username,
            statement.rowToInsert.email
        );

        if (args < 3) {
            result = PREPARE_SYNTAX_ERROR;
        } else {
            result = PREPARE_SUCCESS;
        }
    } else if (0 == input.compare("select")) {
        statement.type = STATEMENT_SELECT;
        result = PREPARE_SUCCESS;
    } else {
        result = PREPARE_UNRECOGNIZED_STATEMENT;
    }

    return result;
}

bool InputHandler::IsMetaCommand(std::string& input)
{
    return '.' == input.at(0);
}

StatementResult InputHandler::ExecuteInsert(Statement& statement, Table* table)
{
    StatementResult result = EXECUTE_FAILURE;

    if (STATEMENT_INSERT == statement.type) {
        if (table->GetRowNum() >= tableMaxRows) {
            result = EXECUTE_TABLE_FULL;
        } else {
            table->AddRow(statement.rowToInsert);
            result = EXECUTE_SUCCESS;
        }
    }

    return result;
}

StatementResult InputHandler::ExecuteSelect(Statement& statement, Table* table)
{
    StatementResult result = EXECUTE_FAILURE;

    if (STATEMENT_SELECT == statement.type) {
        Row tempRow;

        for (unsigned int i = 0; i < table->GetRowNum(); i++) {
            table->GetRow(i, tempRow);

            std::cout << tempRow.id << ' ' << tempRow.username << ' ' << tempRow.email << std::endl;
        }

        result = EXECUTE_SUCCESS;
    }

    return result;
}
