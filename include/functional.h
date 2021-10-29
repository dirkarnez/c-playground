#pragma once

#ifndef __GNUC__ 
#error Only GCC supports anonymous functions
#else
#define lambda(l_ret_type, l_arguments, l_body)       \
({                                                   \
	l_ret_type l_anonymous_functions_name l_arguments   \
	l_body                                              \
	&l_anonymous_functions_name;                        \
})
#endif 


/******************************/
// To simulate a callback and closure
int add1(int a, int b) {
    return a + b;
}

#define add2(a, b) ((a) + (b))
#define add3(x) ((x) + (temp))

#define pretent_to_have_a_callback(a, b) \
{ \
    int temp = a;  \
    temp++; \
    temp--; \
    /*callback in normal function */ \
    \
    int a_added_b = add1(temp, b); \
    \
     /* callback in #define function */ \
    int a_added_b_twice = add2(a_added_b, b); \
    \
     /* Closure */ \
    int a_added_b_twice_added_a = add3(a_added_b_twice); \
    return a_added_b_twice_added_a;\
} 

#include <stdio.h>

int main() {
	// Usage
	// 1 + 2 + 2 + 1
	// pretent_to_have_a_callback(1, 2);
    pretent_to_have_a_callback(7, 9);

    for (int i = 0; i < 10; i++) {
        int temp = 10;
        int ans = add3(i);
        printf("%d -> %d\n", i, ans);
        /*
            0 -> 10
            1 -> 11
            2 -> 12
            3 -> 13
            4 -> 14
            5 -> 15
            6 -> 16
            7 -> 17
            8 -> 18
            9 -> 19
        */
    }
}

/******************************/
