#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>

bool flag = false;      
int estado = 0; 
//En el manejador se define el flag y el estado
void manejador(int sig) {
    printf("Estado: %d y flag: %d \n", estado, flag); //AL tener la variable estado = 0, se imprimir primero las letras
    if (estado == 0) { 
        flag = true;
        estado = 1;
        alarm(2); //Se actualiza el tiempo a 2 y procede a imprimir números 
    } else {
        flag = false;
        estado = 0;
        alarm(5); //Se actualiza el tiempo a 5 y procede a imprimir letras
    }
}

int main() {
    signal(SIGALRM, manejador);
    int i = 0;
    char c = 'A';
    //Se crea el primer temporizador de 5 segundos
    alarm(5);
    while (1) {
        if (flag) {
            printf("%d \n", i);
            if (i == 9) i = 0;
            else i++;
            sleep(1);
        } else {
            printf("%c \n", c);
            if(c == 'Z') c = 'A';
            else c++;
            sleep(1);
        }
    }
    return 0;
}
