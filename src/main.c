#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main(void) {
	struct book* my_book = book_new();
	my_book->id = 1;
	my_book->name = "Harry Potter";
	my_book->content = "Once upon a time...";

	char* name = my_book->name; // name has my_book-> name address

	my_book->read(my_book);

	printf("------\n");

	my_book->read(my_book);

	book_free(my_book);
	// name still has my_book-> name address, will be freed by the c runtime when exit this main scope
	return system("pause");
}