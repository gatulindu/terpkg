#include "terp.h"

#include <stdio.h>

void help() {
    printf("Terpkg - Version v0.01-release - MIT License\n\n");
    printf("Usage:\n");
    printf("  terpkg [option]\n\n");
    printf("Options:\n");
    printf("  --init    Initialize a new terpkg project\n");
    printf("  --run     Run the main terpkg application\n");
    printf("  --help    Show this help message\n");
}
