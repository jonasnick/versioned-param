#include <stdlib.h>

typedef struct {
    unsigned char magic[4];
    size_t size;
    int discordia;
} mylib_param;

#define MYLIB_CONFIG_MAGIC "\x3F\x2F\x8B\x7C"
#define MYLIB_CONFIG_INIT { MYLIB_CONFIG_MAGIC, sizeof(mylib_param) };

int mylib_answer(mylib_param *uparam);
