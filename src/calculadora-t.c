// Librerias I/O | aux exit() | NAN
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculadora-t.h"
// Maximo de n° para operar
#define MAX_NUM 100

//Funciones aux
void mostrarMenu(void) {
    printf("=== Calculadora ===\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("5. Salir\n");
    printf("Operacion: ");
}
// Limpieza del buffer
void limpiarBuffer(void) {
    while (getchar() != '\n');
}

// Solicita cantidad valida
int solicitarCantidad(int min, int max) {
    int cantidad;
    printf("Cantidad de numeros (%d-%d): ", min, max);
    if (scanf("%d", &cantidad) != 1 || cantidad < min || cantidad > max){
        printf("ERROR! Cantidad invalida.\n");
	limpiarBuffer();
	return -1;
    }
    return cantidad;
}

// Solicita numero valido
float solicitarNumero(const char *mensaje){
    float numero;
    printf("%s", mensaje);
    while (scanf("%f", &numero) != 1) {
        printf("ERROR! Entrada invalida.\n");
	limpiarBuffer();
	printf("%s", mensaje);
    }
    return numero;
}

// Logica de operaciones
float operar(int op, int n, float nums[]) {
    float resultado = 0;

    switch(op){
        case 1: // Suma
	    for (int i = 0; i < n; i++) resultado += nums[i];
	    break;
	case 2: // Resta
	    resultado = nums[0];
	    for (int i=1 ; i < n ; i++) resultado -= nums[i];
	    break;
	case 3: // Multiplicacion
	    resultado = 1;
	    for (int i=0 ; i < n ; i++) resultado *= nums[i];
	    break;
	case 4: // Division
            resultado = nums[0];
	    for (int i = 1; i < n; i++){
	        if (nums[i] == 0) return NAN; // Verif. division inv.
		resultado /= nums[i];
	    }
	    break;
	default:
	    return NAN;
    }
    return resultado;
}

// Control del flujo principal
int main(void) {
	int op, cantidad;
	float nums[MAX_NUM];
	float resultado;

	do{
		mostrarMenu();
		// Capturar opcion en entrada
		if (scanf("%d", &op) != 1){
			printf("ERROR!: Opcion invalida.\n");
			limpiarBuffer();
			continue;
		}
		
		if (op == 5) break;
		
		// Validar cantidad en cada operacion
		cantidad= (op == 1 || op == 3) ? solicitarCantidad(1, MAX_NUM)
			                       : solicitarCantidad(2, MAX_NUM);

		if (cantidad == -1) continue;

		// Capturar los numeros
		for (int i = 0; i < cantidad; i++){
		    char mensaje[30];
		    sprintf(mensaje, "Ingresar numero %d: ", i+1);
		    nums[i]= solicitarNumero(mensaje);
		}
                
		// Ejecutar operacion
		resultado= operar(op, cantidad, nums);
		if (isnan(resultado)) {
		    printf("ERROR! Operacion invalida (Division por 0 u operacion invalida)");
		    continue;
		}

		printf("Resultado: %.2f\n", resultado);
        } while (op != 5);

	printf("Cerrando calculadora...\n");
	return 0;

}

