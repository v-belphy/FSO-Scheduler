Projeto de Fundamentos de Sistemas Operacionais (FSO) da Universidade de Brasília (UnB)

Autores: Belphy Pierre Starling (202006420) e Elaina Lynn de Moura Amaral (200016750)

# Visão Geral

Este projeto é um simulador de escalonamento de processos que permite a entrada de processos via terminal e a escolha entre três algoritmos de escalonamento:
- FIFO (First In, First Out)
- SJF (Shortest Job First) - Não Preemptivo
- Round Robin

# Como Funciona
O projeto rodou em uma máquina linux e uma máquina windows pelo wsl.

Para compilar e rodar, digite o comando: `make run`

Caso der erro, compile manualmente com `g++ main.cpp -o a` e rode com `./a`
(O executável estará no diretório /dist/out)

O usuário insere os processos pelo terminal, informando:

- ID do Processo
- Tempo de Chegada
- Tempo de Execução

Após a entrada de todos os processos, o usuário escolhe um algoritmo de escalonamento.

O simulador processa cada processo, imprimindo mensagens indicando qual processo está em execução.

A execução de cada processo é simulada com um sleep proporcional ao tempo de execução: 0.1 * tempo_de_execucao segundos.

Quando o tempo de execução de um processo é atingido, ele é encerrado.

Ao final da simulação para cada processo é exibido:
- ID do processo
- Tempo de chegada
- Tempo de execução
- Tempo de conclusao
- Tempo de espera

E por fim:
- Tempo total percorrido
- Tempo total de espera
