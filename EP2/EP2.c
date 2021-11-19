// MIKAEL SHIN, 10843441

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define count 100000000 // variável global count
#define tam 2 // número de processos/threads

int vez = 0; // declarando e definindo de quem é a vez da execução 

void secao_critica(int p){ // função que simula a execução da região crítica 
    
    int i;
    for (int i = 0; i < count; i++) { // uma execução qualquer que demande um tempinho
        i = i;
    }
    printf("P%d: Entrou na Seção Crítica\n", p); // mensagem de entrada na seção crítica
}

void secao_nao_critica(int p){ // função que simula a execução da seção não crítica
    
    int i;
    int num = 10000000;
    for (int i = 0; i < num; i++) { // uma execução qualquer que demande um tempinho
        num = num;
    }
    printf("P%d: Saiu da Seção Crítica\n", p); // mensagem de entrada na seção crítica
}

void *run (void *arg){ // função que irá servir de execução para cada uma dos threads
    
    int* n;
    n = arg; // necessário para os seguintes if's
    int meu_id; 
    int outro;
    
    if(*n == 0){ // se o argumento do thread for 0, ele entra para a execução
    
        meu_id = 0; // declarando o ID do thread 0
        outro = 1; // armazenando o ID do outro thread
        
        printf("T0 chegou no método 'run'\n"); // mensagem de sucesso
        
        while(1){ // enquanto for verdade
            
            while(vez != meu_id); // enquanto vez é diferente do id, executa (no caso, nada)
            secao_critica(meu_id); // thread entra na seção crítica
            vez = outro; // dá a vez para o outro thread
            secao_nao_critica(meu_id); // thread executa algo que está fora da seção crítica
        }
    } 
    
    else if(*n == 1){ // bloco semelhante ao anterior, só que para a processo 1
        
        meu_id = 1; 
        outro = 0; 
        
        printf("T1 chegou no método 'run'\n"); 
        
        while(1){ 
            
            while(vez != meu_id);
            secao_critica(meu_id);
            vez = outro;
            secao_nao_critica(meu_id);
        }
    }
}

int main()
{
    
    pthread_t p[tam]; // declarando as threads posix
    int i, arg[tam]; // declarando as variáveis inteiras 
    
    for(i = 0; i < tam; i++){ // for: 0 e 1
        
        arg[i] = i; // array de argumento, posição 0 armezena 0, posição 1 armazena 1
        pthread_create(&p[i], NULL, run, (void*)&arg[i]); // instanciação das threads 0 e 1
    }
    
    for(i = 0; i < tam; i++){
    
        pthread_join(p[i], NULL); // aguarda o término de cada uma das threads
    }
    
    pthread_exit(NULL); // finaliza a execução das threads

    return 0;
}


