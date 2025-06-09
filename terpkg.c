#include "terpkg.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void help() {
	printf("Terpkg, Version 0.0.1\nUsage: terpkg [option]\nTerpkg long options:\n\t--init\n\t--run\n\t--help\n");
}

void run() {
	printf("\e[35mStarting The Application\e[0m\n");
	system("ter ./src/main.ter");
	printf("\e[35mFinished Application\e[0m\n");
}

void init() {
	printf("\e[36mCreate Files...\e[0m\n");

	mkdir("src", 0755);
	mkdir("lib", 0755);

  FILE* src;
	FILE* lib;

	fopen("src/main.ter", "w");
	lib = fopen("lib/lib.ter", "w");

	if (src == NULL || lib == NULL) {
		src = fopen("src/main.ter", "w");
		lib = fopen("lib/lib.ter", "w");

		fprintf(src, "include(\"lib/lib.ter\")\nhello()");
		fprintf(lib, "set hello() {\n  output(\"Hello World!\")\n}");

		fclose(src);
		fclose(lib);

		printf("\e[32mFiles Created Successfully!\e[0m\n");
	} else {
		perror("\e[31mCouldn't Create The Files!\e[0m\n");
	}
}
