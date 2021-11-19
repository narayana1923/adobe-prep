#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;

} Node;
Node *head;

int read()
{
    int n;
    printf("Enter data: ");
    scanf("%d", &n);
    return n;
}

void insert_at_front()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = read();
    if (head != NULL)
    {
        temp->rlink = head;
        temp->llink = NULL;
        head->llink = temp;
        head = temp;
    }
    else
    {
        temp->llink = NULL;
        temp->rlink = NULL;
        head = temp;
    }
}

void insert_at_end()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = read();
    if (head != NULL)
    {

        Node *cur = head;
        while (cur->rlink != NULL)
        {
            cur = cur->rlink;
        }
        cur->rlink = temp;
        temp->rlink = NULL;
        temp->llink = cur;
    }
    else
    {
        temp->rlink = NULL;
        temp->llink = NULL;
        head = temp;
    }
}

Node *search(int val)
{
    Node *temp = head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->rlink;
    }
    return temp;
}

void insert_after()
{
    int n = read();
    Node *temp = search(n);
    if (temp == NULL)
        printf("Element not found\n");
    else
    {
        Node *cur = (Node *)malloc(sizeof(Node));
        cur->data = read();
        cur->llink = temp;
        cur->rlink = temp->rlink;
        temp->rlink = cur;
        if (cur->rlink != NULL)
        {
            cur->rlink->llink = cur;
        }
    }
}

void insert_before()
{
    int n = read();
    Node *temp = search(n);
    if (temp == NULL)
        printf("Element not found\n");
    else
    {
        Node *cur = (Node *)malloc(sizeof(Node));
        cur->data = read();
        cur->rlink = temp;
        cur->llink = temp->llink;
        temp->llink = cur;
        if (cur->llink != NULL)
        {
            cur->llink->rlink = cur;
        }
        else{
            head = cur;
        }
    }
}

void printDLL()
{
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

int main()
{
    insert_at_end();
    insert_at_front();
    insert_at_end();
    insert_at_front();
    printDLL();
    insert_after();
    insert_before();
    printDLL();
    insert_before();
    insert_at_end();
    printDLL();
    return 0;
}