#include "bst.h"
#include <iostream>

using namespace std;

int getSecondLargest(Node *node)
{
    if (node->right == nullptr && node->left == nullptr)
    {

        return -1;
    }
    else if (node->right == nullptr)
    {

        Node *temp = node->left;
        while (temp->right)
        {
            temp = temp->right;
        }

        return temp->val;
    }
    else
    {

        int a = getSecondLargest(node->right);
        if (a == -1)
        {
            return node->val;
        }
        else
        {
            return a;
        }
    }

    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char option;
    int val;
    int a, b;

    Node *root = NULL;

    while (scanf("%c %d\n", &option, &val) == 2)
    {
        if (option == 'I')
        {
            root = insertNode(root, val);
            printTree(root);
            printf("\n");
        }
        else if (option == 'D')
        {
            root = deleteNode(root, val);
            printTree(root);
            printf("\n");
        }
        else if (option == 'F')
        {
            if (find(root, val) != NULL)
                printf("Found\n");
            else
                printf("Not Found\n");
        }
        else if (option == 'T')
        {
            if (val == 1)
            {
                inOrder(root);
                printf("\n");
            }
            else if (val == 2)
            {
                preOrder(root);
                printf("\n");
            }
            else
            {
                postOrder(root);
                printf("\n");
            }
        }
        else if (option == 'G')
        {
            printf("%d\n", getSecondLargest(root));
        }
    }
    return 0;
}