#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree.
 * @parent: pointer to the parent node.
 * @value: value of the node.
 * Return: A pointer to the node or return NULL.
 **/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->parent = parent;
    newNode->n = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return (newNode);
}