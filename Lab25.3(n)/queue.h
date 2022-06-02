#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


typedef struct node node;
struct node {
    node *next;
    int key;
};

typedef struct queue {
    node *head, *tail;
} queue;

node *node_alloc(int key);

void node_free(node *n);

queue *queue_alloc();

queue *queue_insert(queue *q, int key);

int queue_pop(queue *q);

queue *merge_queue(queue *q);

int queue_delete_node(queue *q, node *nodeToDel);

void queue_delete_for_id(queue *q, int id);

void queue_print(queue *q);

void queue_free(queue *q);

#endif // QUEUE_H_INCLUDED
