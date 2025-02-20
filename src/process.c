#include "process.h"

int compareByStartTime(const void *const a, const void *const b) {
    Process *pa = (Process *)a;
    Process *pb = (Process *)b;
    if (pa->startTime == pb->startTime) {
        return pa->pid - pb->pid;
    } else {
        return pa->startTime - pb->startTime;
    }
}

int compareByExpectedTime(const void *const a, const void *const b) {
    Process *pa = (Process *)a;
    Process *pb = (Process *)b;
    if (pa->expectedTime == pb->expectedTime) {
        return compareByStartTime(a, b);
    } else {
        return pa->expectedTime - pb->expectedTime;
    }
}
