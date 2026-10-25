// g++ .\tarefa03_iterativo.cpp -o ..\executaveis\tarefa03.exe
// ..\executaveis\tarefa03.exe

/*
Esse código serve para calcular o n-ésimo número de fibonacci de forma iterativa.

A complexidade de tempo é O(n) pois o algoritmo faz um único loop que vai de 3 até n,
acumulando apenas uma soma a cada passo, sem repetir cálculos.

E a complexidade de espaço é O(1) constante, pois a função que cálcula a sequencia 
só é chamada uma vez e não faz nenhuma chamada recursiva.
*/

#include <iostream>

long long fibonacciIterativo(int n);

int main() {
    int n;
    std::cout << "Digite um numero (<= 40): ";
    std::cin >> n;

    while (n < 0 || n > 40) {
        std::cout << "Numero invalido! Digite um numero entre 0 e 40: ";
        std::cin >> n;
    }

    long long resultado = fibonacciIterativo(n);

    std::cout << "O " << n << " numero de fibonacci e: " << resultado << std::endl;

    return 0;
}

long long fibonacciIterativo(int n) {
    if (n <= 1) {
        return n;
    }

    long long a = 1;
    long long b = 1;

    for (int i = 3; i <= n; i++) {
        long long proximo = a + b;
        a = b;
        b = proximo;
    }

    return b;
}
