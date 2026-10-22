
// g++ -std=c++17 src/main.cpp src/recursivo.cpp src/memoizado.cpp src/iterativo.cpp src/binet.cpp -o fibonacci.exe


#include "algoritmos.h"

#include <iostream>

int main() {
    int n;

    std::cout << "Digite um indice entre 0 e 93: ";
    if (!(std::cin >> n) || n < 0 || n > 93) {
        std::cout << "Indice invalido. Use um numero de 0 a 93.\n";
        return 1;
    }

    if (n <= 40) {
        std::cout << "F(" << n << ") pela recursao simples: " << fibonacciRecursivo(n) << '\n';
    } else {
        std::cout << "Recursao simples nao foi executada: ela fica muito lenta acima de 40.\n";
    }
    std::cout << "F(" << n << ") pela recursao com memoria: "
              << fibonacciMemoizado(n) << '\n';
    std::cout << "F(" << n << ") pelo metodo iterativo: "
              << fibonacciIterativo(n) << '\n';
    std::cout << "F(" << n << ") pela formula de Binet: "
              << fibonacciBinet(n) << '\n';

    for (int indice = 0; indice <= 93; ++indice) {
        if (fibonacciBinet(indice) != fibonacciIterativo(indice)) {
            std::cout << "Primeira diferenca de Binet neste computador: n = "
                      << indice << '\n';
            break;
        }
    }

    std::cout << "\nA recursao simples fica lenta para indices grandes.\n";
    std::cout << "A formula de Binet pode perder precisao por usar numeros reais.\n";
    return 0;
}
