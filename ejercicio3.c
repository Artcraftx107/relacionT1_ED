#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Nodo {
    int valor;
    struct Nodo* siguiente;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para agregar un nodo al final de la lista
void agregarAlFinal(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista (para fines de verificación)
void imprimirLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función para eliminar la primera aparición de un número en la lista enlazada
void eliminarPrimero(struct Nodo** cabeza, int numero) {
    struct Nodo* actual = *cabeza;
    struct Nodo* anterior = NULL;

    // Recorrer la lista para encontrar el número
    while (actual != NULL) {
        if (actual->valor == numero) {
            // Si el nodo a eliminar es el primero
            if (anterior == NULL) {
                *cabeza = actual->siguiente;  // Mover la cabeza al siguiente nodo
            } else {
                anterior->siguiente = actual->siguiente;  // Saltar el nodo actual
            }
            free(actual);  // Liberar la memoria del nodo eliminado
            return;  // Salir después de eliminar la primera aparición
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    // Si no se encuentra el número, no hacemos nada
}

// Función principal
int main() {
    struct Nodo* lista = NULL;

    // Agregar elementos a la lista
    agregarAlFinal(&lista, 2);
    agregarAlFinal(&lista, 30);
    agregarAlFinal(&lista, 5);

    printf("Lista original: ");
    imprimirLista(lista);

    // Probar la función eliminarPrimero
    int numeroEliminar = 2;
    eliminarPrimero(&lista, numeroEliminar);
    printf("Lista después de eliminar el primer %d: ", numeroEliminar);
    imprimirLista(lista);

    numeroEliminar = 6;
    eliminarPrimero(&lista, numeroEliminar);
    printf("Lista después de intentar eliminar el %d (no estaba en la lista): ", numeroEliminar);
    imprimirLista(lista);
    
    numeroEliminar = 5; 
    eliminarPrimero(&lista, numeroEliminar); 
    printf("Lista despues de intentar eliminar el %d: ", numeroEliminar); 
    imprimirLista(lista); 
    
    return 0;
}
