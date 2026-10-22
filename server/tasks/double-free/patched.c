// double-free (patched): the pointer is NULLed after the first free.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[256];
    if (!fgets(line, sizeof line, stdin)) { printf("EMPTY\n"); return 0; }
    char *p = malloc(8);
    free(p);
    p = NULL;
    if (strlen(line) > 0 && p) {
        free(p);
    }
    printf("OK\n");
    return 0;
}
