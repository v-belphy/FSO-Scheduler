#pragma once

#include <stdint.h>

typedef struct {
    int64_t pid;
    int64_t startTime;
    int64_t elapsed;
    int64_t expectedTime;
    int64_t finishTime;
} Process;

int compareByStartTime(const void *const a, const void *const b);
int compareByExpectedTime(const void *const a, const void *const b);
