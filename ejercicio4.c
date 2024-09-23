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

// Función para eliminar la última aparición de un número en la lista enlazada
void eliminarUltimo(struct Nodo** cabeza, int numero) {
    struct Nodo* actual = *cabeza;
    struct Nodo* anterior = NULL;
    struct Nodo* ultimoNodo = NULL; // Para almacenar la última aparición
    struct Nodo* anteriorUltimo = NULL; // Para almacenar el nodo anterior al último

    // Recorrer la lista para encontrar la última aparición
    while (actual != NULL) {
        if (actual->valor == numero) {
            ultimoNodo = actual; // Actualizar el último nodo encontrado
            anteriorUltimo = anterior; // Actualizar el nodo anterior al último
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si se encontró la última aparición
    if (ultimoNodo != NULL) {
        if (anteriorUltimo == NULL) {
            // El nodo a eliminar es el primero
            *cabeza = ultimoNodo->siguiente; // Mover la cabeza al siguiente nodo
        } else {
            // Ajustar el puntero del nodo anterior
            anteriorUltimo->siguiente = ultimoNodo->siguiente;
        }
        free(ultimoNodo); // Liberar la memoria del nodo eliminado
    }
}

// Función principal
int main() {
    struct Nodo* lista = NULL;

    // Agregar elementos a la lista
    agregarAlFinal(&lista, 1);
    agregarAlFinal(&lista, 5);
    agregarAlFinal(&lista, 1);
    agregarAlFinal(&lista, 6);

    printf("Lista original: ");
    imprimirLista(lista);

    // Probar la función eliminarUltimo
    int numeroEliminar = 1;
    eliminarUltimo(&lista, numeroEliminar);
    printf("Lista después de eliminar la última aparición de %d: ", numeroEliminar);
    imprimirLista(lista);

    numeroEliminar = 7;
    eliminarUltimo(&lista, numeroEliminar);
    printf("Lista después de intentar eliminar el %d (no estaba en la lista): ", numeroEliminar);
    imprimirLista(lista);

    return 0;
}
