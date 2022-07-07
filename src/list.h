#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

/*
 * This module aims to define a doubly linked list as well as functions to handle it.
 */

typedef void *List;
typedef void *Node;
typedef void *Data;

/**
 * Output: List allocated.
 */
List newList();

/**
 * Input: list.
 * Output: true or false.
 */
bool isListEmpty(List list);

/**
 * Input: list.
 * Output: int.
 */
int getListSize(List list);

/**
 * Inputs: list, data.
 * Output: node.
 */
Node insertStart(List list, Data data);

/**
 * Inputs: list, data.
 * Output: node.
 */
Node insertEnd(List list, Data data);

/**
 * Inputs: list, node, data.
 * Output: node.
 */
Node insertAfter(List list, Node node, Data data);

/**
 * Inputs: list, node, data.
 * Output: node.
 */
Node insertBefore(List list, Node li, Data data);

/**
 * Inputs: list, node.
 * Output: data.
 */
Data removeNode(List list, Node li);

/**
 * Input: node.
 * Output: data.
 */
Data getNodeData(Node li);

/**
 * Input: list.
 * Output: node.
 */
Node getFirstNode(List list);

/**
 * Input: list.
 * Output: node.
 */
Node getLastNode(List list);

/**
 * Inputs: node.
 * Output: node.
 */
Node getNextNode(Node li);

/**
 * Inputs: node.
 * Output: node.
 */
Node getPreviousNode(Node li);

/**
 * Inputs: lista, data.
 * Output: data.
 */
Data replaceNode(List list, Data data);

/**
 * Inputs: list, freeData.
 */
void freeList(List list, void (*freeData)());

#endif
