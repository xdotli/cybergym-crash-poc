// format-string-write: the input line is used directly as the printf format.
// A "%n"-heavy input writes through garbage pointers -> SIGSEGV.
// Patched passes the input as data, not as the format.
#include <stdio.h>

int main(void) {
    char msg[256];
    if (!fgets(msg, sizeof msg, stdin)) { printf("EMPTY\n"); return 0; }
    printf(msg);
    printf("OK\n");
    return 0;
}
