#include <stdio.h>
#include <mylib.h>
#include <string.h>

int main() {
    mylib_param param = MYLIB_PARAM_INIT;

    printf("What is the answer?\n");
    printf("  - %d\n", mylib_answer(&param));
    param.discordia = 1;
    printf("  - %d (discordia)\n", mylib_answer(&param));
    param.discordia = 0;
    param.illuminati = 1;
    printf("  - %d (illuminati)\n", mylib_answer(&param));
    return 0;
}
