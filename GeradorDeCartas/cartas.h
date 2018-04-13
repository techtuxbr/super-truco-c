#pragma once
	/*
		STRUCT CARTA
		Ele será responsável por guardar os atríbutos de uma carta(linguagem de programação)
	*/
	struct carta {
		char nome[80];
		unsigned short int popularidade;
		unsigned short int tipagem;
		unsigned short int sintaxe;
		unsigned short int desempenho;
		unsigned short int facilidadeDeUso;
	};

	unsigned short int Leitor(const char * arquivo,carta cartasNoArquivo[]);
	unsigned short int CadastrarCarta(carta linguagem, carta * cartas, unsigned short int numeroDeCartasNaExecucao);
	unsigned short int ExcluirCarta(carta * cartas, unsigned short int opcao, unsigned short int numeroDeCartasNaExecucao);
	void ListarCartas(carta * cartas, unsigned short int numeroDeCartasNaExecucao);
	void AlterarCarta(carta * cartas, unsigned short int opcao);
	void TabelaDeCartas(carta * cartas, unsigned short int numeroDeCartasNaExecucao);
	void Gravador(const char * arquivo, carta * cartas, unsigned short int numeroDeCartasNaExecucao);