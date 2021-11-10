#include <stdio.h>

#define ADD 0
#define MINUS 1

#define add(a, b) ((a) + (b))
#define minus(a, b) ((a) - (b))

#define compile_time_if(y, a, b) ((y == ADD) ? (add(a, b)) : (y == MINUS) ? (minus(a, b)) : -1) // should do compile time exception

/* usage
int main() {
    printf("ADD -> %d", compile_time_if(ADD, 9, 8)); // 17 assembly immediate value
    printf("MINUS ->%d", compile_time_if(MINUS, 9, 8)); // 1 assembly immediate value
    return 0;
}
*/
