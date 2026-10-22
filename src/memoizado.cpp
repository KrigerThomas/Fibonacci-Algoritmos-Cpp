#include "algoritmos.h"

#include <vector>

namespace {
NumeroFibonacci calcularComMemoria(int n, std::vector<NumeroFibonacci>& memoria) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (memoria[n] != 0) {
        return memoria[n];
    }

    memoria[n] = calcularComMemoria(n - 1, memoria)
               + calcularComMemoria(n - 2, memoria);
    return memoria[n];
}
}

NumeroFibonacci fibonacciMemoizado(int n) {
    std::vector<NumeroFibonacci> memoria(n + 1, 0);
    return calcularComMemoria(n, memoria);
}
