#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree
{
    int data;
    struct binarytree *left;
    struct binarytree *right;
} node;

node *create(int c)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = c;
    new->left = NULL;
    new->right = NULL;
}

node *search(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (root->data < key)
    {
        search(root->right, key);
    }
    else
        search(root->left, key);
}

node* insert(node** root,int c){
    if (*root == NULL){
        *root =create(c);
    }
    else{
     if(c < (*root)->data){
        (*root)->left=insert(&(*root)->left,c);
    }
    else {
        (*root)->right=insert(&(*root)->right,c);
    }
    }
    return *root;
}

node *inorderpredecessor(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *delete(node *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
        root->left = delete (root->left, value);
    else if (value > root->data)
        root->right = delete (root->right, value);
    else
    {
        node *iPre = inorderpredecessor(root);
        root->data = iPre->data;
        root->left = delete (root->left, iPre->data);
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->data);
    }
   
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void main()
{
    node *root = NULL;
    int n, data;
    printf("Enter the number of nodes you want in the binary tree:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(&root, data);
    }
    inorder(root);
    printf("\n");
    
    preorder(root);
    printf("\n");
    
    postorder(root);
    printf("\n");
}