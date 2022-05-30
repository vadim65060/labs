#ifndef RBT_H_INCLUDED
#define RBT_H_INCLUDED

/* ���� ����� */
typedef enum {RED,BLACK} rb_color;

/* ���� ������ */
typedef struct rb_node
{
    int      key;
    void    *data;
    size_t   s;
    rb_color color;
    struct rb_node *left, *right, *parent;
} rb_node;

/* ������ */
typedef struct rb_tree
{
    rb_node *root;
} rb_tree;

rb_tree *rb_alloc();// �������� ������

void rb_node_clear (rb_node *n);// ����������� ������� ����������� ���� � ������ ����

void rb_free(rb_tree **t);// �������� ������ �� ������

rb_node * rb_search (rb_tree *t, int key);// ����� � ������ �� �����

rb_node * rb_min (rb_tree *t);// ����� ���� � ����������� ������

rb_node * rb_max (rb_tree *t);// ����� ���� � ������������ ������

void rb_rotate_left (rb_tree *t, rb_node *x, int check);// ����� �������� ������ t ������ ���� x

void rb_rotate_right (rb_tree *t, rb_node *x, int check);// ������ �������� ������ t ������ ���� x

rb_node *rb_bst_insert (rb_tree *t, int key, const void *data, size_t s);
/* ������� �������� � ������ key � ������� data ������� s
 *         � ������ t ��� � ������� ������ ������
 * ���������� ��������� �� ����������� ������� ��� NULL � ������ �������
 */

int rb_insert (rb_tree *t, int key, const void *data, size_t s);
/* ������� �������� � ������ key � ������� data ������� s � ������ t
 * ���������� 0 � ������ ������, ��������� �������� � ������ �������
 */

int rb_delete (rb_tree *t, int key);
/* �������� �������� � ������ key �� ������ t
 * ���������� 0, ���� ������� ������, ��������� ��������, ���� �������� ���
 */

#endif // RBT_H_INCLUDED
