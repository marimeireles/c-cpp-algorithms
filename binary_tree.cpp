#include <string>

typedef struct node{
    int element;
    node *parent;
    node *left;
    node *right;
}node;

typedef struct
{
    node *root;
}tree;

node *tree_search(node *x, int key)
{
    if ((x == nullptr) || (key == x->element))
        return x;
    if (key < x->element)
        return tree_search(x->left, key);
    else
        return tree_search(x->right, key);
}

void tree_insert(tree *t, node z)
{
    node *y = nullptr;
    node *x = t->root;
    while (x != nullptr)
    {
        y = x;
        if (z.element < x->element)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
            break;
        }
    }
    z.parent = y;
    if (y == nullptr)
        t->root = &z; //tree was empty
    else if (z.element < y->element)
        y->left = &z;
    else
        y->right = &z;
    }

int main(int argc, char const *argv[])
{
    tree t;
    node a, b, c, d, e, f;
    a.element = 5;
    b.element = 1;
    c.element = 3;
    d.element = 3;
    e.element = 0;
    f.element = 8;

    tree_insert(&t, a);
    tree_insert(&t, b);
    tree_insert(&t, c);
    tree_insert(&t, d);
    tree_insert(&t, e);
    tree_insert(&t, f);

    return 0;
}