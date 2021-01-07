typedef struct {
    unsigned char magic[8];
    int discordia;
} mylib_config;

#define MYLIB_CONFIG_INIT { "versio2", 0 };

int mylib_answer(mylib_config *config);
