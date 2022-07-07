#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAXIMUM_QUEUE_SIZE 200

typedef struct _node
{
    Data data;
} NODE;

typedef struct _queue
{
    int size;
    int first;
    int last;
    NODE *node;
} QUEUE;

Queue newQueue()
{
    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
    if (queue == NULL)
    {
        printf("ERROR: Could not allocate memory for empty queue.\n");
        exit(EXIT_FAILURE);
    }
    queue->first = 0;
    queue->size = 0;
    queue->last = 0;
    queue->node = (NODE *)malloc(MAXIMUM_QUEUE_SIZE * sizeof(NODE));
    if (queue->node == NULL)
    {
        printf("ERROR: Could not allocate memory for queue items.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < MAXIMUM_QUEUE_SIZE; i++)
    {
        queue->node[i].data = NULL;
    }
    return queue;
}

bool isQueueEmpty(Queue queue)
{
    if (queue == NULL)
    {
        return true;
    }
    QUEUE *newQueue = (QUEUE *)queue;
    return newQueue->size == 0;
}

bool isQueueFull(Queue queue)
{
    if (queue == NULL)
    {
        return true;
    }
    QUEUE *newQueue = (QUEUE *)queue;
    return newQueue->size == MAXIMUM_QUEUE_SIZE;
}

void enqueue(Queue queue, Data data)
{
    if (queue == NULL || data == NULL)
    {
        return;
    }
    if (isQueueFull(queue))
    {
        printf("WARNING: Queue is full.\n");
        return;
    }
    QUEUE *newQueue = (QUEUE *)queue;
    newQueue->node[newQueue->last].data = data;
    newQueue->last++;
    if (newQueue->last == MAXIMUM_QUEUE_SIZE)
    {
        newQueue->last = 0;
    }
    newQueue->size++;
}

Data dequeue(Queue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    if (isQueueEmpty(queue))
    {
        printf("WARNING: Queue is empty.\n");
        return NULL;
    }
    QUEUE *newQueue = (QUEUE *)queue;
    Data data = newQueue->node[newQueue->first].data;
    newQueue->node[newQueue->first].data = NULL;
    newQueue->first++;
    if (newQueue->first == MAXIMUM_QUEUE_SIZE)
    {
        newQueue->first = 0;
    }
    newQueue->size--;
    return data;
}

Data peekQueue(Queue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    if (isQueueEmpty(queue))
    {
        printf("WARNING: Queue is empty.\n");
        return NULL;
    }
    QUEUE *newQueue = (QUEUE *)queue;
    return newQueue->node[newQueue->first].data;
}

void freeQueue(Queue queue, void (*freeData)())
{
    if (queue == NULL)
    {
        return;
    }
    if (freeData != NULL)
    {
        while (!isQueueEmpty(queue))
        {
            freeData(dequeue(queue));
        }
    }
    QUEUE *newQueue = (QUEUE *)queue;
    free(newQueue->node);
    free(queue);
    queue = NULL;
}
