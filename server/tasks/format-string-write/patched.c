// format-string-write (patched): the input is printed as data.
#include <stdio.h>

int main(void) {
    char msg[256];
    if (!fgets(msg, sizeof msg, stdin)) { printf("EMPTY\n"); return 0; }
    printf("%s", msg);
    printf("OK\n");
    return 0;
}
