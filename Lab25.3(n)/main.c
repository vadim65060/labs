#include"queue.h"

int main() {
    queue *q = queue_alloc();
    queue_insert(q, 0);
    queue_insert(q, 1);
    queue_insert(q, 2);
    queue_insert(q, 3);
    queue_insert(q, 4);
    queue_insert(q, 5);
    queue_insert(q, 6);
    queue_insert(q, 7);
    queue_print(q);
    queue *newQ = queue_divide(q);
    queue_print(q);
    queue_print(newQ);
    queue_insert(q,10);
    queue_print(q);
    queue_free(q);
    queue_free(newQ);
}