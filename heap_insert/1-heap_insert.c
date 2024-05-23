#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (root == NULL)
        return NULL;

    heap_t *newNode = binary_tree_node(NULL, value);
    if (newNode == NULL)
        return NULL;

    if (*root == NULL) {
        *root = newNode;
        return newNode;
    }

    /* Use an array-based queue for level-order traversal */
    heap_t *queue[1024]; /* Assuming the heap won't have more than 1024 nodes */
    int front = 0, rear = 0;

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

    /* Restore the heap property */
    heap_t *current = newNode;
    while (current->parent && current->n > current->parent->n) {
        int temp = current->n;
        current->n = current->parent->n;
        current->parent->n = temp;
        current = current->parent;
    }

    return newNode;
}
