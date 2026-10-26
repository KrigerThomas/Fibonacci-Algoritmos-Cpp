#include "CalculadoraFibonacci.h"

#include <cmath>
#include <iostream>

long long CalculadoraFibonacci::recursivo(int n) const {
    if (n <= 1) {
        return n;
    }
    return recursivo(n - 1) + recursivo(n - 2);
}

long long CalculadoraFibonacci::iterativo(int n) const {
    long long anterior = 0;
    long long atual = 1;
    for (int i = 0; i < n; ++i) {
        long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}

long long CalculadoraFibonacci::binet(int n) const {
    if (n < 0 || n > 92) {
        return 0;
    }

    const double raizDeCinco = std::sqrt(5.0);
    const double phi = (1.0 + raizDeCinco) / 2.0;
    const double psi = (1.0 - raizDeCinco) / 2.0;
    long long aproximado = std::llround(
        (std::pow(phi, n) - std::pow(psi, n)) / raizDeCinco);

    // Retorna zero quando Binet nao bate com a iteracao.
    if (aproximado != iterativo(n)) {
        return 0;
    }
    return aproximado;
}

void CalculadoraFibonacci::compararMetodos(int n) const {
    std::cout << "Recursivo: " << recursivo(n) << '\n';
    std::cout << "Iterativo: " << iterativo(n) << '\n';
    long long resultadoBinet = binet(n);
    if (n > 0 && resultadoBinet == 0) {
        std::cout << "Binet: impreciso para este indice\n";
    } else {
        std::cout << "Binet: " << resultadoBinet << '\n';
    }
}
