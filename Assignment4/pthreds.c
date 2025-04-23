#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

sem_t mutex, writer_mutex;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0;

// Reader function definition with correct return type
void *reader(void *param) {
    sem_wait(&mutex); // lock access to readercount
    readercount++;
    if (readercount == 1)
        sem_wait(&writer_mutex); // first reader locks writers out
    sem_post(&mutex); // release access to readercount

    printf("%d reader is inside\n", readercount);
    usleep(3); // simulate reading work

    sem_wait(&mutex); // lock access to readercount
    readercount--;
    if (readercount == 0)
        sem_post(&writer_mutex); // last reader allows writers
    sem_post(&mutex); // release access to readercount

    printf("%d reader is leaving\n", readercount + 1);
    return NULL;
}

// Writer function definition with correct return type
void *writer(void *param) {
    printf("Writer is trying to enter\n");
    sem_wait(&writer_mutex); // wait for writer access
    printf("Writer has entered\n");

    // simulate writing work
    usleep(3);

    sem_post(&writer_mutex); // release writer access
    printf("Writer is leaving\n");
    return NULL;
}

int main() {
    int n, i;
    printf("Enter the number of readers/writers: ");
    scanf("%d", &n);
    printf("\n");

    sem_init(&mutex, 0, 1); // initialize mutex semaphore
    sem_init(&writer_mutex, 0, 1); // initialize writer_mutex semaphore

    // Create threads
    for (i = 0; i < n; i++) {
        pthread_create(&readerthreads[i], NULL, reader, NULL); // Create reader thread
        pthread_create(&writerthreads[i], NULL, writer, NULL); // Create writer thread
    }

    // Wait for threads to finish
    for (i = 0; i < n; i++) {
        pthread_join(writerthreads[i], NULL); // Wait for writer thread to finish
        pthread_join(readerthreads[i], NULL); // Wait for reader thread to finish
    }

    return 0;
}
