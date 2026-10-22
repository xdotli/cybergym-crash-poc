// heap-overflow (patched): the buffer matches what is read.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *dst = malloc(4096);
    size_t n = fread(dst, 1, 4096, stdin);
    (void)n;
    free(dst);
    printf("OK\n");
    return 0;
}
