#include "algoritmos.h"

#include <cmath>

NumeroFibonacci fibonacciBinet(int n) {
    const double raizDeCinco = std::sqrt(5.0);
    const double razaoAurea = (1.0 + raizDeCinco) / 2.0;
    const double outraRaiz = (1.0 - raizDeCinco) / 2.0;
    const double resultado = (std::pow(razaoAurea, n) - std::pow(outraRaiz, n))
                           / raizDeCinco;

    return static_cast<NumeroFibonacci>(std::round(resultado));
}
