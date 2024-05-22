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
    heap_t *newNode = binary_tree_node(NULL, value);

    if (newNode == NULL)
        return NULL;

    if (*root == NULL)
        return *root = newNode;

    /* Insert the new node at the bottom level */
    {
        heap_t *parent = *root;
        while (parent->left)
            parent = parent->left;

        if (parent->right == NULL)
            parent->right = newNode;
        else
        {
            while (parent->parent && parent == parent->parent->right)
                parent = parent->parent;
            if (parent->parent)
                parent = parent->parent->right;
            while (parent->left)
                parent = parent->left;
            parent->left = newNode;
        }
        newNode->parent = parent;
    }

    /* Restore the heap property */
    {
        heap_t *current = newNode;
        while (current->parent && current->n > current->parent->n)
        {
            int temp = current->n;
            current->n = current->parent->n;
            current->parent->n = temp;
            current = current->parent;
        }
    }

    return newNode;
}
