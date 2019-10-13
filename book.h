#pragma once

typedef struct book {
	char* name;
	char* content;
} book;

book* book_new(void);
void book_free(book* self);
void book_read(book* self);