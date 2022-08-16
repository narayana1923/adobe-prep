#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *head;

int read()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    return n;
}

void insert_at_beginning()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = read();
    if (head != NULL)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        head = temp;
        head->link = NULL;
    }
}

void insert_at_ending()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = read();

    if (head == NULL)
    {
        head = temp;
        head->link = NULL;
    }
    else
    {
        Node *prev = head;
        while (prev->link != NULL)
            prev = prev->link;
        prev->link = temp;
        temp->link = NULL;
    }
}

Node *searchAfter(int val)
{
    Node *temp = head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->link;
    }

    return temp;
}

Node *searchBefore(int val)
{
    if (head->data == val)
        return head;
    Node *temp = head;
    while (temp->link != NULL && temp->link->data != val)
        temp = temp->link;
    return temp;
}

void insertBefore()
{
    int n = read();
    Node *temp = searchBefore(n);
    if (temp == NULL)
    {

        printf("Element not found\n");
        return;
    }
    Node *cur = (Node *)malloc(sizeof(Node));
    cur->data = read();
    if (head->data == n)
    {
        cur->link = head;
        head = cur;
    }
    else
    {
        cur->link = temp->link;
        temp->link = cur;
    }
}

void insertAfter()
{
    int n = read();
    Node *temp = searchAfter(n);
    if (temp == NULL)
        printf("Element not found\n");
    else
    {
        Node *cur = (Node *)malloc(sizeof(Node));
        cur->data = read();
        cur->link = temp->link;
        temp->link = cur;
    }
}

void reverse()
{
    Node *temp = head, *next = NULL, *prev = NULL;
    while (temp != NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

int getLength(Node* temp){
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->link;
    }
    return n;
}

int palindrome(Node *given)
{
    Node *temp = given;
    int n = getLength(given);
    for (int i = 0; i < n / 2; i++)
    {
        // palindrome know
        temp = temp->link;
    }

    Node *temp2 = temp, *prev = NULL, *next = NULL, *cur = temp2;
    //from middle to end we are reversing
    while(temp2 != NULL)
    {
        next = temp2->link;
        temp2->link = prev;
        prev = temp2;
        temp2 = next;
    }
    temp = given;
    temp2 = prev;
    while(temp != cur)// when it reaches middle we terminate
    {
        if(temp->data != temp2->data)
        {
            return 0;//auto type cast even if it is zero
        }
        temp = temp->link;
        temp2 = temp2->link;
    }
    return 1;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void get_index()
{
    int n = read();
    Node *temp = head;
    for (int i = 0; i < n && temp != NULL; i++)
    {
        temp = temp->link;
    }
    if (temp == NULL)
    {
        printf("index out of range");
    }
    else
    {
        printf("%d\n", temp->data);
    }
}
void last_index()
{
    int n = read();
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    if (count < n)
    {
        printf("index out of range");
    }
    else
    {
        temp = head;
        for (int i = 0; i < (count - (n + 1)) && temp->link != NULL; i++)
        {
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapPair()
{
    Node *temp = head;
    while (temp != NULL && temp->link != NULL)
    {
        swap(&temp->data, &temp->link->data);
        temp = temp->link->link;
    }
}

int main()
{
    insert_at_ending();
    insert_at_ending();
    insert_at_ending();
    insert_at_ending();
    insert_at_ending();
    insert_at_ending();
    insert_at_ending();
    insert_at_ending();
    printList();
    printf("%d",palindrome(head));
    return 0;
}