#pragma once
	/*
		STRUCT CARTA
		Ele ser� respons�vel por guardar os atr�butos de uma carta(linguagem de programa��o)
	*/
	struct carta {
		char nome[50];
		unsigned short int popularidade;
		unsigned short int tipagem;
		unsigned short int sintaxe;
		unsigned short int desempenho;
		unsigned short int facilidadeDeUso;
	};

	int Leitor(const char * arquivo,);