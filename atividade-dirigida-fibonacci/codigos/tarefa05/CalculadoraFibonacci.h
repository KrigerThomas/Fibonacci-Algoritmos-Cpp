#pragma once

class CalculadoraFibonacci {
public:
    CalculadoraFibonacci() = default;

    long long recursivo(int n) const;
    long long iterativo(int n) const;
    long long binet(int n) const;
    void compararMetodos(int n) const;
};
