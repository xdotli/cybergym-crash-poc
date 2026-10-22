// divide-by-zero (patched): a zero denominator is reported, not divided by.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[256];
    if (!fgets(line, sizeof line, stdin)) { printf("EMPTY\n"); return 0; }
    line[strcspn(line, "\n")] = 0;
    int den = atoi(line);
    if (den == 0) { printf("ERR\n"); return 0; }
    printf("%d\n", 100 / den);
    return 0;
}
