#include <unistd.h> 
#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

pthread_mutex_t mutex;

void *print_message_function( void *ptr);

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";

    pthread_mutex_init(&mutex, NULL);
    
    int iret1 = pthread_create(&thread1, NULL, print_message_function, (void *)message1);
    int iret2 = pthread_create(&thread2, NULL, print_message_function, (void *)message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 retourne: %d\n", iret1);
    printf("Thread 2 retourne: %d\n", iret2);

    return 0;
}

void *print_message_function(void *ptr) {
    char *message;
    message = (char *)ptr;

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < 5; i++) { 
        printf("%s - Analyse %d\n", message, i + 1);
    }
    
    pthread_mutex_unlock(&mutex);

    return NULL;
}