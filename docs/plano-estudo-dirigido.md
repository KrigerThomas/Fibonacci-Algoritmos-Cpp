# Plano para o estudo dirigido

O PDF pede uma entrega compactada com os códigos, as respostas teóricas e capturas de tela da compilação e execução. A entrega é pelo blog até a aula de **29/10/2026**.

## Organizar sem misturar os projetos

Minha sugestão é criar uma pasta separada para a atividade, ao lado deste projeto de estudo, por exemplo `D:\GitHub\estudo-dirigido-fibonacci`. O repositório atual continua como material de consulta e aprendizado. A atividade fica em sua própria pasta, com os arquivos exatamente nos nomes pedidos pelo professor. No final, uma pasta de entrega reúne `codigos/`, `respostas-teoricas.txt` e `prints/`, pronta para virar o ZIP exigido.

## Etapas

1. **Tarefa 01 — razão áurea:** escrever `tarefa01_natureza.cpp` para mostrar `F(n+1) / F(n)` até um limite e comparar com `φ`. Aqui “Natureza Numérica” é a investigação matemática da sequência, não um algoritmo separado.
2. **Tarefa 02 — recursão:** escrever `tarefa02_recursivo.cpp`, contar quantas vezes os casos base são chamados para `n = 10, 20, 30`, e explicar que o número total de chamadas cresce exponencialmente (`O(2^n)`). A pilha ativa tem profundidade `O(n)`; são medidas diferentes.
3. **Tarefa 03 — iteração:** escrever `tarefa03_iterativo.cpp` e comparar o tempo com a recursão para o mesmo `n`. A versão iterativa usa um laço, tempo `O(n)` e espaço extra `O(1)`.
4. **Tarefa 04 — Binet:** criar `tarefa04_binet.cpp`, comparar com a versão iterativa, registrar os valores em torno da primeira divergência e cronometrar `n = 10, 20, 40, 60, 70`. Completar a explicação da equação característica e das matrizes na resposta teórica.
5. **Tarefa 05 — classe:** só depois das funções isoladas, criar `tarefa05/CalculadoraFibonacci.h`, `CalculadoraFibonacci.cpp` e `main.cpp`. A classe reúne os métodos e imprime uma comparação; a interface fica no `.h` e as definições no `.cpp`.
6. **Respostas e evidências:** responder às seis questões em texto simples, guardar capturas legíveis do terminal e montar o ZIP com o nome e a estrutura exigidos no enunciado.

## Decisões que vale manter simples

- Usar `long long` nas tarefas porque esse é o tipo pedido no enunciado. Ele também tem limite: os testes com `n` devem ficar em uma faixa que caiba no tipo.
- Para os tempos, usar `std::chrono` se a diferença for visível; repetir medições pode ajudar quando a execução for rápida.
- Na tarefa de Binet, comparar com a iteração como referência exata dentro do intervalo representável e registrar o primeiro `n` observado, sem afirmar que o limite é universal.
- Não reutilizar o programa de menu atual como entrega direta: o professor pediu arquivos independentes, nomes próprios, protótipos antes de `main` em algumas tarefas e definições depois de `main`. O projeto atual serve de referência para as ideias.

## Lista final de conferência

- [ ] Quatro arquivos independentes das tarefas 01 a 04.
- [ ] Subprojeto da classe com três arquivos.
- [ ] Respostas das seis questões teóricas e análises críticas.
- [ ] Capturas da compilação e execução, incluindo o experimento de Binet.
- [ ] ZIP com `codigos/`, respostas e `prints/`, usando o nome solicitado.
