#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the HEAP
    n->data = 2; // inserting the data
    n->left = n->right = NULL; // inserting the left and right children to NULL
    return n; // Finally returning the node
}

int main() {

    /*
     * MAKING NODES MANUALLY (NOT RECOMMENDED) =>
    // Root Node =>
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = p->right = NULL;

    // left Child of Root Node =>
    struct node *p1 = (struct node *) malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = p1->right = NULL;

    // right Child of Root Node =>
    struct node *p2 = (struct node *) malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = p2->right = NULL;

    // Linking the root node with his left and right children =>
    p->left = p1;
    p->right = p2;
     */

    /*
     * MAKING NODES WITH FUNCTION (RECOMMENDED) =>
    */
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);
    struct node *p3 = createNode(11);
    struct node *p4 = createNode(12);
    struct node *p5 = createNode(3);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->right = p5;

    // Freeing the allocated memory
    free(p);
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(p5);

    return 0;
}