// Na pasta codigos, compile com:
// g++ -std=c++17 tarefa04_binet.cpp -o ../executaveis/tarefa04.exe

#include <cmath>
#include <chrono>
#include <iomanip>
#include <initializer_list>
#include <iostream>

long long fibonacciIterativo(int n);
long long fibonacciBinet(int n);

int main() {
    int primeiroErro = -1;

    for (int n = 0; n <= 92; ++n) {
        if (fibonacciBinet(n) != fibonacciIterativo(n)) {
            primeiroErro = n;
            break;
        }
    }

    std::cout << "Primeiro erro encontrado: n = " << primeiroErro << "\n\n";
    std::cout << "n       iterativo           Binet               diferenca\n";

    int inicio = primeiroErro - 2;
    if (inicio < 0) inicio = 0;
    int fim = primeiroErro + 4;
    if (fim > 92) fim = 92;

    for (int n = inicio; n <= fim; ++n) {
        long long exato = fibonacciIterativo(n);
        long long aproximado = fibonacciBinet(n);
        double diferenca = std::abs(static_cast<double>(exato) - aproximado);

        std::cout << std::setw(2) << n << "   " << std::setw(18) << exato
                  << "   " << std::setw(18) << aproximado
                  << "   " << diferenca << '\n';
    }

    std::cout << "\nTempo medio por chamada (10000 repeticoes):\n";
    std::cout << "n       iterativo (ns)       Binet (ns)\n";
    for (int n : {10, 20, 40, 60, 70}) {
        const int repeticoes = 10000;
        volatile long long soma = 0;

        auto inicioIterativo = std::chrono::steady_clock::now();
        for (int i = 0; i < repeticoes; ++i) soma = soma + fibonacciIterativo(n);
        auto fimIterativo = std::chrono::steady_clock::now();

        auto inicioBinet = std::chrono::steady_clock::now();
        for (int i = 0; i < repeticoes; ++i) soma = soma + fibonacciBinet(n);
        auto fimBinet = std::chrono::steady_clock::now();

        double tempoIterativo = std::chrono::duration<double, std::nano>(fimIterativo - inicioIterativo).count() / repeticoes;
        double tempoBinet = std::chrono::duration<double, std::nano>(fimBinet - inicioBinet).count() / repeticoes;
        std::cout << n << "       " << tempoIterativo << "              " << tempoBinet << '\n';
    }

    return 0;
}

long long fibonacciIterativo(int n) {
    long long anterior = 0;
    long long atual = 1;
    for (int i = 0; i < n; ++i) {
        long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}

long long fibonacciBinet(int n) {
    const double raizDeCinco = std::sqrt(5.0);
    const double phi = (1.0 + raizDeCinco) / 2.0;
    const double psi = (1.0 - raizDeCinco) / 2.0;
    double resultado = (std::pow(phi, n) - std::pow(psi, n)) / raizDeCinco;
    return std::llround(resultado);
}
