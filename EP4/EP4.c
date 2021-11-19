//MIKAEL SHIN, 10843441

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define tam 5

pthread_t filosofo[tam];
pthread_mutex_t garfo[tam];

void garfosIndisponiveis(int *nFilosofo)
{
    pthread_mutex_lock(&(garfo[*nFilosofo]));
    pthread_mutex_lock(&(garfo[(*nFilosofo + 1) % 5]));
}

void garfosDisponiveis(int *nFilosofo)
{
    pthread_mutex_unlock(&(garfo[*nFilosofo]));
    pthread_mutex_unlock(&(garfo[(*nFilosofo + 1) % 5]));
}

void *acaoFilosofo(void *arg){
    
    int *nFilosofo = (int *) arg;
    printf("Filosofo #%d: Entrou no método.\t", *nFilosofo);
    
    while(1){
        
        // bloco para pensar = não usa o recurso (garfo)
        int tempoPensando = (rand()%16);
        printf("Filosofo #%d: Pensando por %ds.\n", *nFilosofo, tempoPensando);
        sleep(tempoPensando);
        
        // bloco para pensar = usa o recurso (garfo)
        garfosIndisponiveis(nFilosofo);
        int tempoComendo = (rand()%16);
        printf("Filosofo #%d: Comendo por %ds.\n", *nFilosofo, tempoComendo);
        sleep(tempoComendo);
        garfosDisponiveis(nFilosofo);
    }
}

int main()
{
    
    int arg[tam];
    
    for(int i = 0; i < tam; i++){
        
        pthread_mutex_init(&(garfo[i]), NULL);
    }
    
    for(int i = 0; i < tam; i++){
        
        arg[i] = i;
        pthread_create(&filosofo[i], NULL, acaoFilosofo, (void*)&arg[i]);
    }
    
    for(int i = 0; i < tam; i++){
        
        pthread_join(filosofo[i], NULL);
    }
    
    return 0;
}
