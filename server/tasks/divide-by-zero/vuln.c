// divide-by-zero: the input line is parsed as the denominator of 100/x.
// Input "0" (or a line that parses to 0) -> SIGFPE. Patched guards it.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[256];
    if (!fgets(line, sizeof line, stdin)) { printf("EMPTY\n"); return 0; }
    line[strcspn(line, "\n")] = 0;
    int den = atoi(line);
    printf("%d\n", 100 / den);
    return 0;
}
