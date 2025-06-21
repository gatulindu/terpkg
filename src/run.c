#include "terp.h"

#include <stdio.h>
#include <stdlib.h>

void run() {
    printf("\033[35mStarting The Application\033[0m\n");
    int status = system("ter ./src/main.ter");
    if (status != 0) {
        fprintf(stderr, "\033[31mError: Failed to run application (code %d)\033[0m\n", status);
    }
    printf("\033[35mFinished Application\033[0m\n");
}
