// null-pointer-write: with an input line of 4+ characters the program writes
// through a NULL pointer -> SIGSEGV. Patched checks the pointer first.
#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];
    char *sink = NULL;
    if (!fgets(line, sizeof line, stdin)) { printf("EMPTY\n"); return 0; }
    if (strlen(line) >= 4) {
        *sink = line[0];
    }
    printf("OK\n");
    return 0;
}
