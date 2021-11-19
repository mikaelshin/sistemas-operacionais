#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

int main() // processo pai ou processo chamador
{
    
    pid_t childProcess;     // criando um id de processo para a variável
    childProcess = fork();  // criando o processo filho
    
    int i, status;          // atribuindo as variáveis para o código
    
    if(childProcess == 0){  // verifica se é processo filho, e executa o 'if' caso seja. 
        
        printf("Hello World! I'm child process.\n"); // print de Hello World do processo filho
        
        _exit(0); // fim do processo filho, passando o controle para o processo pai
        
    } else { // executa o 'else' referente ao processo pai
        
        wait(childProcess, &status, 0); // suspende a execução do processo pai até que seja finalizado
        printf("Hello World! I'm parent process.\n"); // print de Hello World do processo pai
    }
    
    return 0;
}