
#include "algoritmos.h"

#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    const double razaoAurea = (1.0 + std::sqrt(5.0)) / 2.0;
    int n;

    std::cout << std::fixed << std::setprecision(30);
    std::cout << "Razao aurea (double, exibida com 30 casas): " << razaoAurea << "\n\n";
    std::cout << "Observacao: double nao guarda 30 casas de precisao; as casas finais\n"
                 "sao apenas a exibicao de uma aproximacao com precisao limitada.\n\n";

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

    std::cout << "F(" << n << ") pela recursao com memoria: " << fibonacciMemoizado(n) << '\n';
    std::cout << "F(" << n << ") pelo metodo iterativo: " << fibonacciIterativo(n) << '\n';
    std::cout << "F(" << n << ") pela formula de Binet: " << fibonacciBinet(n) << '\n';

    for (int indice = 0; indice <= 93; ++indice) {
        if (fibonacciBinet(indice) != fibonacciIterativo(indice)) {
            std::cout << "Primeira diferenca de Binet neste computador: n = " << indice << '\n';
            break;
        }
    }

    std::cout << "\nA recursao simples fica lenta para indices grandes.\n";
    std::cout << "A formula de Binet pode perder precisao por usar numeros reais.\n";
    return 0;
}
