#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define Queue_size 10

int queue[Queue_size];   // Shared queue
int in = 0, out = 0;       // queue pointers
sem_t empty, full, mutex;  // Semaphores for synchronization

// Producer function
void *producer(void *arg) {
    FILE *fp = fopen("Product.txt", "r");   // Open the input file
    int val;
    while (fscanf(fp, "%d", &val) == 1) {   // Read from the file 
        sem_wait(&empty);   // Wait until the queue is not full
        sem_wait(&mutex);   // Wait to acquire the queue lock
        queue[in] = val;   // Insert the new item into the queue
        in = (in + 1) % Queue_size;   // Increment the queue pointer
        printf("Produced: %d\n", val);  // Print the produced value
        sem_post(&mutex);   // Release the queue lock
        sem_post(&full);    // Signal that the queue is not empty
    }
    fclose(fp);  // Close the input file
    pthread_exit(NULL);  // Exit the thread
}


// Consumer function
void *consumer(void *arg) {
    int val;
    FILE *fp = fopen("Consumed_product.txt", "w");   // Open the output file
    while (1) {   // Run forever
        sem_wait(&full);   // Wait until the queue is not empty
        sem_wait(&mutex);  // Wait to acquire the queue lock
        val = queue[out];  // Retrieve an item from the queue
        out = (out + 1) % Queue_size;  // Increment the queue pointer
        fprintf(fp, "%d\n", val);  // Write the consumed value to the output file
        printf("Consumed: %d\n", val);//consumed
        sem_post(&mutex);  // Release the queue lock
        sem_post(&empty);  // Signal that the queue is not full
    }
    fclose(fp);  // Close the output file
    pthread_exit(NULL);  // Exit the thread
}


int main() {
    sem_init(&empty, 0, Queue_size);  // Initialize the empty semaphore to Queue_size
    sem_init(&full, 0, 0);  // Initialize the full semaphore to 0
    sem_init(&mutex, 0, 1);  // Initialize the mutex semaphore to 1

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);  // Create the producer thread
    pthread_create(&consumer_thread, NULL, consumer, NULL);  // Create the consumer thread

    pthread_join(producer_thread, NULL);  // Wait for the producer thread to finish
    pthread_join(consumer_thread, NULL);  // Wait for the consumer thread to finish


    return 0;
}

