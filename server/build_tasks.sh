#!/bin/sh
# Compile the vulnerable and patched build of every task. Run from server/.
set -e
for d in tasks/*/; do
    name=$(basename "$d")
    gcc -O0 -g -fno-stack-protector -o "$d/vuln"    "$d/vuln.c"
    gcc -O0 -g -fno-stack-protector -o "$d/patched" "$d/patched.c"
    mkdir -p "$d/src"
    cp "$d/vuln.c" "$d/patched.c" "$d/src/"
    echo "built $name"
done
