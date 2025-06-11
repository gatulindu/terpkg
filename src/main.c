#include "terpkg.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        help();
        return 0;
    }

    if (strcmp(argv[1], "--init") == 0) {
        init();
    } else if (strcmp(argv[1], "--run") == 0) {
        run();
    } else if (strcmp(argv[1], "--help") == 0) {
        help();
    } else {
        fprintf(stderr, "Invalid argument: %s\n\n", argv[1]);
        help();
        return 1;
    }

    return 0;
}
