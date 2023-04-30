#include <iostream>
#include <semaphore.h>
#include <pthread.h>

using namespace std;

sem_t mutex, wrt;
int shared_data = 0;
int reader_count = 0;

void *writer(void *arg)
{
    sem_wait(&wrt);
    shared_data++;
    cout << "Data written by the writer is: " << shared_data << endl;
    sem_post(&wrt);
}

void *reader(void *arg)
{
    sem_wait(&mutex);
    reader_count++;
    if(reader_count == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    cout << "Data read by the reader is: " << shared_data << endl;
    sem_wait(&mutex);
    reader_count--;
    if(reader_count == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}

int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    pthread_t t1, t2, t3, t4;
    string type;

    while (true) {
        cout << "What would you like to do? (writer, reader, exit_reader, exit_writer, exit_program)" << endl;
        cin >> type;

        if (type == "writer") {
            pthread_create(&t1, NULL, writer, NULL);
        } else if (type == "reader") {
            pthread_create(&t2, NULL, reader, NULL);
            
        } else if (type == "exit_reader") {
            if (reader_count > 0) {
                cout << "Reader(s) are still inside. Cannot exit." << endl;
            } else {
                cout << "No reader inside. Cannot exit." << endl;
            }
        } else if (type == "exit_writer") {
            sem_post(&wrt);
            cout << "Writer exited the shared area." << endl;
        } else if (type == "exit_program") {
            break;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

