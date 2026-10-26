#include "CalculadoraFibonacci.h"

#include <iostream>

int main() {
    CalculadoraFibonacci calculadora;
    int n;
    int metodo;

    std::cout << "Escolha: 1 recursivo, 2 iterativo, 3 Binet, 4 comparar: ";
    if (!(std::cin >> metodo) || metodo < 1 || metodo > 4) {
        std::cout << "Opcao invalida.\n";
        return 1;
    }

    int limite = (metodo == 1 || metodo == 4) ? 40 : 92;
    std::cout << "Digite n entre 0 e " << limite << ": ";
    if (!(std::cin >> n) || n < 0 || n > limite) {
        std::cout << "Indice invalido.\n";
        return 1;
    }

    if (metodo == 1) {
        std::cout << "F(" << n << ") = " << calculadora.recursivo(n) << '\n';
    } else if (metodo == 2) {
        std::cout << "F(" << n << ") = " << calculadora.iterativo(n) << '\n';
    } else if (metodo == 3) {
        long long resultado = calculadora.binet(n);
        if (n > 0 && resultado == 0) {
            std::cout << "Binet ficou impreciso para esse indice.\n";
        } else {
            std::cout << "F(" << n << ") = " << resultado << '\n';
        }
    } else {
        calculadora.compararMetodos(n);
    }

    return 0;
}
