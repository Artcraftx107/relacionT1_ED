#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Funcion para verificar si un numero esta en la lista
int contiene(struct Nodo* cabeza, int numero) {
	int wasContained = 0;
	bool found = false;
	struct Nodo* actual = cabeza;
	while (actual != NULL && !found) {
		if (actual->valor == numero) {
			found = true; // El numero ya esta en la lista
			wasContained=1;
		}
		actual = actual->siguiente;
	}
	return wasContained;  // El numero no esta en la lista
}

// Funcion para incluir un numero en la lista si no esta ya presente
void incluir(struct Nodo** cabeza, int numero) {
	// Verificar si el numero ya esta en la lista
	if (!contiene(*cabeza, numero)) {
		// Si no esta en la lista, lo agregamos al final
		agregarAlFinal(cabeza, numero);
	}
}

// Funcion principal para probar el subalgoritmo incluir
int main() {
	struct Nodo* lista = NULL;

	// Agregar algunos elementos a la lista
	agregarAlFinal(&lista, 1);
	agregarAlFinal(&lista, 3);
	agregarAlFinal(&lista, 5);

	printf("Lista original: ");
	imprimirLista(lista);

	// Probar la funcion incluir con un numero que no esta en la lista
	int numeroIncluir = 2;
	incluir(&lista, numeroIncluir);
	printf("Lista despuC)s de incluir %d: ", numeroIncluir);
	imprimirLista(lista);

	// Probar la funcion incluir con un numero que ya esta en la lista
	numeroIncluir = 3;
	incluir(&lista, numeroIncluir);
	printf("Lista despuC)s de intentar incluir %d (ya estC! en la lista): ", numeroIncluir);
	imprimirLista(lista);

	return 0;
}
