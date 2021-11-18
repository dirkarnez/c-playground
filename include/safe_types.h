#include <stdio.h>

typedef struct {
    int value;
} Param;

const Param param1 = { .value = 7 };

int doStuff(Param param) {
    printf("%d", param.value);
}

int doStuff_unsafe(int param) {
    printf("%d", param);
}

int main() {
    doStuff(param1);
    doStuff_unsafe(7);
   return 0;
}
