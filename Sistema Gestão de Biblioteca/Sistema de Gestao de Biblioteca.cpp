#include <iostream>
#include <locale.h>
#include <cstdlib>
#include "funcoesBiblioteca.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese_Brazil.utf8");

	Livro acervo[20];
	Livro estante[3][4];
	int totalLivros = 0, opcoes, idLivro;
	bool sair = false;
	string autorBusca;

	while (sair != true) {

		cout << "-----------------------------\n";
		cout << "SISTEMA GESTÃO DE BIBLIOTECA\n";
		cout << "-----------------------------\n";

		cout << "Menu de opções:\n";
		cout << "1.Cadastrar Livro\n";
		cout << "2.Organizar e Visualizar Estante\n";
		cout << "3.Buscar Livros por Autor\n";
		cout << "4.Realizar Empréstimo de Livro\n";
		cout << "5.Sair\n";
		cin >> opcoes;
		system("cls");

		if (opcoes == 1) {
			cout << "-------------------------\n";
			cout << "Cadastro de um novo livro\n";
			cout << "-------------------------\n";

			cadastrarLivro(acervo, totalLivros);
		}
		else if (opcoes == 2) {
			cout << "---------------------------\n";
			cout << "Organizar e exibir estante\n";
			cout << "---------------------------\n";

			organizarEstante(estante, acervo, totalLivros);
			exibirEstante(estante);
		}
		else if (opcoes == 3) {

			cout << "------------------------\n";
			cout << "Buscar Livros por Autor\n";
			cout << "------------------------\n";

			cout << "Digite o autor que deseja buscar: ";
			cin >> autorBusca;

			buscarPorAutor(acervo, totalLivros, autorBusca);
		}
		else if (opcoes == 4) {

			cout << "-----------------------------\n";
			cout << "Realizar Empréstimo de Livro\n";
			cout << "-----------------------------\n";

			cout << "Qual o id do livro que voc  deseja? ";
			cin >> idLivro;

			if(realizarEmprestimo(estante, acervo, totalLivros, idLivro) == true){
				cout << "Livro emprestado.\n";
			}
			else {
				cout << "Livro não encontrado ou indisponivel.\n";
			}
		}
		else if (opcoes == 5) {
			cout << "Saindo...";
			sair = true;
		}
		else {
			cout << "Essa opção não existe.\n";
		}
	}
}