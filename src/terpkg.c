#include "terpkg.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define PERM 0755

void help() {
    printf("Terpkg - Version v0.01-alpha - MIT License\n\n");
    printf("Usage:\n");
    printf("  terpkg [option]\n\n");
    printf("Options:\n");
    printf("  --init    Initialize a new terpkg project\n");
    printf("  --run     Run the main terpkg application\n");
    printf("  --help    Show this help message\n");
}

void run() {
    printf("\033[35mStarting The Application\033[0m\n");
    int status = system("ter ./src/main.ter");
    if (status != 0) {
        fprintf(stderr, "\033[31mError: Failed to run application (code %d)\033[0m\n", status);
    }
    printf("\033[35mFinished Application\033[0m\n");
}

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

    printf("\033[32mProject initialized successfully!\033[0m\n");
}
