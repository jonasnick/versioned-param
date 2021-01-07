#include "include/mylib.h"

const size_t MYLIB_CONFIG_SIZE = sizeof(mylib_config);

int mylib_answer(mylib_config *config) {
    if (config->discordia) {
        return 5;
    }
    return 42;
}
