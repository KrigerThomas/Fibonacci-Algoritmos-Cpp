// g++ .\tarefa03_iterativo.cpp -o ..\executaveis\tarefa03.exe
// ..\executaveis\tarefa03.exe

/*
Esse código serve para calcular o n-ésimo número de fibonacci de forma iterativa.

A complexidade de tempo é O(n) pois o algoritmo faz um único loop que vai de 3 até n,
acumulando apenas uma soma a cada passo, sem repetir cálculos.

E a complexidade de espaço é O(1), pois o método guarda apenas algumas variáveis,
independentemente do valor de n. A versão recursiva cria novas chamadas, que ocupam
a pilha até retornarem.
*/

#include <iostream>
#include <chrono>

long long fibonacciIterativo(int n);
long long fibonacciRecursivo(int n);

int main() {
    int n;
    std::cout << "Digite um numero (<= 40): ";
    std::cin >> n;

    while (n < 0 || n > 40) {
        std::cout << "Numero invalido! Digite um numero entre 0 e 40: ";
        std::cin >> n;
    }

    auto inicioRecursivo = std::chrono::steady_clock::now();
    long long resultadoRecursivo = fibonacciRecursivo(n);
    auto fimRecursivo = std::chrono::steady_clock::now();

    auto inicioIterativo = std::chrono::steady_clock::now();
    long long resultadoIterativo = fibonacciIterativo(n);
    auto fimIterativo = std::chrono::steady_clock::now();

    double tempoRecursivo = std::chrono::duration<double, std::nano>(fimRecursivo - inicioRecursivo).count();
    double tempoIterativo = std::chrono::duration<double, std::nano>(fimIterativo - inicioIterativo).count();

    std::cout << "F(" << n << ") recursivo: " << resultadoRecursivo
              << " | tempo: " << tempoRecursivo << " ns\n";
    std::cout << "F(" << n << ") iterativo: " << resultadoIterativo
              << " | tempo: " << tempoIterativo << " ns\n";

    return 0;
}

long long fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
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
