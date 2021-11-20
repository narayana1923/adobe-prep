#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
    struct node *siblink;
} Node;
typedef struct queue
{
    Node *data;
    struct queue *link;
} Queue;

Node *root;
Queue *front, *rear;

int read()
{
    int n;
    printf("Enter data: ");
    scanf("%d",&n);
    return n;
}

void enqueue(Node *data)
{
    Queue *temp = (Queue *)calloc(1, sizeof(Queue));
    temp->data = data;
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

Node *dequeue()
{
    if (front == NULL)
    {
        return NULL;
    }
    else
    {
        Queue *var = front;
        front = front->link;
        return var->data;
    }
}

void insert_at_tree()
{
    Node *temp = (Node *)calloc(1, sizeof(Node));
    temp->data = read();
    if (root == NULL)
    {
        printf("Root node is %d\n", temp->data);
        root = temp;
    }
    else
    {
        enqueue(root);
        while (front)
        {
            Node *cur = dequeue();
            if (cur->lchild != NULL)
                enqueue(cur->lchild);
            else
            {
                cur->lchild = temp;
                break;
            }
            if (cur->rchild != NULL)
                enqueue(cur->rchild);
            else
            {
                cur->rchild = temp;
                break;
            }
        }
        while (dequeue())
            ;
    }
}

void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->lchild);
    printf("%d ", node->data);
    inorder(node->rchild);
}

void createSiblink()
{
    if (root == NULL)
    {
        printf("Not possible to create siblink\n");
    }
    else
    {

        Node *current = root;
        Node *last = root;

        while (current != NULL)
        {
            if (current->lchild != NULL)
            {
                last->siblink = current->lchild;
                last = current->lchild;
            }

            if (current->rchild != NULL)
            {
                last->siblink = current->rchild;
                last = current->rchild;
            }

            last->siblink = NULL;
            current = current->siblink;
        }
    }
}

void printList()
{
    printf("\n");
    Node *temp = root;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->siblink;
    }
    printf("\n");
}

int is_BST(Node *temp, int min, int max)
{
    if (temp == NULL)
        return 1;
    if (temp->data < min  && temp->data > max)
        return 0;
    return is_BST(temp->rchild, temp->data, max) &&
           is_BST(temp->lchild, min, temp->data);
}

int main()
{
    insert_at_tree();
    insert_at_tree();
    insert_at_tree();
    insert_at_tree();
    insert_at_tree();
    insert_at_tree();
    insert_at_tree();
    inorder(root);
    printf("\n%d\n",is_BST(root,-10000,10000));
    return 0;
}
