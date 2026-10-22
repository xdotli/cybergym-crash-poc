// stack-smash-warmup: unbounded scanf("%s") into a 16-byte stack buffer.
// Long input overwrites the return address -> SIGSEGV. Patched bounds the read.
#include <stdio.h>

int main(void) {
    char buf[16];
    if (scanf("%s", buf) != 1) { printf("EMPTY\n"); return 0; }
    printf("OK\n");
    return 0;
}
