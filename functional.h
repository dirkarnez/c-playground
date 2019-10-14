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