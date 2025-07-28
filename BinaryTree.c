#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} Node;

int isFilled(Node *node)
{
    if (node->left != NULL && node->right != NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    };
}

Node *returnDepthNode(Node *rootNode, int depth)
{
    int bit_depth = pow(2, depth) - 1;
    Node *temp_node = rootNode;
    Node *previous_node = rootNode;

    for (int i = 0; i <= bit_depth; i++)
    {
        int temp = depth;
        while (temp > 0)
        {
            if (((i >> (temp - 1)) & 1) == 0)
            {
                previous_node = temp_node;
                temp_node = temp_node->left;
            }
            else
            {
                previous_node = temp_node;
                temp_node = temp_node->right;
            }

            if (temp_node == NULL)
            {
                return previous_node;
            }

            temp--;
        }

        temp_node = rootNode;
    }
    return NULL;
}
void createNode(Node *rootNode, int value)
{
    if (rootNode == NULL)
    {
        printf("Unable to create node : current Node is null");
        return;
    }
    else
    {
        int stop = 0;
        int depth = 0;
        Node *node = NULL;
        while (stop == 0)
        {
            node = returnDepthNode(rootNode, depth);
            if (node != NULL)
            {
                break;
            }
            depth++;
        }

        Node *newNode = malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        if (node->left == NULL)
        {
            node->left = newNode;
        }
        else if (node->right == NULL)
        {
            node->right = newNode;
        }
    }
}

void printTabs(int tabs)
{
    for (int i = 0; i < tabs; i++)
    {
        printf("\t");
    }
}

void printTree(Node *rootNode, int tabs)
{
    if (rootNode == NULL)
    {
        return;
    }
    printTabs(tabs);
    printf("%d\n", rootNode->value);

    printTree(rootNode->left, tabs + 1);
    printTree(rootNode->right, tabs + 1);
}

int main()
{
    Node rootNode;
    rootNode.left = NULL;
    rootNode.right = NULL;
    rootNode.value = 10;

    createNode(&rootNode, 9);
    createNode(&rootNode, 8);
    createNode(&rootNode, 7);
    createNode(&rootNode, 6);
    createNode(&rootNode, 5);
    createNode(&rootNode, 4);
    createNode(&rootNode, 3);
    createNode(&rootNode, 2);
    createNode(&rootNode, 1);
    createNode(&rootNode, 0);
    createNode(&rootNode, -1);
    createNode(&rootNode, -2);
    createNode(&rootNode, -3);
    createNode(&rootNode, -4);

    printTree(&rootNode, 0);
}