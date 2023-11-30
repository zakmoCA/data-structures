#include <stdlib.h>
#include <iostream>

using namespace std;

// every node has 2 child nodes at most
// these nodes are termed left and right nodes
// first node is the root, if node has at least 1 child it is parent, terminating nodes are leaf nodes

struct node {
  int data;
  struct node *left;
  struct node *right;
};

// making a new node
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

// traversing left to right or right to left known as preorder
void traversePreOrder(struct node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// leaf to root, then same (minus visiting root) on other subtree
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}

// like inorder but bottom up
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}

int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  cout << "preorder traversal: ";
  traversePreOrder(root); // 1 2 4 5 3 6 7
  cout << "\nInorder traversal: ";
  traverseInOrder(root); // 4 2 5 1 6 3 7
  cout << "\nPostorder traversal: ";
  traversePostOrder(root); // 4 5 2 6 7 3 1
}