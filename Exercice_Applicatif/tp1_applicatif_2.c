#include <unistd.h> 
#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>


void *thread_1(void *arg){ 
    float *variable_incremente= (float *)arg; 
    printf("Nous sommes dans le thread.\n"); 
    printf("Ecris un nombre a acceder .\n"); 
    scanf("%f",variable_incremente);
    (*variable_incremente)++;  
    printf("Valeur incrementee dans le thread : %f\n", *variable_incremente);
    pthread_exit(NULL); 
} 


int main(void){ 
    pthread_t thread1; 

    float *variable_incremente = malloc(sizeof(float));

    if (variable_incremente == NULL) {  
        return EXIT_FAILURE;
    }

    printf("Avant la création du thread.\n"); 
    if (pthread_create(&thread1, NULL, thread_1, (void *)variable_incremente)) { 
        perror("pthread_create"); 
        free(variable_incremente); 
        return EXIT_FAILURE; 
    } 
    if (pthread_join(thread1, NULL)) { 
        perror("pthread_join"); 
        free(variable_incremente); 
        return EXIT_FAILURE; 
    } 

    printf("Après la création du thread.\n"); 

    printf("Voici le nombre choisi : %f", *variable_incremente);
return EXIT_SUCCESS; 
}