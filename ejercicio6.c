#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura del nodo
struct Nodo {
	int valor;
	struct Nodo* siguiente;
};

// Funcion para crear un nuevo nodo
struct Nodo* crearNodo(int valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->valor = valor;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

// Funcion para agregar un nodo al final de la lista
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

// Funcion para imprimir la lista (para fines de verificacion)
void imprimirLista(struct Nodo* cabeza) {
	struct Nodo* actual = cabeza;
	while (actual != NULL) {
		printf("%d -> ", actual->valor);
		actual = actual->siguiente;
	}
	printf("NULL\n");
}

// Funcion para invertir el orden de los valores de una lista enlazada
void invertir(struct Nodo** cabeza) {
	struct Nodo* actual = *cabeza;
	struct Nodo* anterior = NULL;
	struct Nodo* siguiente = NULL;

	while (actual!=NULL) {
		siguiente=actual->siguiente;
		actual->siguiente=anterior;
		anterior=actual;
		actual=siguiente;
	}

	*cabeza=anterior;
}

// Funcion principal para probar la inversion de la lista
int main() {
	struct Nodo* lista = NULL;

	// Agregar elementos a la lista
	agregarAlFinal(&lista, 20);
	agregarAlFinal(&lista, 69);
	agregarAlFinal(&lista, 35);

	printf("Lista original: ");
	imprimirLista(lista);

	// Invertir la lista
	invertir(&lista);

	printf("Lista invertida: ");
	imprimirLista(lista);

	return 0;
}