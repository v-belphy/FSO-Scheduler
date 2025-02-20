#pragma once

#include "process.h"
#include <stddef.h>
#include <stdint.h>

int64_t fifo(Process processes[], const size_t n);
int64_t sjf(Process processes[], const size_t n);
int64_t roundRobin(Process processes[], const size_t n, const int64_t quantum);
