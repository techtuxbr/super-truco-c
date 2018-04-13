#include <iostream>
#include <fstream>
#include <limits>
#include "cartas.h"
#include "utilitarios.h"

int main() {
	using namespace std;	
	unsigned short int numeroDeCartasNaExecucao = 0;
	unsigned short int opcao;
	bool sair = false;
	carta cartas[32];
	char nome[20];

	numeroDeCartasNaExecucao = Leitor("cartas.deck", cartas);
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (opcao)
		{
		case 1:
			carta linguagem;
			cout << "\n Cadastrar carta: \n";
			gerarLinha('-', 20);
			cout << "Nome : ";
			cin.getline(linguagem.nome,80);
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
			numeroDeCartasNaExecucao = CadastrarCarta(linguagem, cartas, numeroDeCartasNaExecucao);
			break;
		case 2:
			cout << "\n Alterar cartas \n";
			gerarLinha('-', 25);
			ListarCartas(cartas, numeroDeCartasNaExecucao);
			cout << "\n Digite o numero da carta: ";
			cin >> opcao;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (!validarOpcao(opcao, numeroDeCartasNaExecucao)) {
				break;
			}
			AlterarCarta(cartas, opcao);
			break;
		case 3:
			cout << "\n Excluir carta \n";
			gerarLinha('-', 25);
			ListarCartas(cartas, numeroDeCartasNaExecucao);
			cout << "\n Digite o numero da carta: ";
			cin >> opcao;
			if (!validarOpcao(opcao, numeroDeCartasNaExecucao)) {
				break;
			}
			numeroDeCartasNaExecucao = ExcluirCarta(cartas, opcao, numeroDeCartasNaExecucao);
			break;
		case 4:
			TabelaDeCartas(cartas, numeroDeCartasNaExecucao);
			break;
		case 5:
			sair = true;
			break;
		default:
			cout << "Opção inválida, tente novamente" << endl;
			break;
		}
	} while (!sair);
	Gravador("cartas.deck", cartas, numeroDeCartasNaExecucao);
	return 0;
}