#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} Node;
 
typedef struct queue{
    struct node* data;
    struct queue* link;
}Queue;

Node* head;

Queue *front, *rear;
void enqueue(Node* data)
{
    Queue *ptr = (Queue *)calloc(1,sizeof(Queue));
    ptr->data = data;
    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
}

Node* dequeue()
{
    if (front == NULL)
    {
        return NULL;
    }
    else
    {
        Queue *prev = front;
        front = front->link;
        return prev->data;
    }
}

int read()
{
    static int i = 1;
    int n;
    printf("Enter data - %d: ", i);
    scanf("%d", &n);
    i++;
    return n;
}

void insert()
{
    Node *temp = (Node *)calloc(1, sizeof(Node));
    temp->data = read();
    if (head != NULL)
    {
        enqueue(head);
        while(front!=NULL){
            Node* cur = dequeue();
            if(cur->lchild!=NULL) enqueue(cur->lchild);
            else{
                cur->lchild = temp;
                break;
            }
            if(cur->rchild !=NULL) enqueue(cur->rchild);
            else{
                cur->rchild = temp;
                break;
            }
        }
    }
    else
    {
        printf("Root node is %d\n", temp->data);
        head = temp;
    }
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;
    printInorder(node->lchild);
    printf("%d ", node->data);
    printInorder(node->rchild);
}

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    printInorder(head);
    return 0;
}