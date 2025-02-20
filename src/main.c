#include "alg.h"
#include "process.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "deps.h"

#define FIFO 0
#define SJF 1
#define ROUND_ROBIN 2

int main(void) {

    size_t n;
    printf("Insira a quantidade de processos: ");
    scanf("%zu", &n);

    Process processes[n];

    for (size_t i = 0; i < n; i++) {
        int64_t pid, startTime, expectedTime;
        printf("Insira o PID do processo: ");
        scanf("%ld", &pid);
        printf("Insira o tempo de chegada do processo: ");
        scanf("%ld", &startTime);
        printf("Insira o tempo de execucao do processo: ");
        scanf("%ld", &expectedTime);

        processes[i] = (Process){
            .pid = pid,
            .startTime = startTime,
            .expectedTime = expectedTime,
            .elapsed = 0,
            .finishTime = -1,
        };
    }

    int32_t algChoice;
    printf(
        "Insira a escolha de algoritmo (0 para FIFO, 1 para SJF, 2 para RR): ");
    scanf("%d", &algChoice);

    int64_t totalElapsed;

    switch (algChoice) {
    case FIFO:
        totalElapsed = fifo(processes, n);
        break;
    case SJF:
        totalElapsed = sjf(processes, n);
        break;
    case ROUND_ROBIN: {
        int64_t quantum;
        printf("Insira o tempo quantum para RR: ");
        scanf("%ld", &quantum);
        if (quantum < 1) {
            fprintf(stderr, "Quantum deve ser maior ou igual a 1");
            return 1;
        }
        totalElapsed = roundRobin(processes, n, quantum);
        break;
    }
    default:
        fprintf(stderr, "Opcao invalida\n");
        return 1;
    }

    int64_t totalWaitTime = 0;

    for (size_t i = 0; i < n; i++) {
        Process *crr = &processes[i];
        int64_t waitTime = crr->finishTime - crr->elapsed;
        totalWaitTime += waitTime;

        printf("Processo %ld\n", crr->pid);
        printf("    Tempo de chegada: %ld\n", crr->startTime);
        printf("    Tempo de execucao: %ld\n", crr->elapsed);
        printf("    Tempo de conclusao: %ld\n", crr->finishTime);
        printf("    Tempo de espera: %ld\n", waitTime);
        printf("\n");
    }

    printf("Tempo total percorrido: %ld\n", totalElapsed);
    printf("Tempo medio de espera: %.2f\n", (float)totalWaitTime / (float)n);

    return 0;
}
