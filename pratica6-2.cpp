/*Programa:
Lê o arquivo que contém os dados dos domicílios. 
Permite: listar todos os domicílios, com as respectivas informações
         buscar, por busca binária, os dados do domicílio quando um determinado endereço é digitado.
         sair do programa.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

# define MAX 1 //numero de domicilios no arquivo

struct dados{
    int endereco; //por CEP
    double renda;
    int ocupantes_total;
    int ocupantes_estudantes;
};

int menu();
int busca_binaria(dados domicilio[]);

int main(){
    dados domicilio[MAX];

    //abrir arquivo em modo leitura
    FILE *arq;
	arq = fopen("dados.txt", "rt");
	if(arq == NULL){
		printf("Falha na leitura do arquivo \n");
		exit(1);
	}

    //leitura do arquivo
    int i = 0;
    while(feof(arq)==0){
		fscanf(arq, "%d", &domicilio[i].endereco); 
        fscanf(arq, "%lf", &domicilio[i].renda); 
        fscanf(arq, "%d", &domicilio[i].ocupantes_total);
        fscanf(arq, "%d", &domicilio[i].ocupantes_estudantes);       
		i++;
	}

    int k, option;
    do{
        option = menu();
        switch(option){
            case 1:
                cout << "\n=====================DOMICILIOS=======================\n";
                for(k = 0; k < MAX; k++){
                    cout << "\nDomicilio " << k+1;
                    cout << "\nEndereco (CEP): " << domicilio[k].endereco;
                    cout << "\nRenda media mensal: R$" << setprecision(2) << fixed << domicilio[k].renda;
                    cout << "\nNumero total de ocupantes: " << domicilio[k].ocupantes_total;
                    cout << "\nNumero de ocupantes em idade escolar: " << domicilio[k].ocupantes_estudantes << endl; 
                }
                break;

            case 2:
                cout << "\n==================BUSCA DE DOMICILIO==================\n";
                //busca binaria
                k = busca_binaria(domicilio);
                if(k == -1){
                    cout << "O domicilio nao foi encontrado." << endl;
                }
                else{
                    cout << "\nDomicilio " << k+1;
                    cout << "\nEndereco (CEP): " << domicilio[k].endereco;
                    cout << "\nRenda media mensal: R$" << setprecision(2) << fixed << domicilio[k].renda;
                    cout << "\nNumero total de ocupantes: " << domicilio[k].ocupantes_total;
                    cout << "\nNumero de ocupantes em idade escolar: " << domicilio[k].ocupantes_estudantes << endl;
                }
                break;

            case 3:
                break;

            default:
                cout << "Opcao invalida!!" << endl;
                break;
        }
    }while(option != 3);
    
    return 0;
}


int menu(){
    int option;
    cout << "\n============================MENU============================= \n[1] Listar domicilios \n[2] Buscar dados de um domicilio \n[3] Sair \nO que voce deseja realizar? ";
    cin >> option;
    return option;
}

int busca_binaria(dados domicilio[]){
    int x;
    cout << "Digite o endereco (CEP) do seu domicilio: ";
    cin >> x; 

    int inicio = 0, fim = MAX-1, sucesso = 0, meio;
    while((inicio <= fim) && (sucesso == 0)){
        meio = floor((inicio+fim)/2);
        if(domicilio[meio].endereco == x) 
            sucesso = 1;
        else{
            if(domicilio[meio].endereco > x)
                fim = meio-1;
            else
                inicio = meio+1;
        }
    }

    if(sucesso == 1)
        return meio;
    else
        return -1;
}