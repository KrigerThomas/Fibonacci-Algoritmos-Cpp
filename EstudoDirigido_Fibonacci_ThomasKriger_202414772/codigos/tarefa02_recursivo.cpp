// g++ .\tarefa02_recursivo.cpp -o ../executaveis/tarefa02.exe
// ..\executaveis\tarefa02.exe

/*
Esse código serve para calcular o n-ésimo número de fibonacci de forma recursiva simples.

A complexidade de tempo é (2^n) pois por se tratar de um algoritmo recursivo,
ele acaba acumulando chamadas que se repetem, fazendo com que o número de operações
seja maior.
*/

#include <iostream>

long long fibonacciRecursivo(int n);

int main() {
    int n;
    std::cout << "Digite um numero: ";
    std::cin >> n;
    std::cout << "O " << n << "-esimo numero de fibonacci e: " << fibonacciRecursivo(n) << std::endl;
    return 0;
}

long long fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}