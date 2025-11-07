## Compilación

Para generar el binario que ejecuta el codigo en C combinado con el RISC V ejecutar el siguiente comando:

```bash
riscv64-linux-gnu-gcc -static -o programa main.c printone.S
```

Luego debe colocar el siguiente comando para ejecutar dicho binario:

```bash
qemu-riscv64 ./programa
```
