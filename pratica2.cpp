
/*Programa:
Calcula o tempo de execução de cada algoritmo (funções prefixMedia1, prefixMedia2)
*/

#include <iostream>
#include <ctime>
using namespace std;

void prefixMedia1(int n, float *X, float *A);
void prefixMedia2(int n, float *X, float *A);

int main(){
    int n;
    cout << "\nInforme o tamanho do vetor: ";
    cin >> n;

    float *X = new float[n];
    float *A = new float[n];

    int i;
    for(i = 0; i < n; i++){
        X[i] = 1;
    }

    clock_t t1, t2;
    double tempo_total1;
    t1 = clock();
    prefixMedia1(n, X, A);
    t2 = clock();
    tempo_total1 = 1000.0*(t2 - t1)/CLOCKS_PER_SEC;
    cout << "\nTempo do Algoritmo 1 = " << tempo_total1 << " milisegundos" << endl;

    clock_t t3, t4;
    double tempo_total2;
    t3 = clock();
    prefixMedia2(n, X, A);
    t4 = clock();
    tempo_total2 = 1000.0*(t4 - t3)/CLOCKS_PER_SEC;
    cout << "Tempo do Algoritmo 2 = " << tempo_total2 << " milisegundos\n" << endl;

    return 0;
}

void prefixMedia1(int n, float *X, float *A){
    for(int i = 0; i < n; i++){
        float a = 0;
        for(int j = 0; j <= i; j++){
            a += X[j];
        }
        A[i] = a/(i+1);
    }
}

void prefixMedia2(int n, float *X, float *A){
    float s = 0;
    for(int i = 0; i < n; i++){
        s += X[i];
        A[i] = s/(i+1);
    }
}