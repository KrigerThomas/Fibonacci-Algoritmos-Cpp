#pragma once

#include <cstdint>

using NumeroFibonacci = std::uint64_t;

NumeroFibonacci fibonacciRecursivo(int n);
NumeroFibonacci fibonacciMemoizado(int n);
NumeroFibonacci fibonacciIterativo(int n);
NumeroFibonacci fibonacciBinet(int n);


