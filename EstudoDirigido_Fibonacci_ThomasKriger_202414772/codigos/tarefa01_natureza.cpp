//g++ .\tarefa01_natureza.cpp -o ../executaveis/tarefa01.exe
// ..\executaveis\tarefa01.exe

#include <iostream>
#include <cmath>

/*
Esse código serve para provar que a razão (divsão) de um elemento pelo seu antecessor
na sequência de fibonacci se aproxima do valor que é chamado de razão áurea (phi).
*/

void verificarRazaoAurea(int limite);

int main() {
    verificarRazaoAurea(15);
    return 0;
}

void verificarRazaoAurea(int limite) {
    // std::sqrt calcula a raiz quadrada de 5.
    double phi = (1.0 + std::sqrt(5.0)) / 2.0;

    long long a = 1;
    long long b = 1;

    std::cout << "Razao Aurea teorica (phi): " << phi << "\n\n";

    for (int i = 1; i <= limite; i++) {
        double razao = (double)b / a;
        // std::abs retorna a diferenca sem sinal negativo.
        double diferenca = std::abs(razao - phi);

        std::cout << i << ") " << b << " / " << a << " = " << razao  << " (diferenca para phi: " << diferenca << ")\n";

        long long proximo = a + b;
        a = b;
        b = proximo;
    }
}
