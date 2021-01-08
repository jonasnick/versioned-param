#include "include/mylib.h"
#include <stdlib.h>
#include <string.h>

static int copy_versioned_struct_from_user(void *dst, size_t dstsize, const void *src, size_t srcsize)
{
    size_t size = dstsize < srcsize ? dstsize : srcsize; /* min */
    size_t rest = (dstsize > srcsize ? dstsize : srcsize)  /* max */
                  - size;

    /* Deal with trailing bytes. */
    if (srcsize < dstsize) {
        memset(dst + size, 0, rest);
    } else if (srcsize > dstsize) {
        size_t i;
        for (i = 0; i < rest; i++) {
            if (*((unsigned char *)src + size + i) != 0) {
                return 0;
            }
        }
    }
    /* Copy the interoperable parts of the struct. */
    memcpy(dst, src, size);
    return 1;
}

static int copy_param(mylib_param *param, mylib_param *uparam) {
    memset(param, 0, sizeof(*param));

    return copy_versioned_struct_from_user(param, sizeof(*param), uparam, uparam->size);
}

int mylib_answer(mylib_param *uparam) {
    mylib_param param;

    if (memcmp(uparam->magic, MYLIB_CONFIG_MAGIC, sizeof(uparam->magic)) != 0) {
        return 0;
    }

    if (!copy_param(&param, uparam)) {
        return 0;
    }
    if (param.discordia) {
        return 5;
    }
    return 42;
}
