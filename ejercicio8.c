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

// Funcion para contar las repeticiones de un numero en la lista enlazada
int repeticiones(struct Nodo* cabeza, int numero) {
	int contador = 0;
	struct Nodo* actual = cabeza;

	while (actual != NULL) {
		if (actual->valor == numero) {
			contador++;  // Incrementar contador cuando se encuentra el numero
		}
		actual = actual->siguiente;
	}

	return contador;
}

// Funcion principal para probar el subalgoritmo repeticiones
int main() {
	struct Nodo* lista = NULL;

	// Agregar algunos elementos a la lista
	agregarAlFinal(&lista, 1);
	agregarAlFinal(&lista, 4);
	agregarAlFinal(&lista, 3);
	agregarAlFinal(&lista, 6);
	agregarAlFinal(&lista, 3);
	agregarAlFinal(&lista, 7);

	printf("Lista original: ");
	imprimirLista(lista);

	// Probar la funcion repeticiones con un numero que aparece varias veces
	int numeroBuscar = 3;
	int resultado = repeticiones(lista, numeroBuscar);
	printf("El numero %d aparece %d veces en la lista.\n", numeroBuscar, resultado);

	// Probar la funcion repeticiones con un numero que no esta en la lista
	numeroBuscar = 8;
	resultado = repeticiones(lista, numeroBuscar);
	printf("El numero %d aparece %d veces en la lista.\n", numeroBuscar, resultado);

	return 0;
}