#include <stdio.h>
#include <stdlib.h>
#include "book.h"

#define p() (3*3)

const int val = p() * p();

void loop(unsigned int times, void (*callback)()) {
	unsigned int i;
	for (i = 0; i < times; i++) {
		callback();
	}
}

int main(void) {
	printf("-->%d<----\n", val);
	book* my_book = book_new();
	my_book->name = "Harry Potter";
	char* name = my_book->name; // name has my_book-> name address
	book_read(my_book);
	book_free(my_book);
	// name still has my_book-> name address, will be freed by the c runtime when exit this main scope
	return system("pause");
}