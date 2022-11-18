/*Programa:
Cria um vetor v de n inteiros aleatórios.
Retorna o índice da primeira ocorrência de x (chave de busca) no vetor.
Se não x for encontrado, retorna -1.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int busca(int n, int v[], int x);

int main(){
    int n;
    cout << "\nQuantos elementos tem o vetor? ";
    cin >> n;
    
    int v[n];
    for(int i = 0; i < n; i++){
        v[i] = rand() % 100;
        cout << "v[" << i << "] = " << v[i] <<endl;
    }

    int x;
    cout << "\nInforme o valor que voce deseja buscar no vetor: ";
    cin >> x;

    int y = busca(n, v, x);
    if(y == -1){
        cout << "-1\n" << endl;
    }
    else{
        cout << "\nO valor " << x << " esta no indice " << y << " do vetor\n" << endl;
    }
    
}

int busca(int n, int v[], int x){
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}