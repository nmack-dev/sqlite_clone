#include "ReplExecutor.h"

#include <iostream>
#include <string>
#include <thread>

void ReplExecutor::replThread()
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

int ReplExecutor::Run()
{
    std::thread replThread(ReplExecutor::replThread);
    
    std::thread::id threadId = replThread.get_id();
    std::thread::id nobody;
    
    replThread.detach();

    if (nobody != threadId) {
        return 1;
    }

    return 0;
}