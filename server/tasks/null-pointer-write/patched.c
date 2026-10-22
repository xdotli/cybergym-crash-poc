// null-pointer-write (patched): the store is guarded.
#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];
    char *sink = NULL;
    if (!fgets(line, sizeof line, stdin)) { printf("EMPTY\n"); return 0; }
    if (sink != NULL && strlen(line) >= 4) {
        *sink = line[0];
    }
    printf("OK\n");
    return 0;
}
