# Fibonacci: o que cada modelo faz

Este texto acompanha meu estudo de Linguagens de Programação. A ideia é explicar com palavras simples o que o programa faz e o que acontece quando cada método é executado.

## A sequência

Fibonacci começa com `F(0) = 0` e `F(1) = 1`. Depois, cada termo é a soma dos dois anteriores:

$$
F(n) = F(n-1) + F(n-2)
$$

Os primeiros termos são `0, 1, 1, 2, 3, 5, 8, 13...`. A “natureza numérica” do enunciado é essa parte matemática e suas propriedades. Ela descreve a sequência, mas não é um algoritmo.

## Recursão simples

A função segue a definição quase literalmente: para calcular `F(n)`, chama a si mesma para calcular `F(n-1)` e `F(n-2)`. Isso deixa a ideia fácil de reconhecer, mas repete muitos cálculos. Por exemplo, `F(5)` pede `F(4)` e `F(3)`, e o cálculo de `F(4)` também pede `F(3)`.

O tempo cresce exponencialmente, normalmente descrito como `O(2^n)` (uma estimativa simples; a taxa mais precisa é `Θ(φ^n)`). A pilha de chamadas, por outro lado, não guarda todas as chamadas da árvore ao mesmo tempo: a maior profundidade é `O(n)`. Portanto, `O(n)` descreve o espaço usado pela pilha, não o tempo. Para índices grandes, a função pode demorar muito; chamadas profundas também podem esgotar a pilha.

## Recursão com memória

É a recursão simples com uma tabela para guardar os termos já calculados. Se precisar de `F(3)` de novo, consulta a tabela em vez de recalcular. O nome dessa técnica é memoização. Ela continua sendo recursiva; não é recursão de cauda. É uma opção adicional do projeto, e tudo bem se por enquanto o foco ficar na recursão simples e na iteração.

## Iteração

A função começa com os dois primeiros valores e usa um laço para somá-los, avançando até chegar ao índice pedido. Não abre uma nova chamada da função para cada termo. Faz `O(n)` passos e usa `O(1)` espaço extra: mantém só algumas variáveis. Por isso costuma ser a opção mais simples e eficiente para calcular um termo de tamanho moderado.

## Fórmula de Binet

A fórmula calcula uma aproximação de `F(n)` diretamente, usando o índice `n`:

$$
F(n) = \frac{\varphi^n - \psi^n}{\sqrt{5}}
$$

Aqui `φ` (“phi”) é `(1 + √5) / 2`, aproximadamente `1,618`, e `ψ` (“psi”) é `(1 - √5) / 2`, aproximadamente `-0,618`. O símbolo `φ^n` significa “phi elevado a n”. Por exemplo, para calcular `F(5)`, colocamos 5 no lugar de cada `n`; o resultado matemático é 5.

No computador, esses valores são calculados como aproximações em `double`, que tem precisão finita. `std::round` arredonda o resultado antes de convertê-lo para inteiro. Em índices maiores, o pequeno erro pode passar de meio inteiro, e então o arredondamento devolve o inteiro vizinho errado. Isso explica por que Binet pode falhar perto de `n = 70` neste tipo de implementação; o primeiro índice exato depende do compilador e da biblioteca matemática.

Não é a razão áurea que muda quando `n` cresce. Se dividirmos termos consecutivos, `F(n+1) / F(n)`, o quociente se aproxima de `φ`. Essa convergência é uma propriedade da sequência. O erro de Binet é um problema separado, causado por precisão limitada ao calcular valores grandes.

## O que quer dizer “tempo constante” em Binet?

No papel, a fórmula tem um número fixo de operações. No código, porém, `std::pow` precisa calcular potências e os valores envolvidos crescem com `n`. Além disso, `double` tem tamanho e precisão fixos. Por isso, dizer simplesmente que Binet é `O(1)` esconde o custo da biblioteca e o limite de precisão; a fórmula também não produz inteiros exatos para todo `n`.

## Resumo pessoal

- **Recursão simples:** mais fácil de relacionar à definição, mas repete cálculos; tempo exponencial e pilha `O(n)`.
- **Iteração:** soma os dois termos anteriores dentro de um laço; tempo `O(n)` e espaço extra `O(1)`.
- **Recursão com memória:** guarda resultados para a recursão não recalcular termos; é uma otimização da recursão.
- **Binet:** fórmula fechada que aproxima o termo diretamente; pode errar por causa da precisão finita dos números reais no computador.
