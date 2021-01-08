#include <stdlib.h>

typedef struct {
    size_t size;
    int discordia;
    /* dummy is required to distinguish between this param and previous
     * versions' param */
    int dummy;
    int illuminati;
} mylib_param;

#define MYLIB_CONFIG_INIT { sizeof(mylib_param) };

int mylib_answer(mylib_param *uparam);
