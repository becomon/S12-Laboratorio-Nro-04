#include <stdio.h>

// Función que de RISC V printone
void printone(char *ch);

int main() {
    char letra = 'Z'; // Caracter a imprimir
    printone(&letra); // Pasamos dirección de la variable a ensamblador
    printf("\n");
    return 0;
}
