#include "binary_trees.h"

/**
 * create_node - Creates a new AVL tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * array_to_avl - Recursive helper
 * function to build the AVL tree.
 * @array: Pointer to the first element of the array to be converted.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * @parent: Pointer to the parent node.
 *
 * Return: Pointer to the root node of the created AVL
 * tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = array_to_avl(array, start, mid - 1, root);
	root->right = array_to_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL
 * tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (array_to_avl(array, 0, size - 1, NULL));
}
