#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <utility>
#include <vector>

namespace {

using FibonacciValue = std::uint64_t;
constexpr int kLargestExactIndex = 93;
constexpr int kLargestNaiveIndex = 40;

FibonacciValue recursive(int n) {
    if (n < 2) {
        return static_cast<FibonacciValue>(n);
    }
    return recursive(n - 1) + recursive(n - 2);
}

FibonacciValue memoized(int n, std::vector<FibonacciValue>& cache,
                        std::vector<bool>& calculated) {
    if (n < 2) {
        return static_cast<FibonacciValue>(n);
    }
    if (calculated[static_cast<std::size_t>(n)]) {
        return cache[static_cast<std::size_t>(n)];
    }

    cache[static_cast<std::size_t>(n)] =
        memoized(n - 1, cache, calculated) + memoized(n - 2, cache, calculated);
    calculated[static_cast<std::size_t>(n)] = true;
    return cache[static_cast<std::size_t>(n)];
}

FibonacciValue memoized(int n) {
    std::vector<FibonacciValue> cache(static_cast<std::size_t>(n + 1), 0);
    std::vector<bool> calculated(static_cast<std::size_t>(n + 1), false);
    return memoized(n, cache, calculated);
}

FibonacciValue iterative(int n) {
    if (n < 2) {
        return static_cast<FibonacciValue>(n);
    }

    FibonacciValue previous = 0;
    FibonacciValue current = 1;
    for (int i = 2; i <= n; ++i) {
        const FibonacciValue next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

std::pair<FibonacciValue, FibonacciValue> fastDoublingPair(int n) {
    if (n == 0) {
        return {0, 1};
    }

    const auto [a, b] = fastDoublingPair(n / 2);
    const FibonacciValue even = a * (2 * b - a);
    const FibonacciValue odd = a * a + b * b;
    if (n % 2 == 0) {
        return {even, odd};
    }
    return {odd, even + odd};
}

FibonacciValue fastDoubling(int n) {
    // F(93) fits in uint64_t, but the pair routine also forms F(94).
    if (n == 93) {
        return fastDoublingPair(92).second;
    }
    return fastDoublingPair(n).first;
}

double binetApproximation(int n) {
    const double squareRootOfFive = std::sqrt(5.0);
    const double phi = (1.0 + squareRootOfFive) / 2.0;
    const double psi = (1.0 - squareRootOfFive) / 2.0;
    return (std::pow(phi, n) - std::pow(psi, n)) / squareRootOfFive;
}

FibonacciValue roundedBinet(int n) {
    const double approximation = binetApproximation(n);
    if (!std::isfinite(approximation) || approximation < 0.0 ||
        approximation >= std::ldexp(1.0, 64)) {
        throw std::overflow_error("A aproximação saiu do intervalo de uint64_t.");
    }
    return static_cast<FibonacciValue>(std::round(approximation));
}

void printExactLimitNotice() {
    std::cout << "Os metodos inteiros usam uint64_t e ficam limitados a n <= "
              << kLargestExactIndex
              << ". F(93) ainda cabe nesse tipo, mas F(94) nao.\n";
}

int readIndex(int maximum) {
    int n = -1;
    std::cout << "Digite n (0 a " << maximum << "): ";
    if (!(std::cin >> n) || n < 0 || n > maximum) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Entrada invalida ou fora do limite.");
    }
    return n;
}

void printBinetResult() {
    const int n = readIndex(kLargestExactIndex);
    const double approximation = binetApproximation(n);
    std::cout.precision(17);
    std::cout << "Aproximacao em ponto flutuante: " << approximation << '\n';
    std::cout << "Depois de std::round:            " << roundedBinet(n) << '\n';
    std::cout << "Valor inteiro de referencia:    " << iterative(n) << '\n';
}

void printBinetExperiment() {
    int firstIncorrectIndex = -1;
    for (int n = 0; n <= kLargestExactIndex; ++n) {
        if (roundedBinet(n) != iterative(n)) {
            firstIncorrectIndex = n;
            break;
        }
    }

    std::cout << "Tipo double: " << (std::numeric_limits<double>::is_iec559
                                            ? "compativel com IEC 559 / IEEE 754"
                                            : "nao declarado como IEC 559")
              << "\nDigitos binarios de precisao de double: "
              << std::numeric_limits<double>::digits << '\n';

    if (firstIncorrectIndex == -1) {
        std::cout << "Nenhuma divergencia foi encontrada entre n=0 e n="
                  << kLargestExactIndex << ".\n";
        return;
    }

    const int previousIndex = firstIncorrectIndex - 1;
    std::cout << "Primeiro n incorreto neste ambiente: n = " << firstIncorrectIndex << '\n';
    std::cout << "n=" << previousIndex << " | Binet arredondado: "
              << roundedBinet(previousIndex) << " | exato: " << iterative(previousIndex)
              << '\n';
    std::cout << "n=" << firstIncorrectIndex << " | Binet arredondado: "
              << roundedBinet(firstIncorrectIndex) << " | exato: "
              << iterative(firstIncorrectIndex) << '\n';
    std::cout << "Esse limite depende da implementacao de pow, do tipo real usado e das "
                 "opcoes de compilacao.\n";
}

void printMenu() {
    std::cout << "\n=== Fibonacci: algoritmos e formula de Binet ===\n"
              << "1. Recursao simples (didatica; lenta)\n"
              << "2. Recursao com memoizacao\n"
              << "3. Iterativo\n"
              << "4. Dobra rapida\n"
              << "5. Formula de Binet\n"
              << "6. Experimento: primeiro erro de Binet\n"
              << "0. Sair\n"
              << "Escolha: ";
}

}  // namespace

int main() {
    printExactLimitNotice();

    while (true) {
        printMenu();
        int option = -1;
        if (!(std::cin >> option)) {
            std::cout << "Entrada invalida. Encerrando.\n";
            return 1;
        }

        try {
            switch (option) {
                case 1: {
                    const int n = readIndex(kLargestNaiveIndex);
                    std::cout << "F(" << n << ") por recursao simples: " << recursive(n)
                              << '\n';
                    break;
                }
                case 2: {
                    const int n = readIndex(kLargestExactIndex);
                    std::cout << "F(" << n << ") por recursao com memoizacao: "
                              << memoized(n) << '\n';
                    break;
                }
                case 3: {
                    const int n = readIndex(kLargestExactIndex);
                    std::cout << "F(" << n << ") por iteracao: " << iterative(n) << '\n';
                    break;
                }
                case 4: {
                    const int n = readIndex(kLargestExactIndex);
                    std::cout << "F(" << n << ") por dobra rapida: " << fastDoubling(n)
                              << '\n';
                    break;
                }
                case 5:
                    printBinetResult();
                    break;
                case 6:
                    printBinetExperiment();
                    break;
                case 0:
                    std::cout << "Ate mais!\n";
                    return 0;
                default:
                    std::cout << "Opcao inexistente. Escolha uma opcao do menu.\n";
            }
        } catch (const std::exception& error) {
            std::cout << "Erro: " << error.what() << '\n';
        }
    }
}

