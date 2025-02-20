#include "alg.h"
#include "sleep.h"
#include <stdio.h>
#include <stdlib.h>

static int64_t min(const int64_t a, const int64_t b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int64_t roundRobin(Process processes[], const size_t n, const int64_t quantum) {
    qsort(processes, n, sizeof(Process), compareByStartTime); //ordena pelo tempo de chegada antes de executar o algoritmo

    //constroi um funcionamento de linked list
    size_t next[n];
    for (size_t i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = 0;

    size_t prev[n];
    for (size_t i = 1; i < n; i++)
        prev[i] = i - 1;
    prev[0] = n - 1;

    int64_t time = 0;
    size_t remaining = n, crrIdx = 0;

    while (remaining) {
        Process *crr = &processes[crrIdx];
        printf("Processo de PID %zu esta sendo processado\n", crr->pid);

        int64_t crrElapsed = min(quantum, crr->expectedTime - crr->elapsed); //tempo de processamento resultante
        _sleep((float)crrElapsed / 10); //simula processamento do processo, dando um sleep proporcional

        //atualiza os dados do processo após o final do processamento
        time += crrElapsed;
        crr->elapsed += crrElapsed;

        //atualiza a linked list caso o processo encerrar
        if (crr->elapsed >= crr->expectedTime) {
            crr->finishTime = time;

            size_t prevIdx = prev[crrIdx];
            size_t nextIdx = next[crrIdx];
            next[prevIdx] = next[crrIdx];
            prev[nextIdx] = prev[crrIdx];

            remaining--;
        }

        crrIdx = next[crrIdx];
    }

    return time;
}
