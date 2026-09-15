#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
#include "Funcoes.h"

using namespace std;

int main() {
    float quantidade, valorLicenca, valorTotal;
    int tipoDesconto;
    char desconto;
    std::string nome;

    setlocale(LC_ALL, "Portuguese_Brazil.utf8");

    cout << "=================================\n";
    cout << "           CADASTRO\n";
    cout << "=================================\n";

    cout << "\nNome do cliente: ";
    cin >> nome;
    cout << "\n";

    system("cls");

    cout << "=================================\n";
    cout << "SISTEMA DE LOCACAO DE SOFTWARES\n";
    cout << "=================================\n";

    cout << "\nQuantidade de Licenças: ";
    cin >> quantidade;

    valorLicenca = obterValorLicenca();
    cout << "\nValor unitario: " << valorLicenca << "\n";

    valorTotal = calcularVenda(quantidade, valorLicenca);
    cout << "\nValor total da venda: " << valorTotal << "\n";

    cout << "\nDeseja aplicar desconto? S/N: ";
    cin >> desconto;
    if (desconto == 'S' || desconto == 's') {
        cout << "\nQual desconto deseja aplicar?\n";
        cout << "1 - Estudante (10%)\n";
        cout << "2 - Empresa Parceira (15%)\n";
        cout << "3 - Cliente Premium (20%)\n";
        cin >> tipoDesconto;

        aplicarDesconto(valorTotal, tipoDesconto);
        cout << "\nValor com desconto: " << valorTotal << "\n";
    }

    system("cls");

    exibirResumo(nome, quantidade, valorTotal);

    return 0;
}