#include <stdlib.h>
#include <assert.h>
#include "tree.h"

void test_add()
{
	TREENODE *root = tree_node_alloc(), *child = tree_node_alloc();

	tree_node_append_child(root, child);

	assert(root->parent == NULL);
	assert(child->parent == root);
	assert(tree_node_children_count(root) == 1);

	tree_node_free(root);
}

void test_remove_childs()
{
	TREENODE *root = tree_node_alloc();
	tree_node_remove_childs(root);
	assert(root != NULL);
	tree_node_free(root);
}

void test_get_parent()
{
	TREENODE *root = tree_node_alloc(),
	    *child1 = tree_node_alloc(), *child11 = tree_node_alloc();

	tree_node_append_child(root, child1);
	tree_node_append_child(child1, child11);

	/*assert(tree_node_get_parent(root, root) == NULL);
	   assert(tree_node_get_parent(root, child1) == root);
	 */
	assert(tree_node_get_parent(root, child11) == child1);

	tree_node_free(root);
}

int main()
{
	test_add();
	test_remove_childs();
	test_get_parent();
	return 0;
}
