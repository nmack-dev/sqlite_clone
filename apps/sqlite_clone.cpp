#include <string>
#include <iostream>

int main()
{
    std::string input_string;

    while (true) {
        std::cout << "db > ";
        std::cin >> input_string;

        if (0 == input_string.compare(".exit")) {
            exit(EXIT_SUCCESS);
        } else if (0 >= input_string.size()) {
            std::cout << "Error reading input";
            exit(EXIT_FAILURE);
        } else {
            std::cout << "Unrecognized command " << input_string << '.';
        }
    }

    return 0;
}
