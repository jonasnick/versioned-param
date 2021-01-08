#include <stdlib.h>

typedef struct {
    size_t size;
    int discordia;
} mylib_param;

#define MYLIB_CONFIG_INIT { sizeof(mylib_param) };

int mylib_answer(mylib_param *uparam);
