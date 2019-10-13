#include <stdio.h>
#include <stdlib.h>
#include "book.h"

book* book_new(void) {
	book* out = malloc(sizeof(book));
	if (out == NULL)
	{
		puts("Some kind of malloc() error");
		exit(1);
	}
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
	printf("Book name: %s, content: %s\n", 
		(self->name ? self->name : "No name"), 
		(self->content ? self->content : "No content")
	);
}