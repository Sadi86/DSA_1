/*
    Tree like this:
                1
               / \
              /   \
             2     3
            / \   / \
           4   5 6   7

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void preOrderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    struct node *root = create_node(1);
    struct node *t1 = create_node(2);
    root->left = t1;
    struct node *t2 = create_node(3);
    root->right = t2;
    struct node *t3 = create_node(4);
    t1->left = t3;
    struct node *t4 = create_node(5);
    t1->right = t4;
    struct node *t5 = create_node(6);
    t2->left = t5;
    struct node *t6 = create_node(7);
    t2->right = t6;

    preOrderTraversal(root);

    free(root);
    free(t1);
    free(t2);
    free(t3);
    free(t4);
    free(t5);
    free(t6);

    return 0;
}