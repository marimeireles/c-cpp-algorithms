#include <iostream>
#include <string>

struct node
{
    int element;
    node *next;
    node *prev;
};

typedef struct
{
    node *head;
}list;

node *list_search(list *l, int key)
{
    node *x = l->head;
    while (x != nullptr && x->element != key)
        x = x->next;
    return x;
}

void list_insert(list *l, node *x)
{
    x->next = l->head;
    if (l->head != nullptr)
        l->head->prev = x;
    l->head = x;
    printf("%d\n", l->head->element);
    x->prev = nullptr;
}

void list_delete(list *l, int key)
{
    node *x = list_search(l, key);
    if (x->prev != nullptr)
        x->prev->next = x->next;
    else 
        l->head = x->next;
    if (x->next != nullptr)
        x->next->prev = x->prev;
}

int main(int argc, char const *argv[])
{
    list l;
    l.head = nullptr;

    //test
    node x;
    x.element = 1;
    node y;
    y.element = 2;

    list_insert(&l, &x);
    list_insert(&l, &y);

    node *result;
    result = list_search(&l, 2);
    printf("%d\n", result->element);

    list_delete(&l, 2);

    return 0;
}