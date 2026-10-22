# Algoritmos de Fibonacci em C++

Projeto desenvolvido como estudo para a disciplina de **Linguagens de Programação**. A atividade foi proposta pelo professor para pesquisar diferentes algoritmos de Fibonacci e aprofundar o estudo da fórmula de Binet. O código foi escrito em C++ com nomes em português e dividido em arquivos pequenos para facilitar o aprendizado.

Este repositório também serve como registro pessoal: a ideia é poder revisitar no futuro os conceitos, implementações e conclusões do experimento, mesmo depois de concluir a disciplina.

## Contexto da atividade

O ponto de partida foi estudar os modelos de cálculo da sequência de Fibonacci e entender como diferentes abordagens se expressam em C++, quais são seus custos e onde aparecem limitações práticas. O foco especial é a fórmula de Binet: sua origem matemática, a aparente promessa de cálculo direto e os erros de precisão de ponto flutuante observados na implementação.

## Sobre o enunciado

A definição da sequência é a base matemática. O programa compara três maneiras de calcular os termos — recursão simples, recursão com memória e iteração — e também mostra o resultado aproximado da fórmula de Binet, que é o foco do experimento.

## Algoritmos comparados

| Método | Tempo | Ideia |
|---|---:|---|
| Recursivo simples | Exponencial | Traduz a definição, mas repete cálculos. |
| Recursivo com memória | O(n) | Guarda valores já calculados. |
| Iterativo | O(n) | Avança guardando os dois termos anteriores. |
| Fórmula de Binet | Depende da implementação de `std::pow` | Calcula uma aproximação e arredonda. |

φ representa a razão áurea. As complexidades contam operações aritméticas em um modelo simplificado; com inteiros de precisão arbitrária, o custo de cada operação também cresce com o tamanho do número.

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
