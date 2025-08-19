#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
    unsigned int height;
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

void swap(Node* node1 , Node* node2)
{
    int temp;
    
    temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;

}
unsigned int computeHeight(Node* rootNode)
{
    if(rootNode == NULL)
    {
        return 0;
    }

    unsigned int left =  computeHeight(rootNode->left);
    unsigned int right =  computeHeight(rootNode->right);
    rootNode->height=((left > right)?left:right) + 1;
    return rootNode->height;
}



void leftRotate(Node* node)
{
    if (!node || !node->right) return;

    // Swap values
    swap(node, node->right);

    Node* oldLeft = node->left;
    Node* rightChild = node->right;
    Node* newRight = rightChild->right;

    node->left = rightChild;
    node->right = newRight;
    node->left->right = rightChild->left;
    node->left->left = oldLeft;

    computeHeight(node->left);
    computeHeight(node);
}


void rightRotate(Node* node)
{
    if (!node || !node->left) return;

    // Swap values
    swap(node, node->left);

    Node* oldRight = node->right;
    Node* leftChild = node->left;
    Node* newLeft = leftChild->left;

    node->right = leftChild;
    node->left = newLeft;
    node->right->left = leftChild->right;
    node->right->right = oldRight;

    computeHeight(node->right);
    computeHeight(node);
}


int returnBalance(Node* root)
{
    int left,right;
    if(root->left == NULL)
    {
        left = 0;
    }
    else {
        left = root->left->height;
    }
    if(root->right == NULL)
    {
        right = 0;
    }
    else 
    {
        right = root->right->height;
    }
    return (left) - ( right );
}

void balanceTree(Node *node)
{
    if(node == NULL)
    {
        return;
    }

    int balance = returnBalance(node);

if (balance > 1 && returnBalance(node->left) >= 0)
    rightRotate(node);
else if (balance < -1 && returnBalance(node->right) <= 0)
    leftRotate(node);
else if (balance > 1 && returnBalance(node->left) < 0) {
    leftRotate(node->left);
    rightRotate(node);
}
else if (balance < -1 && returnBalance(node->right) > 0) {
    rightRotate(node->right);
    leftRotate(node);
}
}


void insert(Node* root,int value )
{
    if(root->value == value)
    {
        printf("Unable to add duplicate elements");
        return;
    }
    

    if( value > root->value )
    {
        if(root->right == NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;

        root->right = newNode;

        
        }
        else{
            insert(root->right , value );
        }

    }

    else 
    {
        if(root->left == NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height  = 0;

        root->left = newNode;
        }
        else{
            insert(root->left , value);
        }

    }

    unsigned int left =  computeHeight(root->left);
    unsigned int right =  computeHeight(root->right);
    root->height=((left > right)?left:right) + 1;

    balanceTree(root);
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
    printf("%d (%d)\n", rootNode->value,rootNode->height);

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
    computeHeight(rootNode);
    balanceTree(rootNode);
    return rootNode;
}


int main()
{
    Node node;
    node.value = 20;
    node.height = 1;
    node.left = NULL;
    node.right = NULL;
    insert(&node , 60);
    insert(&node , 42);
    insert(&node , 32);
    insert(&node , 10);
    //insert(&node , 10);
    insert(&node , 8);
    insert(&node , 15);
    delete(&node , 42);
    //balanceTree(&node);
 
    //computeHeight(&node );
    printTree(&node , 0);
}


