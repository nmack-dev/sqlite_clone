#include "InputHandler.h"

#include <iostream>
#include <string.h>

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
        
        char* keyword = strtok(const_cast<char*>(input.c_str()), " ");
        char* id_string = strtok(nullptr, " ");
        char* username = strtok(nullptr, " ");
        char* email = strtok(nullptr, " ");

        if (nullptr == id_string || nullptr == username || nullptr == email) {
            result = PREPARE_SYNTAX_ERROR;
        } else {
            int id = std::atoi(id_string);

            if (0 > id) {
                result = PREPARE_INVALID_ID;
            } else if (COLUMN_USERNAME_SIZE < strlen(username)) {
                result = PREPARE_STRING_TOO_LONG;
            } else if (COLUMN_EMAIL_SIZE < strlen(email)) {
                result = PREPARE_STRING_TOO_LONG;
            } else {
                statement.rowToInsert.id = (unsigned)id;
                strncpy(statement.rowToInsert.username, username, COLUMN_USERNAME_SIZE);
                strncpy(statement.rowToInsert.email, email, COLUMN_EMAIL_SIZE);
                
                result = PREPARE_SUCCESS;
            }
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
