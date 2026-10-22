#include "algoritmos.h"

NumeroFibonacci fibonacciRecursivo(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}
