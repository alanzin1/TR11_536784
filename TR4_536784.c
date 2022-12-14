
// incluindo a nossa biblioteca

#include "ordvetor.h"

//Aluno: alan victor soares vieira 
//matricula: 536784

//criacao e alocacao de memoria para uma nova struct

VETORORD* VETORD_create(int n, COMP* compara) {
	VETORORD* vetor = malloc(sizeof(VETORORD));
	vetor->N = n;
	vetor->P = 0;
	vetor->elems = malloc(n * sizeof(void*));
	vetor->comparador = compara;
	return vetor;
}

// metodo para adicionar e verificar um valor

void VETORD_add(VETORORD* vetor, void* newelem) {
	if (vetor->P < vetor->N) {
		int posicao = vetor->P;

		for (int i = 0; i < vetor->P; i++) {
			if (vetor->comparador(vetor->elems[i], newelem) == -1) {
				posicao = i;
				break;
			}
		}

		for (int i = vetor->P; i > posicao; i--) {
			vetor->elems[i] = vetor->elems[i - 1];
		}

		vetor->elems[posicao] = newelem;
		vetor->P++;
	}	
}


//metodo de remocao

void* VETORD_remove(VETORORD* vetor) {
	void* menor = vetor->elems[0];

	for (int i = 0; i < vetor->P - 1; i++) {
		vetor->elems[i] = vetor->elems[i + 1];
	}
	
	vetor->P--;

	return menor;
}
