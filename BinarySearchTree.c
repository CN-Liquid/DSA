#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} Node;

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

void insert(Node* root,int value)
{
    if( value > root->value )
    {
        if(root->right == NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        root->right = newNode;
        }
        else{
            insert(root->right , value);
        }

    }

    else 
    {
        if(root->left == NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        root->left = newNode;
        }
        else{
            insert(root->left , value);
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
         printTabs(tabs);
    printf("NULL\n");
    return;
    }
    printTabs(tabs);
    printf("%d\n", rootNode->value);

    printTree(rootNode->left, tabs + 1);
    printTree(rootNode->right, tabs + 1);
}
Node* findMinNode(Node* root) {
    if (root == NULL)
        return NULL;

    // Keep going left until you hit the leftmost node
    if (root->left == NULL)
        return root;

    return findMinNode(root->left);
}

Node* delete(Node *rootNode , int value)
{
    if(rootNode == NULL)
    {
        printf("Key not found");
        return NULL;
    }

    if(value > rootNode->value)
    {
        rootNode->right = delete(rootNode->right,value);
    }
    else if(value < rootNode->value)
    {
        rootNode->left = delete(rootNode->left,value);
    }

    else if(rootNode->value == value)
    {
        if( ( rootNode->left == NULL ) && ( rootNode->right == NULL ) )
        {
            free(rootNode);
            return NULL;
        }
        else if(rootNode->left == NULL)
        {
            Node* temp = rootNode->right;
            free(rootNode);
            return temp;
        }
        else if(rootNode->right == NULL)
        {
            Node* temp = rootNode->left;
            free(rootNode);
            return temp;
        }
        else{
            Node* temp = findMinNode(rootNode->right);
            rootNode->value = temp->value;
            rootNode->right = delete(temp, rootNode->value);
        }
    }
    return rootNode;
}





void main()
{
    Node root ;
    root.left = NULL;  
    root.right = NULL; 
    root.value = 10;
    insert(&root , 15);
    insert(&root , 18);
    insert(&root , 17);
    insert(&root , 16);
    insert(&root , 12);
    insert(&root , 13);
    insert(&root , 9);
    insert(&root , 5);
    insert(&root , 3);
    insert(&root , 4);

    //delete(&root , 15);

    printTree(&root, 0);
}
