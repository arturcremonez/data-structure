#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

/*
 * This module aims to define a circular static queue as well as functions to handle this type.
 */

typedef void *Queue;
typedef void *Data;

/*
 * Output: Queue.
 */
Queue newQueue();

/*
 * Input: Queue.
 * Outputs: true or false.
 */
bool isQueueEmpty(Queue queue);

/*
 * Input: Queue.
 * Outputs: true or false.
 */
bool isQueueFull(Queue queue);

/*
 * Inputs: Queue, Data.
 */
void enQueue(Queue queue, Data data);

/*
 * Input: Queue.
 * Output: Data.
 */
Data deQueue(Queue queue);

/*
 * Input: Queue.
 * Output: Data.
 */
Data peekQueue(Queue queue);

/*
 * Input: Queue, freeData -> Pointer to function to free memory used by Data.
 */
void freeQueue(Queue queue, void (*freeData)());

#endif
