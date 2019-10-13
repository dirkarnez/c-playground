#pragma once
#include "memory.h"

typedef_entity_struct(book, struct {
	char* name;
	char* content;
});

book* book_new(void);
void book_free(book* self);
void book_read(book* self);