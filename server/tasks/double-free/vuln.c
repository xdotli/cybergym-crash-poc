// double-free: a heap block is freed a second time whenever the input line is
// non-empty -> glibc abort (SIGABRT). Patched clears the pointer after free.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[256];
    if (!fgets(line, sizeof line, stdin)) { printf("EMPTY\n"); return 0; }
    char *p = malloc(8);
    free(p);
    if (strlen(line) > 0) {
        free(p);
    }
    printf("OK\n");
    return 0;
}
