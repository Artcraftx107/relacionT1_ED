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

// Función para contar el tamaño de la lista enlazada
int contarElementos(struct Nodo* cabeza) {
    int contador = 0;
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// Función para buscar la primera aparición de un número en la lista enlazada
int buscarPrimero(struct Nodo* cabeza, int numero) {
    struct Nodo* actual = cabeza;
    int posicion = 0;
    bool found = false; 
    // Recorrer la lista
    while (actual != NULL && !found) {
        if (actual->valor == numero) {
            found = true;   // Devolver la posición si el número es encontrado
        }else{
            actual = actual->siguiente;
            posicion++;
        }
    }
    
    // Si no se encuentra, devolver el tamaño de la lista
    if(!found){
        posicion= contarElementos(cabeza);
    }
    
    return posicion; 
}

// Función principal
int main() {
    struct Nodo* lista = NULL;

    // Agregar elementos a la lista
    agregarAlFinal(&lista, 1);
    agregarAlFinal(&lista, 5);
    agregarAlFinal(&lista, 1);

    imprimirLista(lista);

    // Probar la función buscarPrimero
    int numeroBuscado = 1;
    int posicion = buscarPrimero(lista, numeroBuscado);
    printf("La primera aparicion del numero %d esta en la posicion: %d\n", numeroBuscado, posicion);

    numeroBuscado = 6;
    posicion = buscarPrimero(lista, numeroBuscado);
    printf("El numero %d no esta en la lista, devolver el tamaño de la lista: %d\n", numeroBuscado, posicion);

    return 0;
}
