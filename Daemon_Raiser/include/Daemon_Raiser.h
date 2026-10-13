#ifndef DAEMON_RAISER_H
#define DAEMON_RAISER_H

#include <pthread.h>

int sum(int a, int b);
int pthread_add(pthread_t* threads, unsigned long long qua, void* (*func)(void*), void* arg);
int pthread_close(pthread_t* threads, unsigned long long qua);

#endif // DAEMON_RAISER_H
