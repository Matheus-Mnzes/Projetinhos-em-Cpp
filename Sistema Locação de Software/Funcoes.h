#pragma once

#include <string>
#include "Funcoes.h"

using namespace std;

float obterValorLicenca() {
    return 150;
}

float calcularVenda(int quantidade, float valorLicenca) {
    return quantidade * valorLicenca;
}

void aplicarDesconto(float& valorTotal, int tipoDesconto) {
    if (tipoDesconto == 1) {
        valorTotal = valorTotal - (valorTotal * 0.1);
    }
    else if (tipoDesconto == 2) {
        valorTotal = valorTotal - (valorTotal * 0.15);
    }
    else if (tipoDesconto == 3) {
        valorTotal = valorTotal - (valorTotal * 0.2);
    }
    else {
        valorTotal = valorTotal;
    }
}

void exibirResumo(std::string cliente, int qtd, float valorFinal) {
    cout << "===========================\n";
    cout << "RESUMO DA LOCACAO\n";
    cout << "===========================\n";
    cout << "Cliente: " << cliente;
    cout << "\nLicenças: " << qtd;
    cout << "\nTotal pago: " << valorFinal << "R$";
    cout << "\n===========================\n";
}