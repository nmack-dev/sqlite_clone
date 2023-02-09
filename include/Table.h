#ifndef _TABLE_
#define _TABLE_

#include "Row.h"

#include <stdint.h>

#define PAGE_SIZE 4096
#define TABLE_MAX_PAGES 100

const unsigned int rowsPerPage = PAGE_SIZE / ROW_SIZE;
const unsigned int tableMaxRows = rowsPerPage * TABLE_MAX_PAGES;

typedef struct 
{
    unsigned int numRows;
    void* pages[TABLE_MAX_PAGES];
} TableStructure;

class Table
{
public:
    Table();
    ~Table();

    void AddRow(Row& source);
    void GetRow(unsigned int rowNum, Row& destination);

    unsigned int GetRowNum();

protected:
    void* rowSlot(unsigned int rowNum);

private:
    TableStructure* tableStructure;
};

#endif // _TABLE_