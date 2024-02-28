#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *tmp1 = first;
	const binary_tree_t *tmp2 = second;

	while (tmp1)
	{
		while (tmp2)
		{
			if (tmp1 == tmp2)
				return ((binary_tree_t *)tmp1);
			tmp2 = tmp2->parent;
		}
		tmp2 = second;
		tmp1 = tmp1->parent;
	}
	return (NULL);
}
