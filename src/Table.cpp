#include "Table.h"

#include <cstdlib>
#include <cstring>

Table::Table()
{
    tableStructure = new TableStructure();
    tableStructure->numRows = 0;
}

Table::~Table()
{
    delete tableStructure;
}

void* Table::rowSlot(unsigned int rowNum) 
{
    unsigned int pageNum = rowNum / rowsPerPage;
    void* page = tableStructure->pages[pageNum];

    if (page == nullptr) {
        page = tableStructure->pages[pageNum] = malloc(PAGE_SIZE);
    }

    off_t rowOffset = rowNum % rowsPerPage;
    off_t byteOffset = rowOffset * ROW_SIZE;
    return page + byteOffset;
}

void Table::AddRow(Row& source)
{
    void* destination = rowSlot(tableStructure->numRows);
    tableStructure->numRows++;

    memcpy(destination, &source.id, COLUMN_ID_SIZE);
    memcpy(destination + COLUMN_ID_SIZE, source.username, COLUMN_USERNAME_SIZE);
    memcpy(destination + COLUMN_ID_SIZE + COLUMN_USERNAME_SIZE, source.email, COLUMN_EMAIL_SIZE);
}

void Table::GetRow(unsigned int rowNum, Row& destination)
{
    void* source = rowSlot(rowNum);

    memcpy(&destination.id, source, COLUMN_ID_SIZE);
    memcpy(destination.username, source + COLUMN_ID_SIZE, COLUMN_USERNAME_SIZE);
    memcpy(destination.email, source + COLUMN_ID_SIZE + COLUMN_USERNAME_SIZE, COLUMN_EMAIL_SIZE);
}