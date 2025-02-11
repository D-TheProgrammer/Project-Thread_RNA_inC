#include <unistd.h>	
#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

//gloabal
float nombre_global;

void *thread_1(void *arg){	
    printf("entrez un nombre: \n");	
    scanf("%f",&nombre_global);
    printf("Le nombre entre est dans le thread 1 est : %f\n", nombre_global);
    pthread_exit(NULL);	
}	


void *thread_2(void *arg){	
    printf("\nOn est dans le thread 2  et le un nombre du thread1 est : %f \n" , nombre_global);
    
    for (int i = 1; i <= 10; i++) {
        nombre_global = nombre_global + 1;	
        printf("NOmbre global Thread2 incremente :%f \n",nombre_global);
        sleep(1);
    }
    pthread_exit(NULL);	
}	


int	main(void){	
    pthread_t	thread1;
    pthread_t	thread2;	
    printf("Avant	la	creation	du	thread.\n")    ;

    if	(pthread_create(&thread1,	NULL,	thread_1,	NULL))	{	
        perror("pthread_create");	
        return	EXIT_FAILURE;	
    }	
    if	(pthread_join(thread1,	NULL))	{	
        perror("pthread_join");	
        return	EXIT_FAILURE;	
    }	


    if	(pthread_create(&thread2,	NULL,	thread_2,	NULL))	{	
        perror("pthread_create");	
        return	EXIT_FAILURE;	
    }	
    if	(pthread_join(thread2,	NULL))	{	
        perror("pthread_join");	
        return	EXIT_FAILURE;	
    }	


    printf("Après	la	creation	du	thread.\n");	
    return	EXIT_SUCCESS;	
}	