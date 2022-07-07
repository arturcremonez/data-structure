#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _node
{
    struct _node *previous;
    Data data;
    struct _node *next;
} NODE;

typedef struct _list
{
    NODE *head;
    NODE *tail;
} LIST;

bool isListAllocated(List list)
{
    return list == NULL;
}

bool isNodeAllocated(Node node)
{
    return node == NULL;
}

bool isListEmpty(List list)
{
    if (isListAllocated(list))
    {
        return true;
    }
    LIST *newList = (LIST *)list;
    return newList->head == NULL;
}

NODE *newNode()
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node == NULL)
    {
        printf("ERROR: Could not allocate memory for new list Node.\n");
        exit(EXIT_FAILURE);
    }
    node->previous = NULL;
    node->data = NULL;
    node->next = NULL;
    return node;
}

List newList()
{
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (isListAllocated(list))
    {
        printf("ERROR: Could not allocate memory for new list.\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int getListSize(List list)
{
    if (isListAllocated(list))
        return 0;
    int size = 0;
    for (Node node = getFirstNode(list); node != NULL; node = getNextNode(node))
    {
        size++;
    }
    return size;
}

Node insertStart(List list, Data data)
{
    if (list == NULL || data == NULL)
    {
        return NULL;
    }
    LIST *newList = (LIST *)list;
    NODE *node = newNode();
    node->data = data;
    node->next = newList->head;
    if (!isListEmpty(list))
    {
        newList->head->previous = node;
    }
    newList->head = node;
    if (newList->tail == NULL)
    {
        newList->tail = newList->head;
    }
    return node;
}

Node insertEnd(List list, Data data)
{
    if (list == NULL || data == NULL)
    {
        return NULL;
    }
    if (isListEmpty(list))
    {
        return insertStart(list, data);
    }
    NODE *node = newNode();
    node->data = data;
    NODE *lastNode = getLastNode(list);
    lastNode->next = node;
    node->previous = lastNode;
    LIST *newList = (LIST *)list;
    newList->tail = node;
    return node;
}

Node insertAfter(List list, Node node, Data data)
{
    if (list == NULL || node == NULL || data == NULL)
    {
        return NULL;
    }
    if (getLastNode(list) == node)
    {
        return insertEnd(list, data);
    }
    NODE *newerNode = newNode();
    newerNode->data = data;
    NODE *newNode = (NODE *)node;
    newerNode->previous = newNode;
    newerNode->next = newNode->next;
    newNode->next->previous = newerNode;
    newNode->next = newerNode;
    return newerNode;
}

Node insertBefore(List list, Node node, Data data)
{
    if (list == NULL || node == NULL || data == NULL)
    {
        return NULL;
    }
    if (getFirstNode(list) == node)
    {
        return insertStart(list, data);
    }
    NODE *newerNode = newNode();
    newerNode->data = data;
    NODE *newNode = (NODE *)node;
    newerNode->next = newNode;
    newerNode->previous = newNode->previous;
    newNode->previous->next = newerNode;
    newNode->previous = newerNode;
    return newerNode;
}

Data removeNode(List list, Node node)
{
    if (list == NULL || node == NULL)
    {
        return NULL;
    }
    if (isListEmpty(list))
    {
        return NULL;
    }
    Data data = getNodeData(node);
    LIST *newList = (LIST *)list;
    NODE *newNode = (NODE *)node;
    if (getFirstNode(list) == node)
    {
        newList->head = newList->head->next;
    }
    if (getLastNode(list) == node)
    {
        newList->tail = newList->tail->previous;
    }
    if (newNode->previous != NULL)
    {
        newNode->previous->next = newNode->next;
    }
    if (newNode->next != NULL)
    {
        newNode->next->previous = newNode->previous;
    }
    newNode->previous = NULL;
    newNode->data = NULL;
    newNode->next = NULL;
    free(newNode);
    return data;
}

Data getNodeData(Node node)
{
    if (isNodeAllocated(node))
    {
        return NULL;
    }
    NODE *newNode = (NODE *)node;
    return newNode->data;
}

Node getFirstNode(List list)
{
    if (isListAllocated(list))
    {
        return NULL;
    }
    LIST *newList = (LIST *)list;
    return newList->head;
}

Node getLastNode(List list)
{
    if (isListAllocated(list))
    {
        return NULL;
    }
    if (isListEmpty(list))
    {
        return NULL;
    }
    LIST *newList = (LIST *)list;
    return newList->tail;
}

Node getNextNode(Node node)
{
    if (isNodeAllocated(node))
    {
        return NULL;
    }
    NODE *newNode = (NODE *)node;
    return newNode->next;
}

Node getpreviousiousNode(Node node)
{
    if (isNodeAllocated(node))
    {
        return NULL;
    }
    NODE *newNode = (NODE *)node;
    return newNode->previous;
}

Data ReplaceItem(Node node, Data data)
{
    if (node == NULL || data == NULL)
    {
        return NULL;
    }
    NODE *newNode = (NODE *)node;
    Data toReturn = newNode->data;
    newNode->data = data;
    return toReturn;
}

void freeList(List list, void (*freeData)())
{
    if (isListAllocated(list))
    {
        return;
    }
    if (freeData != NULL)
    {
        while (!isListEmpty(list))
        {
            freeData(removeNode(list, getFirstNode(list)));
        }
    }
    free(list);
    list = NULL;
}
