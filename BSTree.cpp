/*
 * Binary Search Tree class
 * Do not alter the display() function, this will break the Repl.it
 * tests
 */

#include "BSTree.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Find Element in the Tree
 * find a node by item_key and provide an updated parent node
 *   pointer and location node pointer
 */

void BST::find(int item_key, node **prnt, node **loc) {
  node *ptr, *ptrsave;
  if (root == NULL) {
    *loc = NULL;
    *prnt = NULL;
    return;
  }
  if (item_key == root->key_value) {
    *loc = root;
    *prnt = NULL;
    return;
  }
  if (item_key < root->key_value)
    ptr = root->p_left;
  else
    ptr = root->p_right;
  ptrsave = root;
  while (ptr != NULL) {
    if (item_key == ptr->key_value) {
      *loc = ptr;
      *prnt = ptrsave;
      return;
    }
    ptrsave = ptr;
    if (item_key < ptr->key_value)
      ptr = ptr->p_left;
    else
      ptr = ptr->p_right;
  }
  *loc = NULL;
  *prnt = ptrsave;
}

/*
 * Inserting Element into the Tree
 */
void BST::insert(node *tree, node *newnode) {
  if (root == NULL) {
    root = newnode;
    return;
  }
  if (newnode->key_value < tree->key_value) {
    insert(tree->p_left, newnode);
    return;
  } else if (newnode->key_value > tree->key_value) {
    insert(tree->p_right, newnode);
}

/*
 * Delete Element from the tree
 */
void BST::remove(int item) {
  node *parent, *location;
  if (root == NULL) {
    cout << "Tree empty" << endl;
    return;
  }
  find(item, &parent, &location);
  if (location == NULL) {
    cout << "Item not present in tree" << endl;
    return;
  }
  if(root->key_value > item) {
    remove(root->p_left, item);
  } else if(root->key_value < item) {
    remove(root->p_right, k);
  }

  if (root->p_left == NULL) {
      Node* temp = root->p_right;
      delete root;
      return;
  } else if (root->p_right == NULL) {
      Node* temp = root->p_left;
      delete root;
      return;
  } else {
    Node* successor = root->right;
    while (successor->left != NULL) {
          successorParent = successor;
          successor = successor->left;
    }
    if (successorParent != root)
      successorParent->left = successor->right;
    else
      successorParent->right = successor->right;

    root->key = successor->key;
    delete successor;
    return;
  }
  free(location);
}

/*
 * Case 0
 * the node is simply removed no other updates necessary.
 */
void BST::case_0(node *prnt, node *loc) {
  // if (we are at the root)
  {
    // update the root
  }
  else {
    // otherwise simply remove node
  }
}

/*
 * Case 1
 * We have only one child so promote the child and replace the target
 * node
 */
void BST::case_1(node *prnt, node *loc) {
  node *child;
  // if (the child is on the left?)
  // point left
  // else  // must be the right side has child
  // point right
  // if (we are at the root handle specialy)
  {
    // update the root
  }
  else {
    // if (the node is left child of parent)
    // promote the left
    // else // the node is right of parent
    //     promote right
  }
}

/*
 * Case case_2
 * We have to find and promote a successor or predecessor
 */
void BST::case_2(node *prnt, node *loc) {
  // temporary pointers for node we are manipulating

  // Find successor: Step to the right child
  // Find the min of the subtree on parent's right

  // if (found node has no children)
  //  Replace the target node with the successor node
  else
  // Temporarily remove the successor node by replacing it with
  // its right child, we will replace the node we are removing
  // with the successor we just removed.

  // if (we are at root)
  {
    // then update root
  }
  else {
    // Insert the successor node where the target node we
    //   are removing is located
  }
  // then update the successor child pointers to reflect the old
  //     target's child pointers.
}

/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level) {
  int i;
  if (ptr != NULL) {
    display(ptr->p_right, level + 1);
    cout << endl;
    if (ptr == root)
      cout << "Root->:  ";
    else {
      for (i = 0; i < level; i++)
        cout << "       ";
    }
    cout << ptr->key_value;
    display(ptr->p_left, level + 1);
  }
}
