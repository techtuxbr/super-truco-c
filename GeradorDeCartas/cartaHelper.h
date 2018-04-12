#pragma once
	/*
		STRUCT CARTA
		Ele será responsável por guardar os atríbutos de uma carta(linguagem de programação)
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