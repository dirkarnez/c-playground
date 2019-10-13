#pragma once

#define typedef_entity_struct(type_name, anonymous_struct) \
typedef struct {                         \
	int id; \
    anonymous_struct;                  \
} type_name;

#define new(type) (malloc(sizeof(type)))