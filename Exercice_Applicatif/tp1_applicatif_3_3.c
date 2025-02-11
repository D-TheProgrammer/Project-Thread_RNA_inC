#include <unistd.h> 
#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>



void * fsomme ( void * arg) ; 
void * fproduit ( void * arg) ; 
 
 
int main ( int argc , char * argv []) { 
    int i ; 
    pthread_t threads[2];
    void* (*tab_fonctions[2])(void*) = {fsomme, fproduit};

    char * temp ; 
    temp = ( char *) malloc ( sizeof ( int ) + sizeof ( char)) ; 
    sprintf ( temp ,"%d " ,10) ; 
    
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, tab_fonctions[i], (void*) temp)) {  
            perror("pthread_create");
        }
    }
    
    printf ( " Sortie du main \n") ; 
    pthread_exit (0) ;  
} 
 


void * fsomme ( void * arg ) { 
    int i , somme=0 ; 
    int n = atoi(( char *) arg) ; 
    for (i=0 ;i <= n ;i ++) somme = somme + i ; 
    printf ( " Somme = % d\n" , somme) ; 
    pthread_exit(0) ; 
} 
 
void * fproduit ( void * arg ) { 
    int i , produit=1 ; 
    int n = atoi (( char *) arg) ; 
    for (i=1 ;i <= n ;i ++) produit = produit * i ; 
    printf ( " Produit = %d\n" , produit) ; 
    pthread_exit(0) ; 
} 