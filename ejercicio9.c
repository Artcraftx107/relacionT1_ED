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
// Funcion para eliminar todas las apariciones de un numero en la lista enlazada, menos la primera aparicion
void eliminarRepeticiones(struct Nodo** cabeza, int numero) {
	struct Nodo* actual = *cabeza;
	struct Nodo* anterior = NULL;
	int repeticiones = 0;

	while (actual != NULL) {
		if (actual->valor == numero && repeticiones>0) {
			// Si el nodo a eliminar es el primero
			if (anterior == NULL) {
				*cabeza = actual->siguiente;  // Mover la cabeza al siguiente nodo
				free(actual);  // Liberar la memoria del nodo eliminado
				actual = *cabeza;  // Actualizar el puntero actual
			} else {
				anterior->siguiente = actual->siguiente;  // Saltar el nodo actual
				free(actual);  // Liberar la memoria del nodo eliminado
				actual = anterior->siguiente;  // Actualizar el puntero actual
			}
		} else {
			//Si la primera aparicion del numero se ha registrado, especificar que se eliminen las siguientes.
			if(actual->valor==numero) {
				repeticiones++;
			}
			// Avanzar si no hay eliminacion
			anterior = actual;
			actual = actual->siguiente;
		}
	}
}

// Funcion principal para probar el algoritmo
int main() {
	struct Nodo* lista = NULL;

	// Agregar elementos a la lista
	agregarAlFinal(&lista, 1);
	agregarAlFinal(&lista, 3);
	agregarAlFinal(&lista, 5);
	agregarAlFinal(&lista, 3);
	agregarAlFinal(&lista, 7);
	agregarAlFinal(&lista, 3);
	agregarAlFinal(&lista, 9);

	// Imprimir la lista original
	printf("Lista original:\n");
	imprimirLista(lista);

	// Eliminar las repeticiones del numero 3
	eliminarRepeticiones(&lista, 3);

	// Imprimir la lista despues de eliminar las repeticiones
	printf("\nLista despues de eliminar repeticiones del 3 (excepto la primera):\n");
	imprimirLista(lista);

	// Liberar la memoria de los nodos restantes
	struct Nodo* actual = lista;
	while (actual != NULL) {
		struct Nodo* temp = actual;
		actual = actual->siguiente;
		free(temp);
	}

	return 0;
}