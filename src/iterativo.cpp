#include "algoritmos.h"

NumeroFibonacci fibonacciIterativo(int n) {
    NumeroFibonacci anterior = 0;
    NumeroFibonacci atual = 1;

    for (int i = 0; i < n; ++i) {
        NumeroFibonacci proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}
