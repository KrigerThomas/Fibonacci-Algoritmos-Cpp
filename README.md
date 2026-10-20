# Algoritmos de Fibonacci em C++

Projeto de estudo para comparar maneiras diferentes de calcular números de Fibonacci e investigar a precisão da fórmula de Binet.

## Sobre o enunciado

A definição da sequência é a base matemática, mas não é um algoritmo. Para comparar **quatro algoritmos**, este projeto implementa recursão simples, recursão com memoização, iteração e dobra rápida. A fórmula de Binet aparece como um quinto método de cálculo e como o foco do experimento de precisão.

## Algoritmos comparados

| Método | Tempo (operações aritméticas) | Espaço extra | Ideia |
|---|---:|---:|---|
| Recursivo simples | Θ(φⁿ) — frequentemente limitado por O(2ⁿ) | O(n) na pilha | Traduz a recorrência diretamente, mas repete cálculos. |
| Recursivo com memoização | O(n) | O(n) | Guarda resultados já calculados. |
| Iterativo | O(n) | O(1) | Avança mantendo os dois termos anteriores. |
| Dobra rápida | O(log n) | O(log n) na pilha | Usa identidades derivadas da multiplicação de matrizes. |
| Fórmula de Binet | Depende da implementação de `std::pow` | O(1) de memória | Calcula uma aproximação com ponto flutuante e arredonda. |

φ representa a razão áurea. As complexidades contam operações aritméticas em um modelo simplificado; com inteiros de precisão arbitrária, o custo de cada operação também cresce com o tamanho do número.

## Como compilar e executar

Com um compilador compatível com C++17, como g++:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic src/main.cpp -o fibonacci
```

No Windows PowerShell:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -pedantic src/main.cpp -o fibonacci.exe
.\fibonacci.exe
```

O menu permite executar cada método, comparar os resultados inteiros e procurar o primeiro índice em que Binet arredondada diverge do valor exato neste ambiente.

## Limites da demonstração

- Os métodos inteiros usam `uint64_t` e aceitam `0 ≤ n ≤ 93`. O termo `F(94)` já não cabe nesse tipo.
- A recursão simples é limitada a `n ≤ 40`, porque seu tempo cresce rapidamente.
- O índice em que Binet começa a errar não é uma constante universal: depende da biblioteca matemática, do tipo de ponto flutuante, do compilador e das opções usadas.
- Binet não é uma forma confiável de obter inteiros Fibonacci grandes. Para isso, prefira dobra rápida com um tipo inteiro de precisão suficiente.

## Material de estudo

- [Fundamentação matemática e comparação](docs/estudo.md)
- [Experimento de precisão de Binet](docs/experimento-binet.md)

## Autor

Projeto de estudo desenvolvido por [Thomás Kriger](https://github.com/KrigerThomas).

