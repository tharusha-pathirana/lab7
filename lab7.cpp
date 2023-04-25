#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    
  if (root == NULL) {
      
    struct node *temp1 = new node;
    temp1->key = key;
    temp1->left = temp1->right = NULL;
    return temp1;
  }

  if (key < root->key) {
    root->left = insertNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }

  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }

  else {
    // 1 child or none
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // 2 children
    struct node *temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }

    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  return 0;
}
