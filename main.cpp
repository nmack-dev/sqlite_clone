#include <iostream>
#include <string>
#include <thread>

void ReplExecutor()
{
    std::string input;
    
    while (true) {
    	std::cout << "db > ";
	std::cin >> input;

	if (0 == input.compare(".exit")) {
	    exit(EXIT_SUCCESS);
	} else {
	    std::cout << "Unrecognized command " << input << '.' << std::endl;
	}
    }
}

int main()
{
    std::thread ReplThread(ReplExecutor);
    ReplThread.join();

    return 0;
}
