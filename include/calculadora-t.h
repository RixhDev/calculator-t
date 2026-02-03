#ifndef CALCULADORA_H
#define CALCULADORA_H

#define MAX_NUM 100

// Prototipos
void mostrarMenu(void);
void limpiarBuffer(void);
int solicitarCantidad(int min, int max);
float solicitarNumero(const char *mensaje);
float operar(int opc, int n, float nums[]);

#endif
