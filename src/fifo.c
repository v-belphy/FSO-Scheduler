#include "alg.h"
#include "sleep.h"
#include <stdio.h>
#include <stdlib.h>

int64_t fifo(Process processes[], const size_t n) {
    qsort(processes, n, sizeof(Process), compareByStartTime); //ordena pelo tempo de chegada

    int64_t time = 0;
    for (size_t i = 0; i < n; i++) {
        Process *crr = &processes[i];
        printf("Processo de PID %zu esta sendo processado\n", crr->pid);

        _sleep((float)crr->expectedTime / 10); //simula processamento do processo, dando um sleep proporcional

        //atualiza os dados do processo após o final do processamento
        time += crr->expectedTime;
        crr->elapsed = crr->expectedTime;
        crr->finishTime = time;
    }

    return time;
}
