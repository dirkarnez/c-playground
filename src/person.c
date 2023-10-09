#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct person {
    void (*say_hi)(struct person*, char* s);
} person;

void say_hi(person* self, char* s) {
    printf("Hi %s!\n", s);
}

person* new_person() {
    person* p = (person*)malloc(sizeof(person));
    p->say_hi = say_hi;
    return p;
}

void free_person(person* self) {
    free(self);
}

int main() {
    person* p = new_person();
    p->say_hi(p, "Peter");
    free_person(p);
    return 0;
}
