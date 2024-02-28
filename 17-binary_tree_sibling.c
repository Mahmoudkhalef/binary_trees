#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node
 * or NULL otherwise
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *P, *R, *L;

	if (!node || !node->parent)
		return (NULL);
	P = node->parent;
	R = P->right;
	L = P->left;
	if (node == L)
		return (R);

	return (L);
}
