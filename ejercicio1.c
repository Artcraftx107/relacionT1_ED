#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Función para verificar si la lista contiene un número
bool contiene(struct Nodo* cabeza, int numero) {
    bool aux = false; 
    struct Nodo* actual = cabeza;
    while (actual != NULL && !aux) {
        if (actual->valor == numero) {
            aux= true;  // Si el número se encuentra en la lista, devolver true
        }
        actual = actual->siguiente;  // Avanzar al siguiente nodo
    }
    return aux;  // Si se llega al final de la lista sin coincidencias, devolver false
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

// Función principal
int main() {
    struct Nodo* lista = NULL;

    // Agregar elementos a la lista
    agregarAlFinal(&lista, 1);
    agregarAlFinal(&lista, 5);
    agregarAlFinal(&lista, 6);

    imprimirLista(lista);

    // Probar la función contiene
    int numeroBuscado = 5;
    if (contiene(lista, numeroBuscado)) {
        printf("La lista contiene el numero %d.\n", numeroBuscado);
    } else {
        printf("La lista NO contiene el numero %d.\n", numeroBuscado);
    }

    numeroBuscado = 7;
    if (contiene(lista, numeroBuscado)) {
        printf("La lista contiene el numero %d.\n", numeroBuscado);
    } else {
        printf("La lista NO contiene el numero %d.\n", numeroBuscado);
    }

    return 0;
}
