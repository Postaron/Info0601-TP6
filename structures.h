#ifndef TP6_FILE_DE_MESSAGE_STRUCTURES_H
#define TP6_FILE_DE_MESSAGE_STRUCTURES_H

/* Type de message requete */
#define TYPE_REQUETE 1

/* Structure utilisee pour les requetes */
typedef struct {
	long type;
	int valeur1;
	int valeur2;
} requete_t;

/* Type de message reponse */
#define TYPE_REPONSE 2

/* Structure utilisee pour les reponses */
typedef struct {
	long type;
	int resultat;
} reponse_t;

#endif //TP6_FILE_DE_MESSAGE_STRUCTURES_H
