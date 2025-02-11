#include <unistd.h> 
#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

void *thread_1(void *arg){ 
    printf("Nous sommes dans le thread.\n"); 
    pthread_exit(NULL); 
}

int main(void){ 
 
    pthread_t thread1;
    printf("Avant la creation du thread.\n"); 
    if(pthread_create(&thread1, NULL, thread_1, NULL) == -1){ 
        perror("pthread_create"); 
        return EXIT_FAILURE;
    } 
    printf("Après la creation du thread.\n"); 
    return EXIT_SUCCESS; 
} 