#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct {
    float poids_entree_couche_cachee[2][2];  
    float poids_couche_cachee_sortie[2];     
    float biais_couche_cachee[2];     
    float biais_sortie;     
} ReseauNeurones;

//frmarre un reseau de neuronne avec des valeurs aleatoire
void demarre_reseau(ReseauNeurones *reseau) {
    for (int i_entree = 0; i_entree < 2; i_entree++) {  // 2 entrees
        for (int i_couche_cachee = 0; i_couche_cachee < 2; i_couche_cachee++) {
            reseau->poids_entree_couche_cachee[i_entree][i_couche_cachee] = ((float)rand() / RAND_MAX) * 2 - 1; // Poids entre [-1, 1]
        }
    }

    for (int i_couche_cachee = 0; i_couche_cachee < 2; i_couche_cachee++) {
        reseau->poids_couche_cachee_sortie[i_couche_cachee] = ((float)rand() / RAND_MAX) * 2 - 1; //entre [-1, 1]
        reseau->biais_couche_cachee[i_couche_cachee] = ((float)rand() / RAND_MAX) * 2 - 1; //entre [-1, 1]
    }

    reseau->biais_sortie = ((float)rand() / RAND_MAX) * 2 - 1; 
}

//propagation avant
float propagation_avant(ReseauNeurones *reseau, float entree1, float entree2, float couche_cachee[2]) {
    //valeurs pour la couche cachee
    for (int i_couche_cachee = 0; i_couche_cachee < 2; i_couche_cachee++) {
        couche_cachee[i_couche_cachee] = tanhf(entree1 * reseau->poids_entree_couche_cachee[0][i_couche_cachee] + entree2 * reseau->poids_entree_couche_cachee[1][i_couche_cachee] + reseau->biais_couche_cachee[i_couche_cachee]);
    }

    float sortie = 0;
    for (int i_couche_cachee = 0; i_couche_cachee < 2; i_couche_cachee++) {
        sortie += couche_cachee[i_couche_cachee] * reseau->poids_couche_cachee_sortie[i_couche_cachee];
    }
    sortie += reseau->biais_sortie;

    return tanhf(sortie);
}

//retropropagation
void retropropagation(ReseauNeurones *reseau, float entree1, float entree2, float couche_cachee[2], float sortie, float cible) {
    float erreur = cible - sortie;

    //delta pour la sortie
    float delta_sortie = erreur * (1 - sortie * sortie);

    //Calcul = delta pour la couche cachee
    float delta_couche_cachee[2];
    for (int i_couche_cachee = 0; i_couche_cachee < 2; i_couche_cachee++) {
        delta_couche_cachee[i_couche_cachee] = delta_sortie * reseau->poids_couche_cachee_sortie[i_couche_cachee] * (1 - couche_cachee[i_couche_cachee] * couche_cachee[i_couche_cachee]);
    }

    //maj des poids et biais pour la sortie
    for (int i_couche_cachee = 0; i_couche_cachee < 2; i_couche_cachee++) {
        reseau->poids_couche_cachee_sortie[i_couche_cachee] += delta_sortie * couche_cachee[i_couche_cachee];
    }
    reseau->biais_sortie += delta_sortie;

    //Maj des poids et biais pour la couche cachee
    for (int i_couche_cachee = 0; i_couche_cachee < 2; i_couche_cachee++) {
        reseau->poids_entree_couche_cachee[0][i_couche_cachee] += delta_couche_cachee[i_couche_cachee] * entree1;
        reseau->poids_entree_couche_cachee[1][i_couche_cachee] += delta_couche_cachee[i_couche_cachee] * entree2;
        reseau->biais_couche_cachee[i_couche_cachee] += delta_couche_cachee[i_couche_cachee];
    }
}

//Entrainement du reseau neuron
void train_reseau(ReseauNeurones *reseau, float entrees[4][2], float sorties[4]) {
    int iterations = 0;
    int max_iterations = 1000;  
    while (iterations < max_iterations) {
        iterations++; 
        int erreur_bonne = 0;
        for (int i = 0; i < 4; i++) {
            float couche_cachee[2];
            float sortie = propagation_avant(reseau, entrees[i][0], entrees[i][1], couche_cachee);

            if (fabs(sortie - sorties[i]) < 0.001) {
                erreur_bonne++;
            } else {
                retropropagation(reseau, entrees[i][0], entrees[i][1], couche_cachee, sortie, sorties[i]);
            }
        }
        if (erreur_bonne == 4) {
            break;  // Si erreurs sont correctes stop
        }
    }
}


//Threads pour les portes logiques
void* train_porte_et(void* arg) {
    ReseauNeurones* reseau = (ReseauNeurones*) arg;
    float entrees[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    float sorties[4] = {0, 0, 0, 1}; //ET
    train_reseau(reseau, entrees, sorties);
    return NULL;
}

void* train_porte_ou(void* arg) {
    ReseauNeurones* reseau = (ReseauNeurones*) arg;
    float entrees[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    float sorties[4] = {0, 1, 1, 1}; //OU
    train_reseau(reseau, entrees, sorties);
    return NULL;
}

void* train_porte_xor(void* arg) {
    ReseauNeurones* reseau = (ReseauNeurones*) arg;
    float entrees[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    float sorties[4] = {0, 1, 1, 0}; //XOR
    train_reseau(reseau, entrees, sorties);
    return NULL;
}


int main() {
    pthread_t threads[3];
    ReseauNeurones res_neu_et, res_neu_ou, res_neu_xor;

    //reseaux neuroonne
    demarre_reseau(&res_neu_et);
    demarre_reseau(&res_neu_ou);
    demarre_reseau(&res_neu_xor);

    //threads pour train chaque reseau
    pthread_create(&threads[0], NULL, train_porte_et, &res_neu_et);
    pthread_create(&threads[1], NULL, train_porte_ou, &res_neu_ou);
    pthread_create(&threads[2], NULL, train_porte_xor, &res_neu_xor);
    
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }


    //Tests
    printf("Predictions des portes logiques :\n");
    
    float couche_cachee[2];  // la couche cachee pour les predictions
    
    for (int entree1 = 0; entree1 <= 1; entree1++) { 
        for (int entree2 = 0; entree2 <= 1; entree2++) {  
            float resultat_et = propagation_avant(&res_neu_et, entree1, entree2, couche_cachee);
            float resultat_ou = propagation_avant(&res_neu_ou, entree1, entree2, couche_cachee);
            float resultat_xor = propagation_avant(&res_neu_xor, entree1, entree2, couche_cachee);

            //afficgae 
            printf("ET : %d ET %d = %.5f -> arrondie: %d\n", entree1, entree2, resultat_et, (resultat_et >= 0.5f) ? 1 : 0);
            printf("OU : %d OU %d = %.5f -> arrondie: %d\n", entree1, entree2, resultat_ou, (resultat_ou >= 0.5f) ? 1 : 0);
            printf("XOR : %d XOR %d = %.5f -> arrondie: %d\n",entree1, entree2, resultat_xor, (resultat_xor >= 0.5f) ? 1 : 0);
            printf("\n");
        }
    }
    return 0;
}