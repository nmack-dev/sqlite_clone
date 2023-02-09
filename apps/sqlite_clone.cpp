#include <string>
#include <iostream>

#include "InputHandler.h"

int main()
{
    Table* table = new Table();
    std::string input_string;

    while (true) {
        std::cout << "db > ";
        std::getline(std::cin, input_string);

        if (InputHandler::IsMetaCommand(input_string)) {
            switch (InputHandler::DoMetaCommand(input_string)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED:
                    std::cout << "Unrecognized command " << input_string << '.' << std::endl;
                    continue;
            }
        } else {
            Statement statement;

            switch (InputHandler::PrepareStatement(input_string, statement)) {
                case PREPARE_SUCCESS:
                    break;
                case PREPARE_SYNTAX_ERROR:
                    std::cout << "Statement Syntax Error: " << input_string << '.' << std::endl;
                    continue;
                case PREPARE_UNRECOGNIZED_STATEMENT:
                    std::cout << "Unrecognized keyword: " << input_string << '.' << std::endl;
                    continue;
            }

            // TODO: Handle InputHanlder failure cases during statement execution
            switch (statement.type) {
                case STATEMENT_INSERT:
                    InputHandler::ExecuteInsert(statement, table);
                    break;
                case STATEMENT_SELECT:
                    InputHandler::ExecuteSelect(statement, table);
                    break;
            }
        }
    }

    return 0;
}
