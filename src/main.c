#include <stdlib.h>
#include "cola.h"

int main(void){
    struct Cola *cola = malloc(sizeof(struct Cola));

    if(cola == NULL)
        return -1;

    cola->inicio = NULL;
    cola->fin = NULL;

    menu(cola);
    free(cola);    
return 0;
}