#pragma once

#include <cstdint>

using NumeroFibonacci = std::uint64_t; // 18.446.744.073.709.551.615

NumeroFibonacci fibonacciRecursivo(int n);
NumeroFibonacci fibonacciMemoizado(int n);
NumeroFibonacci fibonacciIterativo(int n);
NumeroFibonacci fibonacciBinet(int n);


