#include "utilitarios.h"
#include <iostream>

void gerarLinha(char c, unsigned short int tam) {
	using namespace std;
	for (int i = 0; i <= tam; i++) {
		cout << c;
	}
	cout << "\n";
}

bool validarOpcao(unsigned short int opcao, unsigned short int numeroDeCartasNaExecucao) {
	if (opcao > numeroDeCartasNaExecucao) {
		return false;
	}
	else if(opcao < 1) {
		return false;
	}
	else {
		return true;
	}
}