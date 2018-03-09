#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "tools.h"

/* arg1 : clé, arg2 : -R ou -E (réception message ou envoie) */
int main(int argc, char *argv[]) {
	const char *fifoName = "fifo";
	int compE = 0, compR = 0, fdFifo;
	if (argc != 3) {
		fprintf(stderr, "Erreur, nombres arguments insuffisant\n");
		exit(EXIT_FAILURE);
	}
	if ((compE = strcmp(argv[2], "-E")) != 0 || (compR = strcmp(argv[2], "-R")) != 0) {
		fprintf(stderr, "Argument invalide : -E ou -R uniquement\n");
		exit(EXIT_FAILURE);
	}
	/* Creation du tube */
	if (mkfifo(fifoName, S_IRUSR | S_IWUSR) == -1) {
		if (errno != EEXIST) {
			fprintf(stderr, "Erreur lors de la creation du tube '%s'", fifoName);
			perror(" ");
			exit(EXIT_FAILURE);
		} else
			fprintf(stderr, "Le tube '%s' existe deja.\n", fifoName);
	}
	terminaison(fifoName);
	return EXIT_SUCCESS;
}