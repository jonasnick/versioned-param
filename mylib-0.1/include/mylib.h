#include <stdlib.h>

typedef struct {
    /* magic allows checking if the struct is initialized */
    unsigned char magic[4];
    size_t size;
    int discordia;
} mylib_param;

#define MYLIB_PARAM_MAGIC "\x3F\x2F\x8B\x7C"
#define MYLIB_PARAM_INIT { MYLIB_PARAM_MAGIC, sizeof(mylib_param) };

int mylib_answer(mylib_param *uparam);
