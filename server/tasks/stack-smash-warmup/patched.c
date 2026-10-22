// stack-smash-warmup (patched): bounded read, same accepted behaviour.
#include <stdio.h>

int main(void) {
    char buf[16];
    if (scanf("%15s", buf) != 1) { printf("EMPTY\n"); return 0; }
    printf("OK\n");
    return 0;
}
