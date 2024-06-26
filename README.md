# Introdução à Computação II 
Linguagem: C++

+ [prática 1](https://github.com/lalamp/IC2/blob/main/pratica1.cpp)

Crie um programa que possua uma struct chamada estudante com os seguintes elementos: numero USP, nota da primeira prova, nota da segunda prova e média final.

Crie um menu que permita realizar as seguintes operações:

1) entrar com dados de um estudante (número USP e notas das provas),
2) mostrar dados de um estudante,
3) mostrar a média e desvio padrão para as médias finais de todos os estudantes cadastrados,
4) sair. 
  
Observações: procurar dados do estudante usando o número USP, calcular a média final como a média aritmética entre as duas provas e considerar um número máximo de 100 estudantes.

+ [prática 2](https://github.com/lalamp/IC2/blob/main/pratica2.cpp)
  
Implemente os algoritmos prefixMedia1() e prefixMedia2() apresentados a seguir utilizando funções (uma para cada algoritmo).

Obtenha os tempos de execução para vários valores distintos (pelo menos 5) de n para cada uma das duas funções.

Observações: utilize um vetor gerado automaticamente e alocação dinâmica.

+ [prática 3](https://github.com/lalamp/IC2/blob/main/pratica3.cpp)
  
Crie uma função que, dado um vetor v com n inteiros e um inteiro x (chave de busca), retorne o índice da primeira ocorrência de x em v.  Caso não encontre x no vetor v, a função deve retornar o valor -1. 

+ [prática 4](https://github.com/lalamp/IC2/blob/main/pratica4.cpp)
  
Crie um programa que tenha três funções para a manipulação de matrizes de ponto flutuante - todas as matrizes são quadradas, isto é, tem n linhas e n colunas: 

1) uma que imprima a transposta da matriz A,
2) outra que calcule o resultado da multiplicação de duas matrizes A e B,
3) uma que calcule o traço de uma matriz B. 

+ [prática 6-1](https://github.com/lalamp/IC2/blob/main/pratica6.cpp)
+ [prática 6-2](https://github.com/lalamp/IC2/blob/main/pratica6-2.cpp)
  
A prefeitura de uma cidade faz uma pesquisa sobre os domicílios na área urbana. Em cada domicilio, são coletados dados sobre renda média mensal, número total de ocupantes, endereço e número de ocupantes em idade escolar. 

Faça:
1) um programa que leia estes dados, faça a ordenação por inserção direta e salve os dados ordenados em um arquivo. Os dados devem ser ordenados de acordo com o endereço
2) um programa que leia o arquivo e tenha um menu que permita:
    + listar todos os domicílios, com as respectivas informações,
    + buscar os dados do domicílio quando um determinado endereço é digitado. Para a busca, deve-se utilizar busca binária,
    + sair.
 
+ [prática 7](https://github.com/lalamp/IC2/blob/main/pratica7.cpp)
  
Crie um registro (struct) com os campos: nome (string) e número de inscrição (int). 

Faça uma função para ordenar, via QuickSort, um vetor com n registros. A ordenação deve ser de acordo com o número de inscrição.

Imprima na tela o número de comparações entre chaves, movimentações de registros e chamadas da função recursiva realizadas pelo algoritmo. Utilize contadores para isso.
