#include "terp.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define PERM 0755

void init() {
    printf("\033[36mCreating project structure...\033[0m\n");

    if (mkdir("src", PERM) != 0) {
        perror("Error creating src directory");
    }

    if (mkdir("lib", PERM) != 0) {
        perror("Error creating lib directory");
    }

    FILE* src = fopen("src/main.ter", "w");
    if (!src) {
        perror("Error creating src/main.ter");
        return;
    }

    FILE* lib = fopen("lib/lib.ter", "w");
    if (!lib) {
        perror("Error creating lib/lib.ter");
        fclose(src);
        return;
    }

    fprintf(src, "include(\"lib/lib.ter\")\nhello()");
    fprintf(lib, "set hello() {\n  output(\"Hello World!\")\n}");

    fclose(src);
    fclose(lib);
}
