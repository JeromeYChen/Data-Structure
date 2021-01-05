#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef int ElementType;

typedef struct Circular
{
    int Capacity;       //队列容量
    int Front;          //队首
    int Rear;           //队尾
    ElementType *Array;
}*Queue;

Queue CreateQueue(int MaxElements);
bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
int Length(Queue Q);
bool Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
bool FrontAndDequeue(Queue Q, ElementType &E);


int main()
{
    Queue newQ = CreateQueue(5);
    if(IsEmpty)
        cout << "Is empty" << endl;

    for(int i = 0; i < 5; i++)
        if(!Enqueue(i, newQ))
            cout << "IsFull" << endl;
    
    for(int i = 0; i < 5; i++)
    {
        int num = 0;
        FrontAndDequeue(newQ, num);
        cout << num << endl;
    }
    
    cout << endl;

    for(int i = 4; i < 9; i++)
        Enqueue(i, newQ);
    
    for(int i = 0; i < 5; i++)
    {
        int num = 0;
        FrontAndDequeue(newQ, num);
        cout << num << endl;
    }

    if(!IsFull(newQ))
            cout << "IsFull" << endl;


    system("pause");
    return 0;
}
Queue CreateQueue(int MaxElements)
{
    Queue Q = (Queue)malloc(sizeof(Queue));

    Q->Capacity = MaxElements + 1;      //这里留意一下，为什么要加1，如果不加1会咋样（关于判表空以及表满操作）
    Q->Front = Q->Rear = 0;
    Q->Array = new ElementType[MaxElements];

    return Q;
}

bool IsEmpty(Queue Q)
{
    if(Q->Front == Q->Rear)
        return true;
    return false;
}

bool IsFull(Queue Q)
{
    if((Q->Rear + 1) % Q->Capacity == Q->Front)
        return true;
    return false;
}

int Length(Queue Q)
{
    return (Q->Rear - Q->Front + Q->Capacity) % Q->Capacity;
}

bool Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q))
        return false;
    Q->Array[Q->Rear] = X;
    Q->Rear = (Q->Rear + 1) % Q->Capacity;
    return true;
}

ElementType Front(Queue Q)
{
    if(!IsEmpty(Q))
        return Q->Array[Q->Front];
    return -1;
}

/*
这里有个很有意思的事，这种队列的front直接指向队首，而rear指向队尾的后一格
故这里必须用引用来返回队首值，来完成取队首且出列操作
如果是front指向队首前一格，而rear直接指向队尾
那这里就可以直接使用return来完成操作

ElementType FrontAndDequeue(Queue Q)
{
    if(IsEmpty(Q))
        return NULL;
    
    Q->Front = (Q->Front + 1) % Q->Capacity;
    return Q->Array[Q->Front];
}

其他一些操作也同样需要修改，说实话我是建议这种
front指向队首前一格，而rear直接指向队尾
但我现在懒得改了，道理自己想想就很好修改了
*/
bool FrontAndDequeue(Queue Q, ElementType &E)
{
    if(IsEmpty(Q))
        return false;
    
    E = Q->Array[Q->Front];
    Q->Front = (Q->Front + 1) % Q->Capacity;

    return true;
}