// g++ -std=c++17 tarefa04_binet.cpp -o ../executaveis/tarefa04.exe
// ..\executaveis\tarefa04.exe

#include <cmath>
#include <chrono>
#include <iostream>

long long fibonacciIterativo(int n);
long long fibonacciBinet(int n);

int main() {
    int primeiroErro = -1;

    for (int n = 0; n <= 92; n++) {
        if (fibonacciIterativo(n) != fibonacciBinet(n)) {
            primeiroErro = n;
            break;
        }
    }

    if (primeiroErro == -1) {
        std::cout << "Nenhum erro encontrado ate n = 92.\n";
    } else {
        std::cout << "Primeiro erro de Binet encontrado em n = " << primeiroErro << "\n\n";
        std::cout << "n | iterativo | Binet | diferenca absoluta\n";

        int inicio = primeiroErro - 2;
        int fim = primeiroErro + 3;
        if (inicio < 0) inicio = 0;
        if (fim > 92) fim = 92;

        for (int n = inicio; n <= fim; n++) {
            long long exato = fibonacciIterativo(n);
            long long aproximado = fibonacciBinet(n);
            long long diferenca = exato - aproximado;
            if (diferenca < 0) diferenca = -diferenca;

            std::cout << n << " | " << exato << " | " << aproximado
                      << " | " << diferenca << '\n';
        }
    }

    std::cout << "\nTempo medio por chamada (1000 repeticoes):\n";
    int valores[] = {10, 20, 40, 60, 70};
    for (int n : valores) {
        const int repeticoes = 1000;
        long long resultadoIterativo = 0;
        long long resultadoBinet = 0;

        auto inicioIterativo = std::chrono::steady_clock::now();
        for (int i = 0; i < repeticoes; i++) {
            resultadoIterativo = fibonacciIterativo(n);
        }
        auto fimIterativo = std::chrono::steady_clock::now();

        auto inicioBinet = std::chrono::steady_clock::now();
        for (int i = 0; i < repeticoes; i++) {
            resultadoBinet = fibonacciBinet(n);
        }
        auto fimBinet = std::chrono::steady_clock::now();

        double tempoIterativo = std::chrono::duration<double, std::nano>(
            fimIterativo - inicioIterativo).count() / repeticoes;
        double tempoBinet = std::chrono::duration<double, std::nano>(
            fimBinet - inicioBinet).count() / repeticoes;

        std::cout << "n = " << n
                  << " | iterativo: " << tempoIterativo << " ns"
                  << " | Binet: " << tempoBinet << " ns"
                  << " | resultados iguais: "
                  << (resultadoIterativo == resultadoBinet ? "sim" : "nao") << '\n';
    }

    return 0;
}

long long fibonacciIterativo(int n) {
    if (n <= 1) return n;

    long long anterior = 0;
    long long atual = 1;
    for (int i = 2; i <= n; i++) {
        long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

long long fibonacciBinet(int n) {
    double raizDeCinco = std::sqrt(5.0);
    double phi = (1.0 + raizDeCinco) / 2.0;
    double psi = (1.0 - raizDeCinco) / 2.0;
    double resultado = (std::pow(phi, n) - std::pow(psi, n)) / raizDeCinco;
    return std::llround(resultado);
}

