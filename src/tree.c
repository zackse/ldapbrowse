#include "tree.h"
#include <stdlib.h>

TREENODE *tree_node_alloc()
{
	TREENODE *result = calloc(1, sizeof(TREENODE));
	return result;
}

void tree_node_free(TREENODE * n)
{
	tree_node_remove_childs(n);
	free(n->value);
	n->parent = NULL;
	n->value = NULL;
	free(n);
}

unsigned tree_node_children_count(TREENODE * root)
{
	unsigned i;
	for (i = 0; root->children && root->children[i] != NULL; i++)
		;
	return i;
}

TREENODE* tree_node_get_parent(TREENODE* root, TREENODE *node) {
	for (unsigned i = 0; root->children && root->children[i] != NULL; i++) {
    if(root->children[i] == node)
      return root;
    else {
      TREENODE * sub = tree_node_get_parent(root->children[i], node);
      if(sub)
        return sub;
    }
  }
  return NULL;
}

void tree_node_append_child(TREENODE * root, TREENODE * child)
{
	unsigned old_list_len = tree_node_children_count(root) + 1;
	child->parent = root;
	root->children = realloc(root->children, (old_list_len + 1) * sizeof(TREENODE *));
	root->children[old_list_len - 1] = child;
	root->children[old_list_len] = NULL;
}

void tree_node_remove_childs(TREENODE * n)
{
	for (unsigned i = 0; n->children && n->children[i] != NULL; i++)
	{
		tree_node_free(n->children[i]);
		n->children[i] = NULL;
	}

	if (n->children)
	{
		free(n->children);
		n->children = NULL;
	}
}
