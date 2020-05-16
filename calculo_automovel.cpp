#include <iostream>
#include <locale>
using namespace std;

// DECLARA��O DE VARI�VEIS
float valorFabrica, valorAcrescimo, valorTotal;
int opcoes, cValorFabrica, cTrioEletrico, cArCondicionado, cDirecaoHidraulica, cCompleto;
char escolha;

// FUN��O QUE MOSTRA RESULTADO DO VALOR TOTAL
void totalUsuario(){
	setlocale(LC_ALL, "C");
	cout << "\n\n#################### VALOR TOTAL ####################";
	printf("\nValor total: R$%.3f", valorFabrica + valorAcrescimo);
}

void escolhaUsuario(){
	setlocale(LC_ALL, "");
	cout << "\n\n#################### OP��ES ESCOLHIDAS ####################";
	cout << "\nValor de f�brica: " << cValorFabrica;
	cout << "\nTrio el�trico: " << cTrioEletrico;
	cout << "\nAr condicionado: " << cArCondicionado;
	cout << "\nDire��o hidr�ulica: " << cDirecaoHidraulica;
	cout << "\nCompleto: " << cCompleto;
}

int main(){
	setlocale(LC_ALL, "");
	
	cout << "Insira o valor de f�brica: ";
	cin >> valorFabrica;
	
	do{
		cout << "\n\n#################### MENU DE OP��ES ####################";
		cout << "\nPressione a(s) op��o(�es) que o cliente deseja";
		cout << "\nOp��o 0: somente o valor de f�brica (sem opcionais)"; // 2% do valor de f�brica com IPI
		cout << "\nOp��o 1: trio el�trico (alarme, vidro el�trico e tranca el�trica)"; // 2% do valor de f�brica do modelo (sem o IPI)
		cout << "\nOp��o 2: ar condicionado"; // 2% do valor de f�brica do modelo (sem o IPI)
		cout << "\nOp��o 3: dire��o hidr�ulica"; // 2% do valor de f�brica do modelo (sem o IPI)
		cout << "\nOp��o 4: completo (trio el�trico, ar condicionado e dire��o hidr�ulica)"; // a soma dos acr�scimos isolados
		//O IPI dos autom�veis � de 8% do valor de f�brica
		
		cout << "\n\nDigite a op��o desejada: ";
		cin >> opcoes;
		
		switch(opcoes){
			case 0:
				cout << "\nValor de f�brica sem acr�scimos";
				cValorFabrica += 1;
				break;
			case 1:
				valorAcrescimo += ((2*valorFabrica/100) + (8*valorFabrica/100));
				cout << "\nOp��o trio el�trico adicionada";
				cTrioEletrico += 1;
				break;
			case 2:
				valorAcrescimo += (2*valorFabrica/100);
				cout << "\nOp��o ar condicionado adicionada";
				cArCondicionado += 1;
				break;
			case 3:
				valorAcrescimo += (2*valorFabrica/100);
				cout << "\nOp��o dire��o hidr�ulica adicionada";
				cDirecaoHidraulica += 1;
				break;
			case 4:
				valorAcrescimo += (valorFabrica - (3.5*valorFabrica/100) + ((6*valorFabrica/100) + (8*valorFabrica/100)));
				cout << "\nOp��o completa adicionada";
				cCompleto += 1;
				break;
			default:
				cout << "\nOp��o inv�lida! Digite outra op��o de zero a 4";
		}
		
		printf("\n\nDeseja adicionar outra op��o (S/N)? ");
		scanf(" %c", &escolha);
	} while (escolha == 's' || escolha == 'S');
	
	totalUsuario();
	escolhaUsuario();
	
	return 0;
}
