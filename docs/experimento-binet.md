# Experimento: quando Binet começa a falhar?

## Pergunta

Até qual índice a aplicação direta da fórmula de Binet, calculada com `double` e arredondada com `std::round`, coincide com o valor inteiro de Fibonacci?

## Procedimento

Depois de mostrar os resultados para o índice digitado, o programa percorre os índices de `0` a `93`. Para cada índice, compara o resultado de Binet arredondado com o resultado exato do método iterativo. A busca para na primeira divergência. O limite 93 é o maior usado neste projeto porque `F(94)` não cabe em `uint64_t`.

Para repetir:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -pedantic src/main.cpp src/recursivo.cpp src/memoizado.cpp src/iterativo.cpp src/binet.cpp -o fibonacci.exe
.\fibonacci.exe
```

Ao executar, o programa informa a primeira divergência encontrada neste computador.

## Resultado observado

Na execução deste projeto em **Windows x64, g++ 16.1.0 (MinGW-w64), C++17**, `double` informou 53 bits de precisão e compatibilidade com IEC 559 / IEEE 754.

| n | Binet arredondado | Valor exato iterativo | Resultado |
|---:|---:|---:|---|
| 70 | 190392490709135 | 190392490709135 | correto |
| 71 | 308061521170130 | 308061521170129 | primeira divergência |

Portanto, **n = 71 foi o primeiro índice incorreto neste ambiente e com estas opções de compilação**. Isso não deve ser apresentado como um limite universal: outra biblioteca de `pow`, outro compilador, outra precisão ou outras opções podem mudar o primeiro índice. O próprio programa imprime as características observadas e faz a busca novamente.

## Interpretação

Na matemática real, Binet produz exatamente `F(n)`. No programa, os valores irracionais e as potências são aproximados em ponto flutuante. `std::round` corrige o resultado somente enquanto o erro estiver a menos de meio inteiro do valor correto. Em `n = 71`, a aproximação já passou desse limite e o arredondamento devolveu o inteiro seguinte.

Esse experimento também mostra por que é impreciso chamar Binet simplesmente de algoritmo `O(1)`: o custo de avaliar `std::pow` depende da biblioteca e do modelo de cálculo. Mesmo que a chamada pareça constante para um `double` de tamanho fixo, ela não oferece precisão ilimitada para números que crescem com `n`.

## Observação para o relatório

Ao apresentar o resultado, informe sempre a plataforma, o compilador e as opções de compilação. A conclusão correta é “primeiro erro observado neste ambiente”, não “Binet sempre falha em n=71”.
