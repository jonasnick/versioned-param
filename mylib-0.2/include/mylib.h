#include <stdlib.h>

typedef struct {
    /* magic allows checking if the struct is initialized */
    unsigned char magic[4];
    size_t size;
    int discordia;
    /* dummy is required to distinguish between this param and previous
     * versions' param */
    int dummy;
    int illuminati;
} mylib_param;

#define MYLIB_CONFIG_MAGIC "\x3F\x2F\x8B\x7C"
#define MYLIB_CONFIG_INIT { MYLIB_CONFIG_MAGIC, sizeof(mylib_param) };

int mylib_answer(mylib_param *uparam);
