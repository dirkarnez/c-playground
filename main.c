#include <stdio.h>

#define p() (9*9*9*9*9)

const int val = p() * p();

int main(void) {
	printf("-->%d<----\n", val);
	getchar();
	return 0;
}