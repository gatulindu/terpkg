#include "terpkg.h"
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc > 1 && strcmp(argv[1], "--init") == 0) {
		init();
	} else if (argc > 1 && strcmp(argv[1], "--run") == 0) {
		run();
	}	else if (argc > 1 && strcmp(argv[1], "--help") == 0) {
		help();
	} else {
		help();
	}
	return 0;
}
