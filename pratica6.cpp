/*Programa:
Recebe dados sobre o endereço (CEP), a renda média mensal, o número total de ocupantes e o número de ocupantes em idade escolar de vários domicílios.
Ordena esses dados, de acordo com o endereço, por inserção direta e salva os dados ordenados em um arquivo.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct dados{
    int endereco; //por CEP
    double renda;
    int ocupantes_total;
    int ocupantes_estudantes;
};

void ler_dados(dados domicilio[], int n);
void insercao_direta(dados domicilio[], int n);

int main(){
    //abrir/criar arquivo em modo escrita
    FILE *arq;
	arq = fopen("dados.txt", "wt");
	if(arq == NULL){
		printf("Falha ao abrir o arquivo \n");
		exit(1);
	}

    int n;
    cout << "\nQuantos domicilios serao pesquisados? ";
    cin >> n;

    dados domicilio[n+1];
    ler_dados(domicilio, n);
    insercao_direta(domicilio, n);

    //escrever no arquivo
    for(int i = 1; i <= n; i++){
        fprintf(arq, "%d\n", domicilio[i].endereco);
        fprintf(arq, "%.2f\n", domicilio[i].renda);
        fprintf(arq, "%d\n", domicilio[i].ocupantes_total);
        fprintf(arq, "%d\n", domicilio[i].ocupantes_estudantes);
    }

    //fechar arquivo
    fclose(arq);

    return 0;
}

void ler_dados(dados domicilio[], int n){ //leitura dos dados
    for(int i = 1; i <= n; i++){
        cout << "\nDomicilio " << i << endl;
        cout << "Endereco (CEP): ";
        cin >> domicilio[i].endereco;
        
        cout << "Renda media mensal: R$";
        cin >> domicilio[i].renda;

        cout << "Numero total de ocupantes: ";
        cin >> domicilio[i].ocupantes_total;

        cout << "Numero de ocupantes em idade escolar: ";
        cin >> domicilio[i].ocupantes_estudantes;       
    }
    cout << "\nDados coletados com sucesso." << endl;
}

void insercao_direta(dados domicilio[], int n){ //ordenacao
    int aux[4], j;
    for(int i = 2; i <= n; i++){
        aux[0] = domicilio[i].endereco;
        aux[1] = domicilio[i].renda;
        aux[2] = domicilio[i].ocupantes_total;
        aux[3] = domicilio[i].ocupantes_estudantes;
        domicilio[0].endereco = aux[0];
        j = i;
        while(aux[0] < domicilio[j-1].endereco){
            domicilio[j].endereco = domicilio[j-1].endereco;
            domicilio[j].renda = domicilio[j-1].renda;
            domicilio[j].ocupantes_total = domicilio[j-1].ocupantes_total;
            domicilio[j].ocupantes_estudantes = domicilio[j-1].ocupantes_estudantes;
            j = j-1;
        }
        domicilio[j].endereco = aux[0];
        domicilio[j].renda = aux[1];
        domicilio[j].ocupantes_total = aux[2];
        domicilio[j].ocupantes_estudantes = aux[3];
    }
}

