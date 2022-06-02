#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include"queue.h"

node *node_alloc(int key) {
    node *n = malloc(sizeof(node));
    if (!n) return NULL;
    n->next = NULL;
    n->key = key;
    return n;
}

void node_free(node *n) {
    n->next = NULL;
    free(n);
}

queue *queue_alloc() {
    queue *q = malloc(sizeof(queue));
    if (!q) return NULL;
    q->head = q->tail = NULL;
    return q;
}

queue *queue_insert(queue *q, int key) {
    if (!q) return NULL;
    node *n = node_alloc(key);
    if (!n) return q;
    if (!q->tail)
        q->tail = q->head = n;
    else {
        q->tail->next = n;
        q->tail = n;
    }
    return q;
}

int queue_pop(queue *q) {
    int x = q->head->key;
    if (q->head == q->tail) {
        node_free(q->head);
        q->head = NULL;
        q->tail = NULL;
        return x;
    } else {
        node *ptr = q->head;
        q->head = q->head->next;
        node_free(ptr);
    }
    return x;
}


queue *merge_queue(queue *q) {
    queue *newQ = queue_alloc();
    node *it = q->head;
    while (it != NULL) {
        if (it->key % 2) {
            queue_insert(newQ, it->key);
            node *temp = it;
            it = it->next;
            queue_delete_node(q, temp);
        } else {
            it = it->next;
        }
    }
    return newQ;
}


node *get_prev_node(queue *q, node *nodeToFind) {
    if (nodeToFind == q->head)
        return NULL;
    for (node *i = q->head; i != NULL; i = i->next) {
        if (i->next == nodeToFind)
            return i;
    }
    return NULL;
}

void queue_delete_for_id(queue *q, int id) {
    if (q && id >= 0) {
        if (id == 0) {
            node *temp = q->head;
            q->head = q->head->next;
            free(temp);
            return;
        }
        node *it = q->head;
        int i = 0;
        for (; it && i < id - 1; it = it->next, ++i);
        if (it && it->next) {
            node *temp = it->next;
            it->next = it->next->next;
            free(temp);
            if (!it->next) {
                q->tail = it;
            }
        }
    }
}

int queue_delete_node(queue *q, node *nodeToDel) {
    if (nodeToDel == q->head) {
        q->head = q->head->next;
        free(nodeToDel);
        return 0;
    }
    node *prevNode = get_prev_node(q, nodeToDel);
    if (prevNode == NULL)
        return 1;
    if (nodeToDel == q->tail) {
        q->tail = prevNode;
        q->tail->next = NULL;
        free(nodeToDel);
        return 0;
    }
    prevNode->next = nodeToDel->next;
    free(nodeToDel);
    return 0;
}


void queue_print(queue *q) {
    if (q) {
        for (node *temp = q->head; temp; temp = temp->next) {
            printf("%d ", temp->key);
        }
        printf("\n");
    }
}

void queue_free(queue *q) {
    if (q) {
        while (q->head) {
            queue_pop(q);
        }
        free(q);
    }
}
