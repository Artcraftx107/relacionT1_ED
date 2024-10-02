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

// Funcion para eliminar todas las apariciones de un numero en la lista enlazada
void eliminarValor(struct Nodo** cabeza, int numero) {
	struct Nodo* actual = *cabeza;
	struct Nodo* anterior = NULL;

	while (actual != NULL) {
		if (actual->valor == numero) {
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
			// Avanzar si no hay eliminacion
			anterior = actual;
			actual = actual->siguiente;
		}
	}
}

void eliminarRepetidos(struct Nodo** cabeza) {
	struct Nodo* actual = *cabeza;
	struct Nodo* siguienteNodo;

	while (actual != NULL) {
		// Contar cuantas veces aparece el valor actual
		int numReps = repeticiones(*cabeza, actual->valor);

		// Guardamos el siguiente nodo antes de eliminar el actual
		siguienteNodo = actual->siguiente;

		// Si el valor aparece mas de una vez, eliminar todas sus ocurrencias
		if (numReps > 1) {
			eliminarValor(cabeza, actual->valor);  // Elimina todas las instancias de este valor
		}

		// Avanzar al siguiente nodo guardado
		actual = siguienteNodo;
	}
}

// Funcion principal para probar el subalgoritmo repeticiones
int main() {
	struct Nodo* cabeza = NULL;

	// Agregar algunos nodos a la lista
	agregarAlFinal(&cabeza, 3);
	agregarAlFinal(&cabeza, 5);
	agregarAlFinal(&cabeza, 3);
	agregarAlFinal(&cabeza, 7);
	agregarAlFinal(&cabeza, 5);
	agregarAlFinal(&cabeza, 9);
	agregarAlFinal(&cabeza, 3);

	// Imprimir lista antes de eliminar repetidos
	printf("Lista original: ");
	imprimirLista(cabeza);

	// Eliminar repetidos (todas las instancias de numeros repetidos)
	eliminarRepetidos(&cabeza);

	// Imprimir lista despues de eliminar repetidos
	printf("Lista sin repetidos: ");
	imprimirLista(cabeza);

	return 0;
}