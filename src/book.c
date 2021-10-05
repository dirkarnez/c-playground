#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "book.h"

// undefined in book.h on purpose
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

// From https://stackoverflow.com/questions/351733/how-would-one-write-object-oriented-code-in-c
//
// struct Animal_Vtable{
//     typedef void (*Walk_Fun)(struct Animal *a_This);
//     typedef struct Animal * (*Dtor_Fun)(struct Animal *a_This);

//     Walk_Fun Walk;
//     Dtor_Fun Dtor;
// };

// struct Animal{
//     Animal_Vtable vtable;

//     char *Name;
// };

// struct Dog{
//     Animal_Vtable vtable;

//     char *Name; // Mirror member variables for easy access
//     char *Type;
// };

// void Animal_Walk(struct Animal *a_This){
//     printf("Animal (%s) walking\n", a_This->Name);
// }

// struct Animal* Animal_Dtor(struct Animal *a_This){
//     printf("animal::dtor\n");
//     return a_This;
// }

// Animal *Animal_Alloc(){
//     return (Animal*)malloc(sizeof(Animal));
// }

// Animal *Animal_New(Animal *a_Animal){
//     a_Animal->vtable.Walk = Animal_Walk;
//     a_Animal->vtable.Dtor = Animal_Dtor;
//     a_Animal->Name = "Anonymous";
//     return a_Animal;
// }

// void Animal_Free(Animal *a_This){
//     a_This->vtable.Dtor(a_This);

//     free(a_This);
// }

// void Dog_Walk(struct Dog *a_This){
//     printf("Dog walking %s (%s)\n", a_This->Type, a_This->Name);
// }

// Dog* Dog_Dtor(struct Dog *a_This){
//     // Explicit call to parent destructor
//     Animal_Dtor((Animal*)a_This);

//     printf("dog::dtor\n");

//     return a_This;
// }

// Dog *Dog_Alloc(){
//     return (Dog*)malloc(sizeof(Dog));
// }

// Dog *Dog_New(Dog *a_Dog){
//     // Explict call to parent constructor
//     Animal_New((Animal*)a_Dog);

//     a_Dog->Type = "Dog type";
//     a_Dog->vtable.Walk = (Animal_Vtable::Walk_Fun) Dog_Walk;
//     a_Dog->vtable.Dtor = (Animal_Vtable::Dtor_Fun) Dog_Dtor;

//     return a_Dog;
// }

// int main(int argc, char **argv){
//     /*
//       Base class:

//         Animal *a_Animal = Animal_New(Animal_Alloc());
//     */
//     Animal *a_Animal = (Animal*)Dog_New(Dog_Alloc());

//     a_Animal->vtable.Walk(a_Animal);

//     Animal_Free(a_Animal);
// }