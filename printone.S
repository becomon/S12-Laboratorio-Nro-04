    .section .text
    .global printone

printone:
    mv t0, a0            # Guardamos puntero al caracter en t0, nuestro parametro basicamente

    addi a7, x0, 64      # syscall write
    addi a0, x0, 1       # fd = 1 (stdout)
    mv a1, t0            # buf = puntero al caracter
    addi a2, x0, 1       # count = 1 byte
    ecall