#ifndef THREAD_POOL
#define THREAD_POOL

// include files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <errno.h>
#include <pthread.h>

// defines

#define MAX_WAITING_TASK 50
#define MAX_ACTIVE_THREAD 20

struct task 
{
   void* (*action)(void* arg);
   void* arg;
   struct task* next;
};

typedef struct thread_pool
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;

	bool shutdown;

	struct task* task_list;

	pthread_t* thread_ids;

	int max_waiting_tasks;
	int waiting_tasks;
	int active_threads;

}thread_pool;

bool init_pool(thread_pool* pool, int thread_numbers);

bool add_task(thread_pool* pool, void* (*task)(void* arg), void* arg);

int add_thread(thread_pool* pool, int additional_thread);

int remove_thread(thread_pool* pool, int remove_numbers);

bool destroy_pool(thread_pool* pool);

// entry function for all thread function
void* routine(void* arg);


#endif