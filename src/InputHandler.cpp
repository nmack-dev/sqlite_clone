#include "InputHandler.h"

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
    if (0 == input.compare("insert")) {
        statement.type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    } else if (0 == input.compare("select")) {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    } else {
        return PREPARE_UNRECOGNIZED_STATEMENT;
    }
}

bool InputHandler::IsMetaCommand(std::string& input)
{
    return '.' == input.at(0);
}