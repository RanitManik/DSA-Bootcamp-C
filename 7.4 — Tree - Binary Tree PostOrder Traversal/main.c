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
    n->data = data; // inserting the data
    n->left = n->right = NULL; // inserting the left and right children to NULL
    return n; // Finally returning the node
}

void postOrderTraversal(struct node *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {

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

    // Finally, The tree looks like this:
    //      2
    //     / \
    //    1   4
    //   / \   \
    // 11  12   3

    postOrderTraversal(p);

    // Freeing the allocated memory
    free(p);
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(p5);

    return 0;
}