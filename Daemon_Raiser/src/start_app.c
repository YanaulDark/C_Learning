#include <Daemon_Raiser.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void* test(void* arg) {
    char* msg = (char*)arg;
    printf("Your text is %s. Yeah? \n", msg);   // не забудь \n
    return NULL;
}

int main(void) {
    unsigned long long qua;
    char message[256];
    if (scanf("%lld %255s", &qua, message) != 2) {
        fprintf(stderr, "bad input\n");
        return 1;
    }

    pthread_t threads[qua];   // VLA — массив переменной длины 
    pthread_add(threads, qua, test, message); 
    pthread_close(threads, qua);
    return 0;
}
