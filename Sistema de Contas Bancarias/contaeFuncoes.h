#pragma once
#include <string>
using namespace std;

//Struct com os dados que cada conta vai ter.
struct Conta {
	int numero;
	string titular;
	float saldo = 0;
};

//Função que cria uma nova conta.
void criarnoavaConta(Conta contas[], int& totalContas) {
	cout << "NOVA CONTA\n\n";
	cout << "Digite o numero da conta: ";
	cin >> contas[totalContas].numero;
	cout << "Digite o nnome do Titular: ";
	cin >> contas[totalContas].titular;

	totalContas++;
}

//Função que mostras as contas até então criadas.
void exibirContas(int totalContas, Conta contas[]) {
	cout << "CONTAS\n\n";
	for (int i = 0; i < totalContas; i++) {
		cout << "Titular: " <<contas[i].titular << "\n";
	}
}

//Função que pede ao usuario o numero da conta que ele quer acessar para obter os outros dados da conta.
void consultaConta(Conta contas[], int totalContas) {
	int numero, k = 0;
	cout << "CONSULTA\n\n";
	cout << "Qual o numero da conta que voce deseja consultar? ";
	cin >> numero;

	for (int i = 0; i < totalContas; i++) {
		if (contas[i].numero == numero) {
			cout << "Titular: " << contas[i].titular << "\n";
			cout << "Saldo da conta: " << contas[i].saldo << "\n";
			k++;
		}
	}
	if (k == 0) {
		cout << "Conta nao encontrada\n";
	}
}

//Função que permite o usuário a dicionar saldo a sua conta.
void depositoConta(Conta contas[], int totalContas) {
	float deposito;
	int numero, k = 0;
	cout << "DEPOSITO\n\n";
	cout << "Qual o numero da sua conta? ";
	cin >> numero;
	cout << "Quanto voce deseja depositar? ";
	cin >> deposito;

	for (int i = 0; i < totalContas; i++) {
		if (contas[i].numero == numero) {
			contas[i].saldo += deposito;
			k++;
			cout << "Deposito feito.\n";
		}
	}
	if (k == 0) {
		cout << "Conta nao encontrada\n";
	}
}

//Função que permite o usuário sacar parte do saldo da sua conta.
void saqueConta(Conta contas[], int totalContas) {
	float saque;
	int numero, k = 0;
	cout << "SAQUE\n\n";
	cout << "Qual o numero da sua conta? ";
	cin >> numero;
	cout << "Quanto voce deseja sacar? ";
	cin >> saque;

	for (int i = 0; i < totalContas; i++) {
		if (contas[i].numero == numero) {
			if (saque <= contas[i].saldo) {
				contas[i].saldo -= saque;
				cout << "Saque feito.\n";
			}
			else {
				cout << "Voce nao tem saldo o suficiente para essa transacao.\n";
			}
			k++;
		}
	}
	if (k == 0) {
		cout << "Conta nao encontrada\n";
	}
}