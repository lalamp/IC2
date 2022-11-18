/* Programa:
Recebe dados dos alunos de uma turma.
Calcula a média final de cada aluno.
Calcula a média e o desvio padrão das médias finais da turma.
*/

#include <iostream>
#include <math.h>
using namespace std;

struct estudante{
    int numUSP;
    float nota1;
    float nota2;
    float media_final;
};

int main(){
    int i, cadastros = 0, y = 0; 
    estudante v[100];

    do{
        for(int j = 1; j <= 65; j++){
            cout << "-";
        }
        cout << "\nMENU: [1] entrar com os dados de um estudante \n      [2] mostrar os dados de um estudante\n      [3] mostrar a media e o desvio padrao das medias finais\n      [4] sair";
        cout << "\nO que deseja realizar? ";
        cin >> y;
    
        while(y != 1 and y != 2 and y != 3 and y != 4){
            cout << "\nOpcao invalida. Tente novamente.\n" << endl;

            for(int j = 1; j <= 65; j++){
                cout << "-";
            }
            cout << "\nMENU: [1] entrar com os dados de um estudante \n      [2] mostrar os dados de um estudante\n      [3] mostrar a media e o desvio padrao das medias finais\n      [4] sair";
            cout << "\nO que deseja realizar? ";
            cin >> y;
        }

        for(int j = 1; j <= 65; j++){
            cout << "-";
        }
 
        if(y == 1){
            cout << "\n\n            CADASTRO            ";
            cout << "\nEntre com os dados do estudante: "<< endl;
            cout << "Numero USP: ";
            cin >> v[cadastros].numUSP;
            cout << "Nota da primeira prova: ";
            cin >> v[cadastros].nota1;                
            cout << "Nota da segunda prova: ";
            cin >> v[cadastros].nota2;
            cout << endl;
            v[cadastros].media_final = (v[cadastros].nota1 + v[cadastros].nota2)/2;
            cadastros++;
        }

        if(y == 2){
            cout << "\n\n                            DADOS                             ";
            int x;
            cout << "\nDigite o numero USP do estudante para acessar os seus dados: ";
            cin >> x;

            int aux = 0;
            for(i = 0; i < cadastros; i++){
                if(x == v[i].numUSP){
                aux = 1;
                cout << "\nEstudante " << v[i].numUSP << endl;
                cout << "Nota da primeira prova: " << v[i].nota1 << endl;
                cout << "Nota da segunda prova: " << v[i].nota2 << endl;
                cout << "Media final: " << v[i].media_final << endl;
                cout << endl;
                }
            }

            if(aux == 0){
                cout << "\nNumero USP nao encontrado. " << endl;
                cout << endl;
            }
        }

        if(y == 3){
            cout << "\n\n         MEDIA E DESVIO PADRAO         ";
            float soma = 0, soma2 = 0, media_total, desvio;
            for(i = 0; i < cadastros; i++){
                soma += v[i].media_final;
            }
            media_total = soma/cadastros;
            for(i = 0; i < cadastros; i++){
                soma2 += pow((v[i].media_final - media_total), 2);
            }
            desvio = sqrt(soma2/cadastros);
            cout << "\nTotal de alunos cadastrados: " << cadastros;
            cout << "\nMedia das medias finais = " << media_total << "\nDesvio padrao das medias finais = " << desvio << endl;
            cout << endl;
        }
    }
    while(y != 4);
       
    return 0; 
}