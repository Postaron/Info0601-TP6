#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <errno.h>
#include "structures.h"

/* arg1 : clé, arg2 : -R ou -E (réception message ou envoie) */
int main(int argc, char *argv[]) {
	int compE = 0, compR = 0, fdFifo, msqid, key;
	requete_t requete;
	reponse_t reponse;
	if (argc != 3) {
		fprintf(stderr, "Erreur, nombres arguments insuffisant\n");
		exit(EXIT_FAILURE);
	}
	key = atoi(argv[1]);
	if ((compE = strcmp(argv[2], "-E")) != 0 || (compR = strcmp(argv[2], "-R")) != 0) {
		fprintf(stderr, "Argument invalide : -E ou -R uniquement\n");
		exit(EXIT_FAILURE);
	}
	/* Creation de la file si elle n'existe pas */
	if ((msqid = msgget((key_t) key, S_IRUSR | S_IWUSR | IPC_CREAT | IPC_EXCL)) == -1) {
		if (errno == EEXIST)
			fprintf(stderr, "Erreur : file (cle=%d) existante\n", key);
		else {
			perror("Erreur lors de la creation de la file ");
			exit(EXIT_FAILURE);
		}
	}
	if (compE == 0) {
		requete.type = TYPE_REQUETE,
		requete.valeur1 = 3,
		requete.valeur2 = 2;
		if (msgsnd(msqid, &requete, sizeof(requete_t) - sizeof(long), 0) == -1) {
			perror("Erreur lors de l'envoi de la requete ");
			exit(EXIT_FAILURE);
		}
		printf("Client : envoi d'une requete.\n");
	}
	return EXIT_SUCCESS;
}