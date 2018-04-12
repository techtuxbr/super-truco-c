#include <iostream>
#include <fstream>
#include "cartaHelper.h"
using namespace std;

// Prototipos
	void gerarLinha(char c, unsigned short int tam);

int main() {
	
	
	ofstream fout;
	ifstream fin;
	 
	carta cartas[32];
	carta cartaAuxiliar;

	unsigned short int numeroDeCartasNaLeitura = 0;
	unsigned short int numeroDeCartasNaExecucao = 0;
	unsigned short int opcao;
	bool sair = false;

	fin.open("cartas.deck", ios_base::in | ios_base::binary);
	int c = 0;
	while (fin.read((char*)&cartaAuxiliar, sizeof(carta))){
		cartas[c] = cartaAuxiliar;
		numeroDeCartasNaLeitura++;
		c++;
	}
	fin.close();


	numeroDeCartasNaExecucao = numeroDeCartasNaLeitura;
	do {
		cout << "Gerador de cartas \n";
		gerarLinha('-', 20);

		cout << "1) " << "Cadastrar\n";
		cout << "2) " << "Alterar\n";
		cout << "3) " << "Excluir\n";
		cout << "4) " << "Listar\n";
		cout << "5) " << "Sair\n";

		cout << "Escolha uma opcao: ";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
			carta linguagem;
			cout << "\n Cadastrar carta: \n";
			gerarLinha('-', 20);
			cout << "Nome : ";
			cin >> linguagem.nome;
			cout << "Popularidade : ";
			cin >> linguagem.popularidade;
			cout << "Tipagem : ";
			cin >> linguagem.tipagem;
			cout << "Sintaxe : ";
			cin >> linguagem.sintaxe;
			cout << "Desempenho : ";
			cin >> linguagem.desempenho;
			cout << "Facilidade de uso : ";
			cin >> linguagem.facilidadeDeUso;

			if (numeroDeCartasNaExecucao == 0) {
				cartas[0] = linguagem;
				numeroDeCartasNaExecucao++;
			}
			else {
				cartas[numeroDeCartasNaExecucao] = linguagem;
				numeroDeCartasNaExecucao++;
			}
			break;
		case 2:
			
			cout << "\n Atualizar cartas \n";
			gerarLinha('-', 25);
			for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
				cout << i + 1 << " ) " << cartas[i].nome << endl;
			}

			cout << "\n Digite o numero da carta: ";
			cin >> opcao;

			if (opcao > numeroDeCartasNaExecucao) {
				break;
			}
			cout << "\n Alterando carta " << cartas[opcao - 1].nome << endl;
			gerarLinha('-', 20);
			cout << "Nome : ";
			cin >> cartas[opcao - 1].nome;
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
			break;
		case 3:

			carta escolhida;
			carta ultima;

			cout << "\n Excluir cartas \n";
			gerarLinha('-', 25);
			for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
				cout << i + 1 << " ) " << cartas[i].nome << endl;
			}

			cout << "\n Digite o numero da carta: ";
			cin >> opcao;

			if (opcao > numeroDeCartasNaExecucao) {
				break;
			}

			escolhida = cartas[opcao - 1];
			ultima = cartas[numeroDeCartasNaExecucao-1];

			cartas[opcao - 1] = ultima;
			cartas[numeroDeCartasNaExecucao - 1] = escolhida;
			numeroDeCartasNaExecucao--;
			break;
		case 4:

			cout << "\nCartas no baralho: " << endl;
			gerarLinha('-', 30);

			for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
				cout << "#" << i + 1; 
				cout.width(9);
				cout << cartas[i].nome;\
				cout.width(6);
				cout << cartas[i].popularidade;
				cout.width(6);
				cout << cartas[i].tipagem;
				cout.width(6);
				cout << cartas[i].sintaxe;
				cout.width(6);
				cout << cartas[i].desempenho;
				cout.width(6);
				cout << cartas[i].facilidadeDeUso;
				cout << endl;
			}
			cout << endl;
			break;
		case 5:
			sair = true;
			break;
		default:
			break;
		}
	} while (!sair);
	
	carta * cartasDin = new carta[numeroDeCartasNaExecucao];
	for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
		cartasDin[i] = cartas[i];
	}
	fout.open("cartas.deck", ios_base::out | ios_base::binary);
	for (int i = 0; i < numeroDeCartasNaExecucao; i++) {
		fout.write((char*)&cartasDin[i], sizeof(carta));
	}
	fout.close();
	delete[] cartasDin;
	return 0;
}

void gerarLinha(char c, unsigned short int tam) {
	for (int i = 0; i <= tam; i++) {
		cout << c;
	}
	cout << "\n";
}