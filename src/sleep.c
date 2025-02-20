#include <time.h>

void _sleep(double seconds) {
    struct timespec ts;
    ts.tv_sec = (int)seconds;
    ts.tv_nsec = (seconds - (int)seconds) * 1e9;
    if (ts.tv_nsec >= 1e9) {
        ts.tv_sec++;
        ts.tv_nsec -= 1e9;
    }
    nanosleep(&ts, NULL);
}
