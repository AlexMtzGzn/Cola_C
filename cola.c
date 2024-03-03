#include "cola.h"

struct Nodo *crearNodo()
{
    int elemento;
    printf("Ingresa el elemento de la cola: ");
    scanf("%i", &elemento);

    struct Nodo *nodo = malloc(sizeof(struct Nodo));
    
    if (nodo != NULL)
    {
        nodo->dato = elemento;
        nodo->siguiente = NULL;
    }
    else
    {
        printf("\nError al asignar memoria al nodo. ");
    }

    return nodo;
}

bool esColaVacia(struct Cola *cola)
{
    return cola->inicio == NULL && cola->fin == NULL;
}

void encolar(struct Cola *cola)
{
    struct Nodo *nodoNuevo = crearNodo();

    if (nodoNuevo != NULL)
    {
        if (esColaVacia(cola))
        {
            cola->inicio = cola->fin = nodoNuevo;
        }
        else
        {
            cola->fin->siguiente = nodoNuevo;
            cola->fin = nodoNuevo;
        }
    }
}

void desencolar(struct Cola *cola){
    if(!esColaVacia(cola)){
        struct Nodo *nodoEliminar = cola->inicio;
        cola->inicio = nodoEliminar->siguiente;
        free(nodoEliminar);

        if(cola->inicio == NULL){
            cola->fin = cola->inicio = NULL;
        }
    }
}

void imprimirCola(struct Cola *cola)
{
    if (!esColaVacia(cola))
    {
        printf("\nCola\n");
        struct Nodo *nodoActual = cola->inicio;
        while (nodoActual != NULL)
        {
            printf("%i", nodoActual->dato);

            if (nodoActual->siguiente != NULL)
                printf("-");

            nodoActual = nodoActual->siguiente;
        }
    }
    else
    {
        printf("\nLa cola está vacía.");
    }
}

void liberarCola(struct Cola *cola)
{
    while (!es_Cola_Vacia(cola))
        desencolar(cola);

    cola->fin = NULL;
}

void menu(struct Cola *cola)
{
    int opcion;
    do
    {
        printf("\n\nCOLAS");
        printf("\n\n1- Encolar");
        printf("\n2- Desencolar");
        printf("\nIngresa la opcion: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:
            encolar(cola);
            imprimirCola(cola);
            break;
        case 2:
            desencolar(cola);
            imprimirCola(cola);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            
            break;            
        default:
            printf("\nOpción inválida.");
            break;
        }
    } while (opcion != 3);

}
