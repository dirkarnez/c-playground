#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "book.h"

book* book_new(void) {
	book* out = new(book);
	if (out == NULL)
	{
		puts("Some kind of malloc() error");
		exit(1);
	}
	out->id = 0;
	out->name = NULL;
	out->content = NULL;
	return out;
}

void book_free(book* self) {
	if (self == NULL) {
		return;
	}

	free(self);
}

void book_read(book* self) {
	printf("Book id: %d, name: %s, content: %s\n", 
		self->id,
		(self->name ? self->name : "No name"), 
		(self->content ? self->content : "No content")
	);
}