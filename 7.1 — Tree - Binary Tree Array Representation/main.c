#include <stdio.h>

#define MAX_SIZE 100 // Maximum number of nodes in the tree

int tree_arr[MAX_SIZE];

// Function to get the left child index based on parent index
int get_left_child(int index) {
    return (2 * index + 1);
}

// Function to get the right child index based on parent index
int get_right_child(int index) {
    return (2 * index + 2);
}

// Function to check if a node is a leaf (no children)
int is_leaf(int index) {
    return (tree_arr[get_left_child(index)] == -1 && tree_arr[get_right_child(index)] == -1);
}

// Function to insert a node at a specific index (assuming complete binary tree)
void insert(int value, int index) {
    if (index >= MAX_SIZE) {
        printf("Tree overflow\n");
        return;
    }
    tree_arr[index] = value;
}

// In-order traversal function (modify for preorder or postorder)
void in_order(int index) {
    if (index == -1 || is_leaf(index)) {
        return;
    }
    in_order(get_left_child(index));
    printf("%d ", tree_arr[index]);
    in_order(get_right_child(index));
}

int main() {
    // Initialize all elements to -1 (representing empty nodes)
    for (int i = 0; i < MAX_SIZE; i++) {
        tree_arr[i] = -1;
    }

    // Insert nodes (assuming complete binary tree for simplicity)
    insert(1, 0);
    insert(2, 1);
    insert(3, 2);
    insert(4, 3);

    printf("In-order traversal: ");
    in_order(0);
    printf("\n");

    return 0;
}
