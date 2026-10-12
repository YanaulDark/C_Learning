#include <Daemon_Raiser.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>


int pthread_add(pthread_t* threads, int qua, void* (*func)(void*), void* arg) {
    for (int i = 0; i < qua; i++) {
        int rc = pthread_create(&threads[i], NULL, func, arg);
        if (rc != 0) return rc;
    }
    return 0;
}

int pthread_close(pthread_t* threads, int qua) {
    for (int i = 0; i < qua; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc != 0) return rc;
    }
    return 0;
}
