#ifndef _PAGER_
#define _PAGER_

#include <stdint.h>

#include "Table.h"


class Pager
{
public:
    Pager() {};
    ~Pager();

    /**
     * @brief Opens a file and sets a file descriptor.
     * 
     * @param fileName Name of file to open
     * @return int Open status
     */
    int Open(std::string fileName);
    
    /**
     * @brief Get the Page object
     * 
     * @param pageNumber 
     * @return void* 
     */
    void* GetPage(uint32_t pageNumber);
    
    /**
     * @brief 
     * 
     * @param pageNumber 
     * @param flushSize 
     */
    void Flush(uint32_t pageNumber, size_t flushSize);

private:
    int fileDescriptor;
    off_t fileLength;
    void* pages[TABLE_MAX_PAGES];
};

#endif // _PAGER_