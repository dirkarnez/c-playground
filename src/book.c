#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "book.h"

void book_read(struct book* self) {
	self->read_count++;

	printf("Book id: %d\nname: %s\nread count: %d\ncontent: %s\n",
		self->id,
		(self->name ? self->name : "No name"),
		self->read_count,
		(self->content ? self->content : "No content")
	);
}

struct book* book_new(void) {
	struct book* out = new(struct book);
	if (out == NULL)
	{
		puts("Some kind of malloc() error");
		exit(1);
	}
	out->id = 0;
	out->name = NULL;
	out->content = NULL;
	out->read_count = 0;
	out->read = book_read;
	return out;
}

void book_free(struct book* self) {
	if (self == NULL) {
		return;
	}

	free(self);
}