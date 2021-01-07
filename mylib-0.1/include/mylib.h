typedef struct {
    unsigned char magic[8];
} mylib_config;

#define MYLIB_CONFIG_INIT { "versio1" };

int mylib_answer(mylib_config *config);
