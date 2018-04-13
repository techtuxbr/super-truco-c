#include <fstream>
#include <iostream>
#include <iomanip>
#include "cartas.h"
#include "utilitarios.h"

using namespace std;

unsigned short int Leitor(const char * arquivo, carta cartasNoArquivo[]) {
	ofstream fout;
	ifstream fin;
	carta cartaAuxiliar;
	unsigned short int numeroDeCartasNaLeitura = 0;
	fin.open(arquivo, ios_base::in | ios_base::binary);
	int c = 0;
	while (fin.read((char*)&cartaAuxiliar, sizeof(carta))) {
		if (numeroDeCartasNaLeitura > 32) {
			fin.close();
			return numeroDeCartasNaLeitura;
		}
		cartasNoArquivo[c] = cartaAuxiliar;
		numeroDeCartasNaLeitura++;
		c++;
	}
	fin.close();
	return numeroDeCartasNaLeitura;
}

unsigned short int CadastrarCarta(carta linguagem, carta * cartas, unsigned short int numeroDeCartasNaExecucao) {

	if (numeroDeCartasNaExecucao == 0) {
		cartas[0] = linguagem;
		numeroDeCartasNaExecucao++;
	}
	else {
		cartas[numeroDeCartasNaExecucao] = linguagem;
		numeroDeCartasNaExecucao++;
	}


	return numeroDeCartasNaExecucao;
}

void ListarCartas(carta * cartas, unsigned short int numeroDeCartasNaExecucao) {
	for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
		cout << i + 1 << " ) " << cartas[i].nome << endl;
	}
}

void AlterarCarta(carta * cartas, unsigned short int opcao) {
	cout << "\n Alterando carta " << cartas[opcao - 1].nome << endl;
	gerarLinha('-', 20);
	cout << "Nome : ";
	cin.getline(cartas[opcao - 1].nome, 80);
	cout << "Popularidade : ";
	cin >> cartas[opcao - 1].popularidade;
	cout << "Tipagem : ";
	cin >> cartas[opcao - 1].tipagem;
	cout << "Sintaxe : ";
	cin >> cartas[opcao - 1].sintaxe;
	cout << "Desempenho : ";
	cin >> cartas[opcao - 1].desempenho;
	cout << "Facilidade de uso : ";
	cin >> cartas[opcao - 1].facilidadeDeUso;
}

unsigned short int ExcluirCarta(carta * cartas, unsigned short int opcao, unsigned short int numeroDeCartasNaExecucao) {
	carta ultima;
	ultima = cartas[numeroDeCartasNaExecucao - 1];
	carta escolhida;
	escolhida = cartas[opcao - 1];
	cartas[opcao - 1] = ultima;
	cartas[numeroDeCartasNaExecucao - 1] = escolhida;
	numeroDeCartasNaExecucao--;
	return numeroDeCartasNaExecucao;
}

void TabelaDeCartas(carta * cartas, unsigned short int numeroDeCartasNaExecucao) {
	cout << "\nCartas no baralho: " << endl;
	gerarLinha('-', 30);


	for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
		cout << setw(1) << "#" << i + 1 << " ";
		cout << setw(14) << cartas[i].nome;
		cout << setw(5) << cartas[i].popularidade;
		cout << setw(5) << cartas[i].tipagem;
		cout << setw(5) << cartas[i].sintaxe;
		cout << setw(5) << cartas[i].desempenho;
		cout << setw(5) << cartas[i].facilidadeDeUso;
		cout << endl;
	}
	cout << endl;
}

void Gravador(const char * arquivo, carta * cartas, unsigned short int numeroDeCartasNaExecucao){

	ofstream fout;
	ifstream fin;

	carta * cartasDin = new carta[numeroDeCartasNaExecucao];
	for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
		cartasDin[i] = cartas[i];
	}
	fout.open(arquivo, ios_base::out | ios_base::binary);
	for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
		fout.write((char*)&cartasDin[i], sizeof(carta));
	}
	fout.close();
	delete[] cartasDin;
}
