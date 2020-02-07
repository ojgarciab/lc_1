CC=gcc
CFLAGS=

all : Ejercicio6completo_TP3 TP3-Ej6b
	echo "Hecho"

Ejercicio6completo_TP3: Ejercicio6completo_TP3.c
	$(CC) -o Ejercicio6completo_TP3 Ejercicio6completo_TP3.c

TP3-Ej6b: TP3-Ej6b.c
	$(CC) -o TP3-Ej6b TP3-Ej6b.c
