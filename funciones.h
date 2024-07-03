#ifndef FUNCIONES_H
#define FUNCIONES_H

void ingresarCliente(char clientes[20][2][40]);
void listarPeliculas(char peliculas[10][4][40]);
void buscarporNombre(char peliculas[10][4][40]);
void buscarporGenero(char peliculas[10][4][40]);
void comprarTicket(char peliculas[10][4][40], double precio[3], char clientes[20][2][40], int reserva[10][4]);
void verCompras(char peliculas[10][4][40], double precio[3], char clientes[20][2][40], int reserva[10][4]);
void cargarPeliculas(char peliculas[10][4][40]);

#endif

