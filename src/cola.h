#ifndef COLA_H
#define COLA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

struct Cola{
    struct Nodo *inicio, *fin;
};

struct Nodo* crearNodo();
bool esColaVacia(struct Cola *cola);
void encolar(struct Cola *cola);
void desencolar(struct Cola *cola);
void imprimirCola(struct Cola *cola);
void menu(struct Cola *cola);

#endif /*cola.h*/