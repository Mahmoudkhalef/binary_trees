#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: the height of the binary tree
 * or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftH, rightH;

	if (!tree)
		return (0);

	leftH = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	rightH = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (rightH > leftH ? rightH : leftH);
}

/**
 * print_level - Prints the binary tree level by level.
 *
 * @node: pointer to the node of the tree to print.
 * @level: The current level number.
 * @func: A pointer to the function to call for each node.
 *
 * Return: Nothing.
 */

void print_level(binary_tree_t *node, size_t level, void (*func)(int))
{
	if (node == NULL)
		return;

	if (level == 0)
		func(node->n);
	else
	{
		print_level(node->left, level - 1, func);
		print_level(node->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - Prints the binary tree by level order.
 *
 * @tree: pointer to the root node of the tree to print.
 * @func: A pointer to the function to call for each node.
 *
 * Return: Nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = binary_tree_height(tree);
	size_t i = 0;

	if (!tree || !func)
		return;

	for (; i <= height; i++)
	{
		print_level((binary_tree_t *)tree, i, func);
	}
}
