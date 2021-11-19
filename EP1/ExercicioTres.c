#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define tam 10

void wait(){ // função que será executada para simular o estado de wait nas threads
    
    int i;
    int num = 10000000;
    for (int i = 0; i < num; i++) {
        num = num;
    }
}

void *run (void *arg){ // função que irá servir de execução para cada uma das threads
    
    int *valor; // declarando um ponteiro de inteiro
    valor = arg; // "valor" recebe o conteúdo do endereço de "arg"
    
    printf("Thread #%i: Hello World!\n", *valor);
    
    wait(); // chamando a função que simula uma espera das threads

    printf("Thread #%i: See you later World!\n", *valor);
}

int main(){
    
    pthread_t threads[tam]; // declarando as threads posix
    
    int i, arg[tam]; // declarando as variáveis inteiras
    
    for(i = 0; i < tam; i++){ // loop: contando de 0 a 9 
        
        arg[i] = i + 1; // array de argumento, posição 0 armezena 1, posição 1 armazena 2, ...
        pthread_create(&threads[i], NULL, run, (void*)&arg[i]); // instanciação das threads (de 1 à 10)
        // pthread_create:  1º parâmetro: recebe o endereço da thread
        //                  2º parâmetro: recebe atributos para a thread (nesse caso, utilizou-se o NULL)
        //                  3º parâmetro: recebe a função de início para a execução das threads
        //                  4º parâmetro: recebe o mesmo argumento que é passado para a função de início
    }
    
    for(i = 0; i < tam; i++){
    
        pthread_join(threads[i], NULL); // aguarda o término de cada uma das threads
        // pthread_join: 1º parâmetro: recebe a thread
        //               2º parâmetro: se !NULL, recebe o código de retorno da thread (0 = sucesso, 'n' = código de erro )
    }
    
    printf("\nTodas as threads foram executadas.\n"); // mensagem de fim da execução das threads
        
    pthread_exit(NULL); // finalização das threads
        
    return 0;
}
