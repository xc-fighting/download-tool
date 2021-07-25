#include "thread_pool.h"

void* routine(void* arg)
{


}


bool init_pool(thread_pool* pool, int thread_numbers)
{


}

bool add_task(thread_pool* pool, void* (*task)(void* arg), void* arg)
{


}

int add_thread(thread_pool* pool, int additional_thread)
{


}


int remove_thread(thread_pool* pool, int remove_numbers)
{


}

bool destroy_pool(thread_pool* pool)
{


}

