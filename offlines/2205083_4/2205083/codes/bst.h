#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

Node *insertNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be inserted
    // Returns the pointer to the root of the modified BST.
    if (node==nullptr)
    {
       Node* tobeinserted = new Node;
    tobeinserted->val = val;
    tobeinserted->right = nullptr;
    tobeinserted->left = nullptr;
    return tobeinserted; 
    }
    if (val<node->val)
    {
        node->left = insertNode(node->left,val);
    }
    else if (val>node->val)
    {
        node->right = insertNode(node->right,val);
    }
    return node;
}

Node *deleteNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be deleted.
    // Returns the pointer to the root of the modified BST.
    if (node==nullptr) return nullptr;
    if (node->val==val) 
    {
        if (node->right==nullptr && node->left==nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left==nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right==nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else{
            Node* temp = node->right;
            while (temp && temp->left)
            {
                temp = temp->left;

            }
            node->val = temp->val;
            node -> right = deleteNode(node->right,node->val);

            return node;
        }
    }
    if (val>node->val) node->right=deleteNode(node->right,val);
    else node->left=deleteNode(node->left,val);
    return node;
}

Node* find(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be searched.
    // Returns the pointer to the node that contains val.
    // Returns NULL if not found.
    if (node==nullptr) return nullptr;
    if (node->val==val) return node;
    if (val>node->val) return find(node->right,val);
    else return find(node->left,val);
}

void inOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the in-order traversal of the given BST
    if (node==nullptr) return;
    inOrder(node->left);
    cout<<node->val<<" ";
    inOrder(node->right);
}

void preOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the pre-order traversal of the given BST
    if (node==nullptr) return;
    cout<<node->val<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the post-order traversal of the given BST

    if (node==nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->val<<" ";

}

void printTree(Node *root){
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints parenthesized representation of the given BST
    if (root==nullptr) {cout<<'_'; return;}
    cout<<root->val;
    if (root->right || root->left)
    {
        cout<<" (";
        printTree(root->left);
        cout<<", ";
        printTree(root->right);
        cout<<")";
    }
}