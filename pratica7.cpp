/*Programa:
Recebe registros - nome(string) e número de inscrição(int) - de n pessoas.
Ordena, por meio do método QuickSort e de acordo com o número de inscrição, um vetor com os n registros.
Imprime o número de comparações entre chaves, movimentações de registros e chamadas da função recursiva realizadas pelo algoritmo do QuickSort.
*/

#include <iostream>
#include <math.h>
using namespace std;


struct registro{
    string nome; 
    int inscricao;
};

void quicksort(registro v[], int L, int R);
void setRegistros(registro v[], int n);
void getRegistros(registro v[], int n);
void contadores();

int count_comp = 0, count_moves = 0, count_rec = 1;

int main(){
    int n;
    cout << "\nQuantos registros serao feitos? ";
    cin >> n;
    
    registro cadastros[n+1];
    setRegistros(cadastros, n);
    quicksort(cadastros, 1, n);
    getRegistros(cadastros, n);
    contadores();

    return 0;
}

void setRegistros(registro v[], int n){
    cout << "\n----------REGISTRAR----------";
    for(int i = 1; i <= n; i++){
        cout << "\nRegistro " << i << endl;
        cout << "Nome: ";
        cin >> v[i].nome;
        cout << "Numero da Inscricao: ";
        cin >> v[i].inscricao;
    }
}
void getRegistros(registro v[], int n){
    cout << "\n----------REGISTROS----------";
    for(int i = 1; i <= n; i++){
        cout << "\nRegistro " << i << endl;
        cout << "Nome: " << v[i].nome;
        cout << "\nNumero da Inscricao: " << v[i].inscricao << endl;
    }
}
void contadores(){
    cout << "\n----------CONTADORES----------";
    cout << "\nNumero de comparacoes: " << count_comp << endl;
    cout << "Numero de movimentacoes: " << count_moves << endl;
    cout << "Numero de chamadas da funcao 'quicksort': " << count_rec << "\n" << endl;
}

void quicksort(registro v[], int L, int R){
    int i, j, m, aux;
    registro w;

    i = L;
    j = R;
    m = floor((L+R)/2);
    aux = v[m].inscricao; 
    count_moves++;
    
    do{
        count_comp++;
        while(v[i].inscricao < aux){
            i++;
            count_comp++;
        }
        count_comp++;
        while(aux < v[j].inscricao){
            j--;
            count_comp++;
        }
        if(i <= j){
            w = v[i];
            v[i] = v[j];
            v[j] = w;
            i++;
            j--;
            count_moves += 3;
        }
    }while(i <= j);

    if(L < j){
        quicksort(v, L, j);
        count_rec++;
    }
    if(i < R){
        quicksort(v, i, R);
        count_rec++;
    }
}

