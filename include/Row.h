#ifndef _ROW_
#define _ROW_

#define COLUMN_ID_SIZE 4
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define ROW_SIZE 291 // COLUMN_ID_SIZE + COLUMN_USERNAME_SIZE + COLUMN_EMAIL_SIZE

typedef struct
{
    unsigned int id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
} Row;

#endif // _ROW_