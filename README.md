# Algoritmos de Fibonacci em C++

Este repositório reúne meus estudos sobre a sequência de Fibonacci e os algoritmos usados para calculá-la. O projeto começou como uma atividade da disciplina de **Linguagens de Programação**, proposta pelo professor, e também serve como registro para eu consultar o conteúdo no futuro.

## Organização

- `src/`: programa principal e implementações dos algoritmos.
- `docs/`: anotações sobre a sequência, a comparação dos métodos e o experimento com a fórmula de Binet.
- `atividade-dirigida-fibonacci/`: arquivos da atividade passada pelo professor, separados do estudo principal.

## Algoritmos comparados

| Método | Tempo | Ideia |
|---|---:|---|
| Recursivo simples | Exponencial | Traduz a definição, mas repete cálculos. |
| Recursivo com memória | O(n) | Guarda valores já calculados. |
| Iterativo | O(n) | Avança guardando os dois termos anteriores. |
| Fórmula de Binet | Depende da implementação de `std::pow` | Calcula uma aproximação e arredonda. |

φ (phi) representa a razão áurea. As complexidades contam operações aritméticas em um modelo simplificado; com inteiros de precisão arbitrária, o custo de cada operação também cresce com o tamanho do número.

## Como compilar e executar

Com um compilador compatível com C++17, como g++:

```bash
g++ -std=c++17 src/main.cpp src/recursivo.cpp src/memoizado.cpp src/iterativo.cpp src/binet.cpp -o fibonacci.exe
./fibonacci.exe
```

No Windows PowerShell:

```powershell
g++ -std=c++17 src/main.cpp src/recursivo.cpp src/memoizado.cpp src/iterativo.cpp src/binet.cpp -o fibonacci.exe
.\fibonacci.exe
```

O programa pede um índice, mostra os resultados dos métodos e procura o primeiro índice em que Binet diverge do resultado exato neste ambiente. A recursão simples só é executada até `n = 40`, pois fica muito lenta para valores maiores.

## Limites da demonstração

- Os métodos inteiros usam `uint64_t` e aceitam `0 ≤ n ≤ 93`. O termo `F(94)` já não cabe nesse tipo.
- A recursão simples só é executada até `n ≤ 40`, porque seu tempo cresce rapidamente.
- O índice em que Binet começa a errar não é uma constante universal: depende da biblioteca matemática, do tipo de ponto flutuante, do compilador e das opções usadas.
- Binet não é uma forma confiável de obter inteiros Fibonacci grandes. Para isso, prefira um método inteiro com precisão suficiente.

## Material de estudo

- [Fundamentação matemática e comparação](docs/estudo.md)
- [Experimento de precisão de Binet](docs/experimento-binet.md)

## Autor

Projeto de estudo desenvolvido por [Thomás Kriger](https://github.com/KrigerThomas).
