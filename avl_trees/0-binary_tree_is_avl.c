#include "binary_trees.h"
#include <limits.h>

/**
 * height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Helper function to check if a binary
 * tree is a BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed
 * @max: Maximum value allowed
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Helper function to check if a binary tree is
 * an AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX) &&
			is_avl(tree->left) &&
			is_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid
 * AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl(tree));
}
