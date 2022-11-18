/*Programa:
Para matrizes quadradas (com n linhas e n colunas).
Imprime a transposta da matriz A.
Calcula o produto entre as matrizes A e B.
Calcula o traço da matriz B.
*/

#include <iostream>
using namespace std;

const int n = 2; //numero de linhas/colunas das matrizes

void setMatriz(float M[][n], int n);
void printMatriz(float M[][n], int n);
void transposta(float A[][n], int n);
void produto(float A[][n], float B[][n], int n);
void traco(float B[][n], int n);


int main(){
    int i, j;   

    //MATRIZ A
    cout << "\nMatriz A" << endl;
    float A[n][n];
    cout << "Elementos da matriz A" << endl;
    setMatriz(A, n);
    cout << endl;
    printMatriz(A, n);

    //MATRIZ B
    cout << "\nMatriz B" << endl;
    float B[n][n];
    cout << "Elementos da matriz B" << endl;
    setMatriz(B, n);
    cout << endl;
    printMatriz(B, n);

    transposta(A, n);
    produto(A, B, n);
    traco(B, n);

    return 0;
}


void setMatriz(float M[][n], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << "M[" << i << "][" << j << "] = ";
            cin >> M[i][j];
        }
    }
}
void printMatriz(float M[][n], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }
}


void transposta(float A[][n], int n){
    int i, j;
    float At[n][n];
    cout << "\nTransposta de A: "<< endl;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            At[i][j] = A[j][i];
            cout << At[i][j] << "  ";
        }
        cout << endl;
    }
}

void produto(float A[][n], float B[][n], int n){
    int i, j, k;
    float P[n][n];
    cout << "\nProduto de AxB: "<< endl;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            P[i][j] = 0;
            for(k = 0; k < n; k++){
                P[i][j] += A[i][k] * B[k][j];
            }
            cout << P[i][j] << "  ";
        }
        cout << endl;
    }
}

void traco(float B[][n], int n){
    int i, traco = 0;
    for(i = 0; i < n; i++){
        traco += B[i][i];
    }
    cout << "\nTraco de B = " << traco << "\n" << endl;
}

