#include "tools.h"

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void terminaison(const char *nameFifo) {
	if (unlink(nameFifo) != 0) {
		if (errno != ENOENT) {
			fprintf(stderr, "Erreur lors de la suppression du tube %s", nameFifo);
			perror(" ");
			exit(EXIT_FAILURE);
		}
	}
}