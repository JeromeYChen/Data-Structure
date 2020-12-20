#include<iostream>

using namespace std;

typedef int ElementType;

typedef struct node
{
    ElementType data;
    struct node *lp, *rp;
}btnode;

btnode *create();
void traverseLayer(btnode *tp);
ElementType visit(btnode *tp);
void traverseRootFirst(btnode *tp);
void traverseRootSecond(btnode *tp);
void traverseRootFirst2(btnode *tp);
void traverseRootSecond2(btnode *tp);

int main()
{
    btnode *BTree =  create();

    traverseLayer(BTree);
    cout << endl;
    traverseRootFirst(BTree);
    cout << endl;
    traverseRootSecond(BTree);

    system("pause");
    return 0;
}

btnode *create()
{
    btnode *p;
    ElementType e;
    cin >> e;
    if(e == 0)
        p = NULL;
    else
    {
        p = new btnode;
        p->data = e;
        p->lp = create();
        p->rp = create();
    }
    return p;
}

ElementType visit(btnode *tp)
{
    cout << tp->data << ' ';
    return tp->data;
}

void traverseLayer(btnode *tp)
{
    btnode *queue[1024];
    int front = 0, rear = 0;

    if(tp != NULL)
        queue[++rear] = tp;

    while(front != rear)
    {
        front = (front + 1) % 1024;
        tp = queue[front];
        visit(tp);
        if(tp->lp)
        {
            rear = (rear + 1) % 1024;
            queue[rear] = tp->lp;
        }
        if(tp->rp)
        {
            rear = (rear + 1) % 1024;
            queue[rear] = tp->rp;
        }
    }
}

//先根序遍历（递归）
void traverseRootFirst(btnode *tp)
{
    if(tp)
    {
        visit(tp);
        traverseRootFirst(tp->lp);
        traverseRootFirst(tp->rp);
    }
}

//中根序遍历（递归）
void traverseRootSecond(btnode *tp)
{
    if(tp)
    {
        traverseRootSecond(tp->lp);
        visit(tp);
        traverseRootSecond(tp->rp);
    }
}

//先根序遍历（非递归）
void traverseRootFirst2(btnode *tp)
{
    btnode *stack[1024];
    int top = -1;

    while(tp || top != -1)
    {
        while(tp)
        {
            visit(tp);
            stack[++top] = tp->rp;
            tp = tp->lp;
        }
        tp = stack[top--];
    }
}

//中根序遍历（非递归）
void traverseRootSecond2(btnode *tp)
{
    btnode *stack[1024];
    int top = -1;

    stack[++top] = tp;

    while(top != -1)
    {
        while((tp = stack[top]) != NULL)
            stack[++top] = tp->lp;
        top--;
        if(top != -1)
        {
            tp = stack[top--];
            visit(tp);
            stack[++top] = tp->rp;
        }
    }
}
