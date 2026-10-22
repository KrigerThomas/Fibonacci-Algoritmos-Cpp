#include "algoritmos.h"

#include <cmath>

NumeroFibonacci fibonacciBinet(int n) {
    // Formula: F(n) = (phi^n - psi^n) / sqrt(5)
    // phi = (1 + sqrt(5)) / 2; psi = (1 - sqrt(5)) / 2
    const double raizDeCinco = std::sqrt(5.0);
    const double razaoAurea = (1.0 + raizDeCinco) / 2.0;
    const double outraRaiz = (1.0 - raizDeCinco) / 2.0;
    const double resultado = (std::pow(razaoAurea, n) - std::pow(outraRaiz, n))
                           / raizDeCinco;

    // Binet gives an approximation, so round before converting to an integer.
    const double resultadoArredondado = std::round(resultado);
    return static_cast<NumeroFibonacci>(resultadoArredondado);
}
