#pragma once

using namespace std;
struct Livro {
	int id;
	string titulo;
	string autor;
	int anoPublicacao;
	bool disponivel;
};

void cadastrarLivro(Livro acervo[], int& totalLivros) {

	cout << "Digite o id do livro: ";
	cin >> acervo[totalLivros].id;
	cout << "Digite o titulo do livro: ";
	cin >> acervo[totalLivros].titulo;
	cout << "Digite o autor do livro: ";
	cin >> acervo[totalLivros].autor;
	cout << "Digite o ano de Publicação do livro: ";
	cin >> acervo[totalLivros].anoPublicacao;

	acervo[totalLivros].disponivel = true;
	totalLivros++;
}

void organizarEstante(Livro estante[3][4], Livro acervo[], int totalLivros) {
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (k < totalLivros) {
				estante[i][j] = acervo[k];
				k++;
			}
			else {
				estante[i][j].id = 0;
			}
		}
	}
}

void exibirEstante(const Livro estante[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (estante[i][j].id == 0) {
				cout << "VAZIO ";
			}
			else {
				cout << "Titulo:" << estante[i][j].titulo << " ";
			}
			cout << "id:" << estante[i][j].id << "   ";
		}
		cout << "\n";
	}
}

void buscarPorAutor(const Livro acervo[], int totalLivros, string autorBusca) {
	int j = 0;
	for (int i = 0; i < 3; i++) {
		if (acervo[i].autor == autorBusca) {
			cout << acervo[i].titulo << "\n";
			j++;
		}
	}
	if (j == 0) {
		cout << "Autor não encontrado\n";
	}
}

bool realizarEmprestimo(Livro estante[3][4], Livro acervo[], int totalLivros, int idLivro) {
	int indexAcervo = -1;
	for (int i = 0; i < totalLivros; i++) {
		if (acervo[i].id == idLivro) {
			indexAcervo = i;
			break;
		}
	}

	if (indexAcervo == -1 || !acervo[indexAcervo].disponivel) {
		return false;
	}

	acervo[indexAcervo].disponivel = false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (estante[i][j].id == idLivro) {
				estante[i][j].disponivel = false;
			}
		}
	}
	return true;
}





