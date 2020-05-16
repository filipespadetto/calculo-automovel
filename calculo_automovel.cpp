#include <iostream>
#include <locale>
using namespace std;

// DECLARAÇÃO DE VARIÁVEIS
float valorFabrica, valorAcrescimo, valorTotal;
int opcoes, cValorFabrica, cTrioEletrico, cArCondicionado, cDirecaoHidraulica, cCompleto;
char escolha;

// FUNÇÃO QUE MOSTRA RESULTADO DO VALOR TOTAL
void totalUsuario(){
	setlocale(LC_ALL, "C");
	cout << "\n\n#################### VALOR TOTAL ####################";
	printf("\nValor total: R$%.3f", valorFabrica + valorAcrescimo);
}

void escolhaUsuario(){
	setlocale(LC_ALL, "");
	cout << "\n\n#################### OPÇÕES ESCOLHIDAS ####################";
	cout << "\nValor de fábrica: " << cValorFabrica;
	cout << "\nTrio elétrico: " << cTrioEletrico;
	cout << "\nAr condicionado: " << cArCondicionado;
	cout << "\nDireção hidráulica: " << cDirecaoHidraulica;
	cout << "\nCompleto: " << cCompleto;
}

int main(){
	setlocale(LC_ALL, "");
	
	cout << "Insira o valor de fábrica: ";
	cin >> valorFabrica;
	
	do{
		cout << "\n\n#################### MENU DE OPÇÕES ####################";
		cout << "\nPressione a(s) opção(ões) que o cliente deseja";
		cout << "\nOpção 0: somente o valor de fábrica (sem opcionais)"; // 2% do valor de fábrica com IPI
		cout << "\nOpção 1: trio elétrico (alarme, vidro elétrico e tranca elétrica)"; // 2% do valor de fábrica do modelo (sem o IPI)
		cout << "\nOpção 2: ar condicionado"; // 2% do valor de fábrica do modelo (sem o IPI)
		cout << "\nOpção 3: direção hidráulica"; // 2% do valor de fábrica do modelo (sem o IPI)
		cout << "\nOpção 4: completo (trio elétrico, ar condicionado e direção hidráulica)"; // a soma dos acréscimos isolados
		//O IPI dos automóveis é de 8% do valor de fábrica
		
		cout << "\n\nDigite a opção desejada: ";
		cin >> opcoes;
		
		switch(opcoes){
			case 0:
				cout << "\nValor de fábrica sem acréscimos";
				cValorFabrica += 1;
				break;
			case 1:
				valorAcrescimo += ((2*valorFabrica/100) + (8*valorFabrica/100));
				cout << "\nOpção trio elétrico adicionada";
				cTrioEletrico += 1;
				break;
			case 2:
				valorAcrescimo += (2*valorFabrica/100);
				cout << "\nOpção ar condicionado adicionada";
				cArCondicionado += 1;
				break;
			case 3:
				valorAcrescimo += (2*valorFabrica/100);
				cout << "\nOpção direção hidráulica adicionada";
				cDirecaoHidraulica += 1;
				break;
			case 4:
				valorAcrescimo += (valorFabrica - (3.5*valorFabrica/100) + ((6*valorFabrica/100) + (8*valorFabrica/100)));
				cout << "\nOpção completa adicionada";
				cCompleto += 1;
				break;
			default:
				cout << "\nOpção inválida! Digite outra opção de zero a 4";
		}
		
		printf("\n\nDeseja adicionar outra opção (S/N)? ");
		scanf(" %c", &escolha);
	} while (escolha == 's' || escolha == 'S');
	
	totalUsuario();
	escolhaUsuario();
	
	return 0;
}
