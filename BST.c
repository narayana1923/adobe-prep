#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} Node;

Node *root;

int read()
{
    int n;
    printf("Enter data: ");
    scanf("%d", &n);
    return n;
}

Node *newNode(int key)
{
    Node *temp = (Node *)calloc(1, sizeof(Node));
    temp->data = key;
    return temp;
}

Node *insert(Node *temp, int key)
{
    if (temp == NULL)
        return newNode(key);
    if (key < temp->data)
        temp->lchild = insert(temp->lchild, key);
    else if (key > temp->data)
        temp->rchild = insert(temp->rchild, key);

    return temp;
}

Node *search(Node *temp, int key)
{
    if (key < temp->data)
        search(temp->lchild, key);
    else if (key > temp->data)
        search(temp->rchild, key);
    else if (key == temp->data)
        return temp;
    else
        return NULL;
}

int findMin(Node *temp)
{
    int min;
    Node *prev = temp;
    temp = temp->rchild;
    while (temp->lchild != NULL)
    {
        prev = temp;
        temp = temp->lchild;
    }
    min = temp->data;
    if (temp->rchild != NULL)
    {
        prev->rchild = temp->rchild;
        free(temp);
    }
    else
    {
        if (temp == prev->lchild)
            prev->lchild = NULL;
        else if (temp == prev->rchild)
            prev->rchild = NULL;
        free(temp);
    }
    return min;
}

void deleteElem(int elem, Node *temp, Node *prev)
{
    if (temp->lchild == NULL && temp->rchild == NULL && temp->data == elem)
    {
        if (prev->rchild == temp)
            prev->rchild = NULL;
        else if (prev->lchild == temp)
            prev->lchild = NULL;
        free(temp);
    }
    else if (temp->data == elem)
    {
        if (temp->lchild != NULL && temp->rchild != NULL)
        {
            temp->data = findMin(temp);
            return;
        }
        if (prev == root)
        {
            if (prev->lchild == NULL)
                root = root->rchild;
            else if (prev->rchild == NULL)
                root = root->lchild;
            free(prev);
        }
        else
        {
            if (temp->rchild == NULL && temp->lchild != NULL)
            {
                if (prev->lchild == temp)
                    prev->lchild = temp->lchild;
                else
                    prev->rchild = temp->lchild;
            }
            else if (temp->lchild == NULL && temp->rchild != NULL)
            {
                if (prev->lchild == temp)
                    prev->lchild = temp->rchild;
                else
                    prev->rchild = temp->rchild;
            }
            free(temp);
        }
    }
    printf("\nDeleted successfully");
}

void findElement(int elem, Node *temp, Node *prev)
{
    if (temp->data == elem)
        deleteElem(elem, temp, prev);
    else if (temp->data != elem && temp->lchild == NULL && temp->rchild == NULL)
        printf("\nElement not found");
    else if (temp->data < elem)
        findElement(elem, temp->rchild, temp);
    else if (temp->data > elem)
        findElement(elem, temp->lchild, temp);
}

void delete (int elem, Node *temp, Node *temp1)
{
    if (root == NULL)
        printf("\nBST is already empty!!!\n");
    else if (root->lchild == NULL && root->rchild == NULL)
    {
        if (root->data == elem)
        {
            free(root);
            root = NULL;
            printf("\nElement successfully deleted and BST is empty now\n");
        }
        else
            printf("\nELement not found\n");
    }
    else
        findElement(elem, temp, temp1);
}

void inorder(Node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->lchild);
    printf("%d -> ", temp->data);
    inorder(temp->rchild);
}

int main()
{
    root = insert(root, read());
    insert(root, read());
    insert(root, read());
    insert(root, read());
    insert(root, read());
    insert(root, read());
    insert(root, read());
    insert(root, read());
    inorder(root);
    delete (read(), root, root);
    inorder(root);
    delete (read(), root, root);
    inorder(root);
    delete (read(), root, root);
    inorder(root);
    return 0;
}