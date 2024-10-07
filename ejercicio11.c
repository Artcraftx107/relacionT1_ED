#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura del nodo para numeros reales
struct Nodo {
	double valor;
	struct Nodo* siguiente;
};

// Funcion para crear un nuevo nodo
struct Nodo* crearNodo(double valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->valor = valor;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

// Funcion para agregar un valor en una lista enlazada ordenada
void insertarOrdenado(struct Nodo** cabeza, double valor) {
	struct Nodo* nuevoNodo = crearNodo(valor);

	// Si la lista esta vacia o el nuevo valor es menor que la cabeza
	if (*cabeza == NULL || (*cabeza)->valor > valor) {
		nuevoNodo->siguiente = *cabeza; // Insertar al inicio
		*cabeza = nuevoNodo;
	} else {
		// Buscar la posicion correcta para insertar el nuevo valor
		struct Nodo* actual = *cabeza;
		while (actual->siguiente != NULL && actual->siguiente->valor < valor) {
			actual = actual->siguiente;
		}

		// Insertar el nuevo nodo en la posicion adecuada
		nuevoNodo->siguiente = actual->siguiente;
		actual->siguiente = nuevoNodo;
	}
}

// Funcion para imprimir la lista (para fines de verificacion)
void imprimirLista(struct Nodo* cabeza) {
	struct Nodo* actual = cabeza;
	while (actual != NULL) {
		printf("%.2f -> ", actual->valor);
		actual = actual->siguiente;
	}
	printf("NULL\n");
}

int main() {
	struct Nodo* cabeza = NULL;

	// Insertar elementos de manera ordenada
	insertarOrdenado(&cabeza, 3.0);
	insertarOrdenado(&cabeza, 4.5);
	insertarOrdenado(&cabeza, 8.0);
	insertarOrdenado(&cabeza, 20.3);

	// Imprimir lista antes de la nueva insercion
	printf("Lista antes de insertar 6.0: ");
	imprimirLista(cabeza);

	// Insertar el valor 6.0 en la lista ordenada
	insertarOrdenado(&cabeza, 6.0);

	// Imprimir lista despues de insertar 6.0
	printf("Lista despues de insertar 6.0: ");
	imprimirLista(cabeza);

	return 0;
}
