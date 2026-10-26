# Estudo dirigido de Fibonacci

Essa pasta representa a atividade da disciplina de Linguagens de Programação, organizada conforme os arquivos e tarefas pedidos pelo professor.

## Conteudo

- `codigos/`: tarefas 01 a 04 e a classe da tarefa 05.
- `respostas-teoricas.txt`: respostas para as seis questoes.
- `prints/`: capturas do terminal para acrescentar depois de compilar e executar os programas.

## Compilar

Os comandos abaixo devem ser executados dentro da pasta `codigos`:

```powershell
g++ -std=c++17 tarefa01_natureza.cpp -o ../executaveis/tarefa01.exe
g++ -std=c++17 tarefa02_recursivo.cpp -o ../executaveis/tarefa02.exe
g++ -std=c++17 tarefa03_iterativo.cpp -o ../executaveis/tarefa03.exe
g++ -std=c++17 tarefa04_binet.cpp -o ../executaveis/tarefa04.exe
g++ -std=c++17 tarefa05/main.cpp tarefa05/CalculadoraFibonacci.cpp -o ../executaveis/tarefa05.exe
```

Depois de compilar, execute os programas a partir da pasta `codigos`:

```powershell
..\executaveis\tarefa01.exe
..\executaveis\tarefa02.exe
..\executaveis\tarefa03.exe
..\executaveis\tarefa04.exe
..\executaveis\tarefa05.exe
```

Os tempos medidos podem mudar de um computador para outro. O primeiro erro observado em Binet tambem pode variar conforme compilador e biblioteca.
