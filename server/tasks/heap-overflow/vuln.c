// heap-overflow: up to 4096 bytes are read into a 16-byte heap block; freeing
// the corrupted chunk aborts in glibc (SIGABRT). Patched allocates 4096.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *dst = malloc(16);
    size_t n = fread(dst, 1, 4096, stdin);
    (void)n;
    free(dst);
    printf("OK\n");
    return 0;
}
