#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>	

typedef struct {
    int chiffre1; //chiffre1
    int chiffre2; //chiffre2
    int result; //resultat operation
    int mode;  //Pour choisir entre 1 pour AND, 2 pour OR, 3 pour XOR
} entrer_utilisateur;

//Fonction pour calculer l'AND
void *and(void *arg) {
    entrer_utilisateur *choix = (entrer_utilisateur *)arg;
    choix->result = choix->chiffre1 && choix->chiffre2;
    pthread_exit(NULL);
}

//Fonction pour calculer l'OR
void *or(void *arg) {
    entrer_utilisateur *choix = (entrer_utilisateur *)arg;
    choix->result = choix->chiffre1 || choix->chiffre2;
    pthread_exit(NULL);
}

//Fonction pour calculer le XOR
void *xor(void *arg) {
    entrer_utilisateur *choix = (entrer_utilisateur *)arg;
    choix->result = choix->chiffre1 ^ choix->chiffre2;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];  //1 threads par operation
    entrer_utilisateur choix[3];  //Un tableau de structures pour AND, OR, XOR
    
    printf("Entrez un premier chiffre  0 ou 1 : ");
    scanf("%d", &choix[0].chiffre1);

    while (choix[0].chiffre1 != 0 && choix[0].chiffre1 != 1) {
        printf("Il faut rntrer 0 ou 1 : ");
        scanf("%d", &choix[0].chiffre1);
    }

    printf("Entrez un deuxième chiffre 0 ou 1 : ");
    scanf("%d", &choix[0].chiffre2);

    while (choix[0].chiffre2 != 0 && choix[0].chiffre2 != 1) {
        printf("Il faut rntrer 0 ou 1  : ");
        scanf("%d", &choix[0].chiffre2);
    }

    entrer_utilisateur choix_and = choix[0];  
    entrer_utilisateur choix_or = choix[0];  
    entrer_utilisateur choix_xor = choix[0]; 

    //threads pour chaque operation 
    pthread_create(&threads[0], NULL, and, (void *)&choix_and);
    pthread_create(&threads[1], NULL, or, (void *)&choix_or);
    pthread_create(&threads[2], NULL, xor, (void *)&choix_xor);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    //resultats
    printf("Resultat\n");
    printf("%d AND %d = %d\n", choix_and.chiffre1, choix_and.chiffre2, choix_and.result);
    printf("%d OR %d = %d\n", choix_or.chiffre1, choix_or.chiffre2, choix_or.result);
    printf("%d XOR %d = %d\n", choix_xor.chiffre1, choix_xor.chiffre2, choix_xor.result);

    return 0;
}