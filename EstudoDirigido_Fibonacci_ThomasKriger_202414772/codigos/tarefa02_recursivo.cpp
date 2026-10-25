// g++ .\tarefa02_recursivo.cpp -o ../executaveis/tarefa02.exe
// ..\executaveis\tarefa02.exe

/*
Esse código serve para calcular o n-ésimo número de fibonacci de forma recursiva simples.

A complexidade de tempo é O(2^n) pois, por se tratar de um algoritmo recursivo que se divide em 2 chamadas a cada passo,
ele acaba acumulando chamadas que se repetem, fazendo com que o número de operações seja maior.
*/

#include <iostream>

long long contadorCasosBase = 0;

long long fibonacciRecursivo(int n);

int main() {
    int n;
    std::cout << "Digite um numero (<= 40): ";
    std::cin >> n;

    while (n < 0 || n > 40) {
        std::cout << "Numero invalido! Digite um numero entre 0 e 40: ";
        std::cin >> n;
    }

    contadorCasosBase = 0;
    long long resultado = fibonacciRecursivo(n);

    std::cout << "O " << n << " numero de fibonacci e: " << resultado << std::endl;
    std::cout << "Casos base atingidos: " << contadorCasosBase << std::endl;

    return 0;
}

long long fibonacciRecursivo(int n) {
    if (n <= 1) {
        contadorCasosBase++;
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}