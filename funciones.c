#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarCliente(char clientes[20][2][40]) {
    int i;
    for (i = 0; i < 20; i++) {
        if (strlen(clientes[i][0]) == 0) {
            printf("Ingrese el nombre del cliente: ");
            scanf("%s", clientes[i][0]);
            printf("Ingrese el cedula del cliente: ");
            scanf("%s", clientes[i][1]);
            break;
        }
    }
    if (i == 20) {
        printf("No se pueden agregar más clientes.\n");
    }
}

void listarPeliculas(char peliculas[10][4][40]) {
    printf("Listado de peliculas:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s. %s - %s - %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
}

void buscarporNombre(char peliculas[10][4][40]) {
    char nombre[40];
    printf("Ingrese el nombre de la pelicula: ");
    scanf("%s", nombre);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], nombre) == 0) {
            printf("Pelicula encontrada: %s - %s - %s\n", peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("Pelicula no encontrada.\n");
}

void buscarporGenero(char peliculas[10][4][40]) {
    char genero[40];
    printf("Ingrese el genero de la pelicula: ");
    scanf("%s", genero);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][3], genero) == 0) {
            printf("Pelicula: %s - %s - %s\n", peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
}

void comprarTicket(char peliculas[10][4][40], double precio[3], char clientes[20][2][40], int reserva[10][4]) {
    int clienteIndex, peliculaIndex, cantidad;
    printf("Clientes:\n");
    for (int i = 0; i < 20; i++) {
        if (strlen(clientes[i][0]) > 0) {
            printf("%d. %s\n", i, clientes[i][0]);
        }
    }
    printf("Seleccione el cliente (indice): ");
    scanf("%d", &clienteIndex);

    printf("Peliculas:\n");
    listarPeliculas(peliculas);
    printf("Seleccione la pelicula (indice): ");
    scanf("%d", &peliculaIndex);

    printf("Seleccione la cantidad de tickets: ");
    scanf("%d", &cantidad);

    int reserved = 0;
    for (int i = 0; i < 4; i++) {
        if (reserva[peliculaIndex][i] == -1) {
            reserva[peliculaIndex][i] = clienteIndex;
            reserved++;
            if (reserved == cantidad) break;
        }
    }

    if (reserved < cantidad) {
        printf("No hay suficientes asientos disponibles para la cantidad solicitada.\n");
    } else {
        printf("Compra realizada. Precio total: %.2f\n", precio[cantidad-1] * cantidad);
    }
}

void verCompras(char peliculas[10][4][40], double precio[3], char clientes[20][2][40], int reserva[10][4]) {
    printf("Reservas:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            if (reserva[i][j] != -1) {
                printf("Pelicula: %s, Cliente: %s\n", peliculas[i][1], clientes[reserva[i][j]][0]);
            }
        }
    }
}

void cargarPeliculas(char peliculas[10][4][40]) {
    FILE *file = fopen("peliculas.txt", "r");
    if (file == NULL) {
        perror("Error al abrir peliculas.txt");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%s %s %s %s", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
    fclose(file);
}
