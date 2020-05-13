#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define THREADS 4
/* the function called for each thread */
void* f(void* threadid) {
    long tid = (long)threadid;
    printf("Hello, World! from thread id : %ld\n", tid);
    pthread_exit(NULL);
}
int main ( ) {
    /* an array of threads */
    pthread_t threads[THREADS];
    /* start all of the threads */
    long t;
    for (t = 0; t < THREADS; t++) {
        pthread_create(&threads[t], NULL, f, (void *)t);
    }
    pthread_exit(NULL);
}

