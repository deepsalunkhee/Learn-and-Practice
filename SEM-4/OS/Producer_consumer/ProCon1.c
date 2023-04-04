#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];   // Shared buffer
int in = 0, out = 0;       // Buffer pointers
sem_t empty, full, mutex;  // Semaphores for synchronization

// Producer function
void *producer(void *arg) {
    FILE *fp = fopen("Product.txt", "r");   // Open the input file
    int val;
    while (fscanf(fp, "%d", &val) == 1) {   // Read from the file 
        sem_wait(&empty);   // Wait until the buffer is not full
        sem_wait(&mutex);   // Wait to acquire the buffer lock
        buffer[in] = val;   // Insert the new item into the buffer
        in = (in + 1) % BUFFER_SIZE;   // Increment the buffer pointer
        printf("Produced: %d\n", val);  // Print the produced value
        sem_post(&mutex);   // Release the buffer lock
        sem_post(&full);    // Signal that the buffer is not empty
    }
    fclose(fp);  // Close the input file
    pthread_exit(NULL);  // Exit the thread
}


// Consumer function
void *consumer(void *arg) {
    int val;
    FILE *fp = fopen("Consumed_product.txt", "w");   // Open the output file
    while (1) {   // Run forever
        sem_wait(&full);   // Wait until the buffer is not empty
        sem_wait(&mutex);  // Wait to acquire the buffer lock
        val = buffer[out];  // Retrieve an item from the buffer
        out = (out + 1) % BUFFER_SIZE;  // Increment the buffer pointer
        fprintf(fp, "%d\n", val);  // Write the consumed value to the output file
        sem_post(&mutex);  // Release the buffer lock
        sem_post(&empty);  // Signal that the buffer is not full
    }
    fclose(fp);  // Close the output file
    pthread_exit(NULL);  // Exit the thread
}


int main() {
    sem_init(&empty, 0, BUFFER_SIZE);  // Initialize the empty semaphore to BUFFER_SIZE
    sem_init(&full, 0, 0);  // Initialize the full semaphore to 0
    sem_init(&mutex, 0, 1);  // Initialize the mutex semaphore to 1

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);  // Create the producer thread
    pthread_create(&consumer_thread, NULL, consumer, NULL);  // Create the consumer thread

    pthread_join(producer_thread, NULL);  // Wait for the producer thread to finish
    pthread_join(consumer_thread, NULL);  // Wait for the consumer thread to finish

    sem_destroy(&empty);  // Destroy the empty semaphore
    sem_destroy(&full);   // Destroy the full semaphore
    sem_destroy(&mutex);  // Destroy the mutex semaphore

    return 0;
}

