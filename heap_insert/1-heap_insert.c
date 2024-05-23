#include <stdlib.h>
#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *newNode;
    heap_t *queue[1024]; /* Assuming the heap won't have more than 1024 nodes */
    int front = 0, rear = 0;
    heap_t *current;

    if (root == NULL)
        return NULL;

    newNode = binary_tree_node(NULL, value);
    if (newNode == NULL)
        return NULL;

    if (*root == NULL) {
        *root = newNode;
        return newNode;
    }

    queue[rear++] = *root;

    while (front < rear) {
        heap_t *parent = queue[front++];

        if (parent->left == NULL) {
            parent->left = newNode;
            newNode->parent = parent;
            break;
        } else {
            queue[rear++] = parent->left;
        }

        if (parent->right == NULL) {
            parent->right = newNode;
            newNode->parent = parent;
            break;
        } else {
            queue[rear++] = parent->right;
        }
    }

    current = newNode;
    while (current->parent && current->n > current->parent->n) {
        int temp = current->n;
        current->n = current->parent->n;
        current->parent->n = temp;
        current = current->parent;
    }

    return newNode;
}
