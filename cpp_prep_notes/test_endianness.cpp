#include <cstdio>
#include <cstdlib>

const int i = 1;
#define is_bigendian() ( (*(char*)&i) == 0 )

int main(void) {
    int val;
    char *ptr;
    ptr = (char*) &val;
    val = 0x12345678;
    if (is_bigendian()) {
        printf("big endian\n");
        printf("%X.%X.%X.%X\n", ptr[0], ptr[1], ptr[2], ptr[3]);
    } else {
        printf("little endian\n");
        printf("%X.%X.%X.%X\n", ptr[3], ptr[2], ptr[1], ptr[0]);
    }
    exit(0);
}
