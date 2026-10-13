#include <Daemon_Raiser.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>


int pthread_add(pthread_t* threads, unsigned long long qua, void* (*func)(void*), void* arg) {
    for (unsigned long long i = 0; i < qua; i++) {
        int rc = pthread_create(&threads[i], NULL, func, arg);
        if (rc != 0) return rc;
    }
    return 0;
}

int pthread_close(pthread_t* threads, unsigned long long qua) {
    for (unsigned long long i = 0; i < qua; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc != 0) return rc;
    }
    return 0;
}
