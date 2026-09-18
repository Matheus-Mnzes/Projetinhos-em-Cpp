#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
#include "contaeFuncoes.h"

using namespace std;

int main() {
	Conta contas[50];
	int opcoes, totalContas = 0;
	bool sair = false;

	//Função da biblioteca <locale.h> para trazer os caracteres do portugues para o código.
	setlocale(LC_ALL, "Portuguese_Brazil.utf8");

	while (sair != true) {

		//Opções do programa
		cout << "===========================\n";
		cout << "BANCO DIGITAL\n";
		cout << "===========================\n";
		cout << "1 - Criar conta\n";
		cout << "2 - Listar contas\n";
		cout << "3 - Consultar conta\n";
		cout << "4 - Depositar\n";
		cout << "5 - Sacar\n";
		cout << "6 - Sair\n";
		cout << "Escolha uma das opções: ";
		cin >> opcoes;
		cout << "===========================\n";

		//Função da biblioteca <cstdlib> para limpar o terminal bagunçado.
		system("cls");

		//Cadeia de if, else if e else que servem com um switch.
		if (opcoes == 1) {
			criarnoavaConta(contas, totalContas);
		}
		else if (opcoes == 2) {
			exibirContas(totalContas, contas);
		}
		else if (opcoes == 3) {
			consultaConta(contas, totalContas);
		}
		else if (opcoes == 4) {
			depositoConta(contas, totalContas);
		}
		else if (opcoes == 5) {
			saqueConta(contas, totalContas);
		}
		else if (opcoes == 6) {
			cout << "Saindo...\n";
			sair = true;
		}
		else {

		}
	}
}