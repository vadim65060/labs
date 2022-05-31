#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "graph.h"

// Создание дерева
rb_tree *rb_alloc() {
    rb_tree *r = malloc(sizeof(rb_tree));
    if (!r) return NULL;

    r->root = NULL;
    return r;
}

// Рекурсивная очистка поддеревьев узла и самого узла
void rb_node_clear(rb_node *n) {
    if (!n) return;
    rb_node_clear(n->left);
    rb_node_clear(n->right);
    free(n->data);
    free(n);
}

// Удаление дерева из памяти
void rb_free(rb_tree **t) {
    rb_node_clear((*t)->root);
    free(*t);
    *t = NULL;
}

// Поиск в дереве по ключу
rb_node *rb_search(rb_tree *t, int key) {
    rb_node *x = t->root;

    while (x) {
        if (key < x->key) x = x->left;
        else if (key > x->key) x = x->right;
        else return x;
    }

    return NULL;
}

// Поиск узла с минимальным ключом
rb_node *rb_min(rb_tree *t) {
    rb_node *x = t->root;
    if (!x) return NULL;
    while (x->left) x = x->left;
    return x;
}

// Поиск узла с максимальным ключом
rb_node *rb_max(rb_tree *t) {
    rb_node *x = t->root;
    if (!x) return NULL;
    while (x->right) x = x->right;
    return x;
}

// Левое вращение дерева t вокруг узла x
void rb_rotate_left(rb_tree *t, rb_node *x, int check) {
    rb_node *y = x->right;
    if (!y)return;

    if (check) rbt_tree_graph(t, 8, x);
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    if (!x->parent)
        t->root = y;
    else {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->parent = x->parent;
    y->left = x;
    x->parent = y;
    if (check) rbt_tree_graph(t, 9, x);
}

// Правое вращение дерева t вокруг узла x
void rb_rotate_right(rb_tree *t, rb_node *x, int check) {
    rb_node *y = x->left;
    if (!y)return;
    if (check) rbt_tree_graph(t, 6, x);
    x->left = y->right;
    if (y->right)
        y->right->parent = x;
    if (!x->parent)
        t->root = y;
    else {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->parent = x->parent;
    y->right = x;
    x->parent = y;
    if (check) rbt_tree_graph(t, 7, x);
}

/* Вставка элемента с ключом key и данными data размера s
 *         в дерево t как в простое дерево поиска
 * Возвращает указатель на вставленный элемент или NULL в случае неудачи
 */
rb_node *rb_bst_insert(rb_tree *t, int key, const void *data, size_t s) {
    rb_node *y = NULL, *x = t->root,
            *z = malloc(sizeof(rb_node));
    if (!z) return NULL;

    z->key = key;
    z->color = RED;
    z->left = z->right = NULL;
    z->s = s;
    z->data = malloc(s);

    if (!z->data) {
        free(z);
        return NULL;
    }
    memcpy(z->data, data, s);
    while (x) {
        y = x;
        x = z->key < x->key ? x->left
                            : x->right;
    }
    z->parent = y;
    if (!y)
        t->root = z;
    else {
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }

    return z;
}

/* Вставка элемента с ключом key и данными data размера s в дерево t
 * Возвращает 0 в случае успеха, ненулевое значение в случае провала
 */
int rb_insert(rb_tree *t, int key, const void *data, size_t s) {
    rb_node *x = rb_bst_insert(t, key, data, s);
    int check;
    printf("Visualise? YES(1), NO(0): ");
    scanf("%i", &check);
    if (check) rbt_tree_graph(t, 2, t->root);
    if (!x) return -1;

    while (x != t->root && x->parent->color == RED) {
        rb_node *y = x->parent == x->parent->parent->left ? x->parent->parent->right
                                                          : x->parent->parent->left;

        if (y && y->color == RED) {
            x->parent->color = BLACK;
            y->color = BLACK;
            x->parent->parent->color = RED;
            x = x->parent->parent;
        } else {
            if (x->parent == x->parent->parent->left && x == x->parent->right) {
                rb_rotate_left(t, x->parent, check);
                x = x->left;
            } else if (x->parent == x->parent->parent->right && x == x->parent->left) {
                rb_rotate_right(t, x->parent, check);
                x = x->right;
            }
            x->parent->color = BLACK;
            x->parent->parent->color = RED;
            x == x->parent->left ? rb_rotate_right(t, x->parent->parent, check)
                                 : rb_rotate_left(t, x->parent->parent, check);
        }
    }
    t->root->color = BLACK;
    if (check) rbt_tree_graph(t, 3, t->root);
    return 0;
}

/* Удаление элемента с ключом key из дерева t
 * Возвращает 0, если элемент удален, ненулевое значение, если элемента нет
 */
int rb_delete(rb_tree *t, int key) {
    rb_node *x, *y, *z = t->root, *n = NULL;
    while (z && z->key != key)
        z = key < z->key ? z->left
                         : z->right;
    if (!z) return -1;
    if (!z->left || !z->right) {
        y = z;
        free(y->data);
    } else {
        rb_tree r;
        r.root = z->right;
        y = rb_min(&r);
        free(z->data);
        z->key = y->key;
        z->data = y->data;
        z->s = y->s;
    }
    int check;
    printf("Visualise? YES(1), NO(0): ");
    scanf("%i", &check);
    if (check) rbt_tree_graph(t, 4, t->root);
    x = y->left ? y->left : y->right;
    if (!x) {
        n = malloc(sizeof(rb_node));
        n->color = BLACK;
        x = n;
    }
    x->parent = y->parent;
    if (!y->parent)
        t->root = x;
    else {
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }
    if (y->color == BLACK) {
        while (x != t->root && x->color == BLACK) {
            rb_node *w = x == x->parent->left ? x->parent->right
                                              : x->parent->left;

            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                if (x == x->parent->left) {
                    rb_rotate_left(t, x->parent, check);
                    w = x->parent->right;
                } else {
                    rb_rotate_right(t, x->parent, check);
                    w = x->parent->left;
                }
            }
            if ((!w->left || w->left->color == BLACK) &&
                (!w->right || w->right->color == BLACK)
                    ) {
                w->color = RED;
                x = x->parent;
                if (x->color == RED) {
                    x->color = BLACK;
                    x = t->root;
                }
            } else {
                if ((x == x->parent->left && (!w->right || w->right->color == BLACK)) ||
                    (x == x->parent->right && (!w->left || w->left->color == BLACK))
                        ) {
                    w->color = RED;
                    if (x == x->parent->left) {
                        w->left->color = BLACK;
                        rb_rotate_right(t, w, check);
                        w = x->parent->right;
                    } else {
                        w->right->color = BLACK;
                        rb_rotate_left(t, w, check);
                        w = x->parent->left;
                    }
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (x == x->parent->left) {
                    w->right->color = BLACK;
                    rb_rotate_left(t, x->parent, check);
                } else {
                    w->left->color = BLACK;
                    rb_rotate_right(t, x->parent, check);
                }
                x = t->root;
            }
        }
        x->color = BLACK;
    }
    free(y);
    if (n) {
        if (n == t->root)
            t->root = NULL;
        else {
            if (n == n->parent->left)
                n->parent->left = NULL;
            else
                n->parent->right = NULL;
        }
        free(n);
    }
    if (check) rbt_tree_graph(t, 5, t->root);
    return 0;
}