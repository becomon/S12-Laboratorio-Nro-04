#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>

bool flag = false;      
int estado = 0; 

void manejador(int sig) {
    printf("Estado: %d y flag: %d \n", estado, flag);
    if (estado == 0) {
        flag = true;
        estado = 1;
        alarm(2);
    } else {
        flag = false;
        estado = 0;
        alarm(5);
    }
}

int main() {
    signal(SIGALRM, manejador);
    int i = 0;
    char c = 'A';
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
