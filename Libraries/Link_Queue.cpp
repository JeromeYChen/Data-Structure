#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef int ElementType;

//整体使用引用来进行修改操作
typedef struct Node
{
    ElementType Data;
    struct Node *next;
}*QueuePtr;

typedef struct LinkQueue
{
    QueuePtr rear;
    QueuePtr front;
}Queue;

void Initiate(Queue &Q);
bool IsEmpty(Queue Q);
void Enqueue(ElementType X, Queue &Q);
bool DequeueAndFront(Queue &Q, ElementType &e);
void DestoryQueue(Queue &Q);

int main()
{
    Queue newQ;

    Initiate(newQ);

    if(IsEmpty(newQ))
        cout << "Is empty" << endl;

    for(int i = 4; i < 23; i++)
        Enqueue(i, newQ);
    
    for(int i = 0; i < 9; i++)
    {
        int num = 0;
        DequeueAndFront(newQ, num);
        cout << num << endl;
    }

    DestoryQueue(newQ);

    system("pause");
    return 0;
}

void Initiate(Queue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(Node));
    Q.front->next = NULL;
}

bool IsEmpty(Queue Q)
{
    return Q.front->next == NULL;
}

void Enqueue(ElementType X, Queue &Q)
{
    QueuePtr tmp = (QueuePtr)malloc(sizeof(Node));
    tmp->Data = X;
    tmp->next = NULL;
    Q.rear->next = tmp;
    Q.rear = tmp;
    if(IsEmpty(Q))
        Q.front->next = tmp;
}

bool DequeueAndFront(Queue &Q, ElementType &e)
{
    if(IsEmpty(Q))
        return false;

    QueuePtr tmp = (QueuePtr)malloc(sizeof(Node));
    tmp = Q.front->next;
    e = Q.front->next->Data;
    Q.front->next = tmp->next;
    if(Q.rear == tmp)
        Q.rear = Q.front;
    free(tmp);
    return true;
}

void DestoryQueue(Queue &Q)
{
    while(Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}