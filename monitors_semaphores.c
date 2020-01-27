#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore>

#define SIZE 10
#define NUMBER_OF_THREADS 10
#define Producer_Loops 4
#define Consumer_Loops 4

typedef int buffer_t;
buffer_t buffer[SIZE];

int buffer_index;
pthread_mutex_t buffer_mutex;

semaphore_t full_semaphore;
semaphore_t empty_semaphore;

void insertBuffer(buffer_t value){
	if(buffer_index < SIZE){
		buffer[buffer_index++] = value;
	}else{
	printf("Buffer overflow\n"); //user knows the buffer is overflow 
	}
	return 0;
}
buffer_t undobuffer(){
	if(buffer_index > 0){
		return buffer[--buffer_index];
	}else{
		printf("Buffer underflow\n"); //prints that the buffer is underflow. 
	}
}
int isempty() //Buffer is empty method
	if(buffer_index == 0)
		return TRUE;
	return FALSE:
}
int isfull(){ //Buffer is full method
	if(buffer_index == SIZE)
		return TRUE;
	return FALSE;
}
void *producer(void *thread_n){ //producer method
	int thread_num = *(int *)thread_n;
	buffer_t value;
	int i =0;
	while(i++ <Producer_loops){ //initial loop for producer
		sleep(rand() % 10);
		value = rand() % 100;
		pthread_mutex_lock(&buffer_mutex); //method to terminate the producer thread 
		do{
			semaphore_wait(&full_semaphore);
			pthread_mutex_unlock(&buffer_mutex);
			pthread_mutex_lock(&buffer_mutex);
		}while(isfull());
		insertBuffer(value);
		pathread_mutex_unlock(&buffer_mutex);
		semaphore_post(&empty_sem);
		printf("Producer %d added %d to buffer\n", thread_numb, value);
	}
	pthread_exit(0);
}
void *consumer(void *thread_n){ //consumer method
	int thread_number = *(int *)thread_n;
	buffer_t value;
	int i = o;
	while(i++ < CONSUMER_LOOPS){ // initial conusmer loop 
		pthread_mutex_lock(&buffer_mutex);
		do{
			pthread_mutex_unlock(&buffer_mutex); //method to terminate the thread
			semaphore_wait(&empty_semaphore);
			pthread_mutex_lock(&buffer_mutex);
		}while(isempty());
		value = undobuffer(value);
		pthread_mutex_unlock(&buffer_mutex);
		semaphore_post(&full_semaphore);
		printf("Consumer %d dequeue %d from buffer\n", thread_numb, value);
	}
	pthread_exit(0);
}
int main(int argc, int **argv){
	buffer_index =0;
	pthread_mutex_init(&buffer_mutex, NULL);
	semaphore_init(&full_semaphore, 0, SIZE);
	semaphore_init(&empty_semaphore, 0, 0);
	pthread_t thread[NUMBER_OF_THREADS];
	int thread_number[NUMBER_OF_THREADS]:
	int i;
	for(i=0; i < NUMBER_OF_THREADS; ){
		thread_number[i] = i;
		pthread_create(thread + i, NULL, producer, thread_number + 1);
		i++;
		thread_number[i] =i; 
		pthread_creat(&thread[i], NULL, consumer, &thread_number[i]);
		i++;
	}
	for(i=0; i < NUMBER_OF_THREADS; i++)
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&buffer_mutex);
	semaphore_destroy(&full_semaphore);
	semaphore_destroy(&empty_semaphore);
	return 0;
}