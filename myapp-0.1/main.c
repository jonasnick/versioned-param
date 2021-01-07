#include <stdio.h>
#include <mylib.h>

int main() {
    mylib_config config = MYLIB_CONFIG_INIT;
    printf("%d\n", mylib_answer(&config));
    return 0;
}
