#include "Pager.h"

int Pager::Open(std::string fileName)
{
    int fd = open(fileName.c_str(), O_RDWR | O_CREAT, S_IWUSR | S_IRUSR);

    fileLength = lseek(fd, 0, SEEK_END);
    fileDescriptor = fd;

    for (unsigned int i = 0; i < TABLE_MAX_PAGES, i++) {
        pages[i] == nullptr;
    }

    return fd;
}

void* Pager::GetPage(uint32_t pageNumber)
{
    if (pageNumber > TABLE_MAX_PAGES) {
        return nullptr;
    }

    if (nullptr == pages[pageNumber]) {
        void* page = malloc(PAGE_SIZE);
        uint32_t numPages = fileLength / PAGE_SIZE;

        if (fileLength % PAGE_SIZE) {
            numPages++;
        }

        if (pageNumber <= numPages) {
            lseek(fileDescriptor, pageNumber * PAGE_SIZE);
            ssize_t bytesRead = read(fileDescriptor, page, PAGE_SIZE);
            
        }
    }

}

void Pager::Flush(uint32_t pageNumber, size_t flushSize)
{

}