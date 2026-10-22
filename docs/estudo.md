# Fundamentação matemática e comparação

## 1. Definição da sequência

A sequência de Fibonacci é definida por

\[
F_0=0,\qquad F_1=1,\qquad F_n=F_{n-1}+F_{n-2}\quad(n\geq 2).
\]

Assim, seus primeiros termos são `0, 1, 1, 2, 3, 5, 8, 13, ...`. A razão entre termos consecutivos se aproxima da razão áurea

\[
\varphi=\frac{1+\sqrt5}{2}\approx1{,}618.
\]

Essa parte do enunciado explica a sequência; não é, por si só, um algoritmo de computador.

## 2. Quatro algoritmos

### Recursão simples

A função espelha a definição: para `n ≥ 2`, calcula `F(n-1) + F(n-2)`. É a versão mais direta para aprender recursão, mas volta a calcular muitos dos mesmos termos. A recorrência do tempo tem a mesma forma da sequência, então o crescimento é Θ(φⁿ); O(2ⁿ) é uma cota superior comum e mais simples. A profundidade da pilha é O(n).

### Recursão com memoização

Antes de calcular um termo, a função verifica se já guardou seu valor. Cada índice é calculado uma vez, reduzindo o tempo para O(n), com O(n) de memória para a tabela e a pilha recursiva.

### Iteração

O programa mantém apenas os dois últimos valores e avança em um laço. Para um único `F(n)`, executa O(n) somas e usa O(1) de memória auxiliar.

## 3. De onde vem a fórmula de Binet?

Partimos da recorrência `F_n = F_(n-1) + F_(n-2)`. Procuramos soluções da forma `F_n = r^n`. Substituindo na recorrência e dividindo por `r^(n-2)`, obtemos a equação característica

\[
r^2-r-1=0.
\]

Suas raízes são

\[
\varphi=\frac{1+\sqrt5}{2},\qquad \psi=\frac{1-\sqrt5}{2}.
\]

A solução geral combina as duas raízes: `F_n = Aφⁿ + Bψⁿ`. Aplicando `F_0=0` e `F_1=1`, chegamos a `A=1/√5` e `B=-1/√5`. Logo,

\[
F_n=\frac{\varphi^n-\psi^n}{\sqrt5}.
\]

A fórmula é exata na matemática real. No computador, `φ`, `ψ`, `√5` e suas potências são representados com precisão finita. O resultado de ponto flutuante pode ficar ligeiramente acima ou abaixo do inteiro correto; arredondar recupera o inteiro somente enquanto o erro total for menor que metade da distância entre inteiros.

## 4. A conexão com matrizes

Defina

\[
A=\begin{bmatrix}1&1\\1&0\end{bmatrix}.
\]

Para `n ≥ 1`, vale

\[
A^n=\begin{bmatrix}F_{n+1}&F_n\\F_n&F_{n-1}\end{bmatrix}.
\]

Diagonalizar `A` separa suas duas raízes características, `φ` e `ψ`, e conduz à fórmula de Binet. Essa conexão é uma forma de entender de onde vem a expressão, mesmo sem implementar diagonalização no programa.

## 5. Por que O(1) pode enganar?

Uma expressão fechada tem um número fixo de símbolos, mas isso não prova que a avaliação computacional tenha custo constante para qualquer tamanho de entrada. `std::pow` é uma função de biblioteca; seu custo e sua precisão dependem da implementação e do tipo numérico. Além disso, o valor produzido cresce com `n`, e representar um inteiro com mais algarismos exige mais bits.

Para o exercício, é útil distinguir duas perguntas:

1. Quantas operações aritméticas o método executa?
2. Quanto custa cada operação e com quanta precisão ela é feita?

Em um modelo de máquina com `double` de largura fixa e entrada limitada, a chamada pode parecer constante. Isso não significa que Binet seja uma solução exata e escalável para inteiros arbitrariamente grandes.

## Referências

- [Fibonacci Number — Wolfram MathWorld](https://mathworld.wolfram.com/FibonacciNumber.html)
- [Aritmética de ponto flutuante: problemas e limitações — Documentação Python](https://docs.python.org/pt-br/3/tutorial/floatingpoint.html)
- [Rascunho de trabalho do padrão C++: funções matemáticas](https://eel.is/c++draft/c.math)
