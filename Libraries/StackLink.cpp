#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef int ElementType;

typedef struct Linkstack
{
    ElementType Element;
    Linkstack* next;
}*Stack;

//声明部分
Stack CreateStack( int MaxElements );     //创建栈
bool IsEmpty( Stack S );       //判断栈空
void Push( ElementType x, Stack S );        //入栈
void DisposeStack( Stack S );      //释放栈
ElementType Top( Stack S );       //看栈顶
ElementType Pop( Stack S );     //出栈

//Calling Function CallTest
int main()
{
    Stack myStack = CreateStack(5);

    if(IsEmpty(myStack))
        cout << "myStack is empty" << endl;

    Push(2, myStack);
    Push(43, myStack);
    Push(23, myStack);

    cout << Top(myStack) << endl;
    cout << Pop(myStack) << endl;
    cout << Top(myStack) << endl;

    if(!IsEmpty(myStack))
        cout << "myStack is not empty" << endl;

    Push(2, myStack);
    Push(2, myStack);
    Push(2, myStack);


    DisposeStack(myStack);

    system("pause");

    return 0;
}

/**
 * 创建栈
 * 参数：int
 * 返回值：Stack 栈的指针
 * 功能：创建一个新栈，并且返回指向新栈的指针
 */
Stack CreateStack( int MaxElements )
{
    Stack S = (Stack)malloc(sizeof(Linkstack));

    S->next = NULL;     //初始化

    return S;
}

/**
 * 参数：栈的指针
 * 返回值：bool类型
 * 功能：判断一个栈是否为空
 **/
bool IsEmpty( Stack S )
{
    return S->next == NULL;
}

/**
 * 参数：入栈元素， 栈的指针
 * 无返回值
 * 功能：就入栈呗
 **/
void Push( ElementType x, Stack S )
{
    Stack temp = (Stack)malloc(sizeof(Linkstack));

    temp->Element = x;
    temp->next = S->next;
    S->next = temp;
}

/**
 * 参数：栈的指针
 * 返回值：无
 * 功能：释放栈
 **/
void DisposeStack( Stack S )
{
    while(S->next != NULL)
    {
        Stack temp = (Stack)malloc(sizeof(Linkstack));
        temp->next = S->next;
        S->next = S->next->next;
        free(temp->next);
        free(temp);
    }
    free(S);
}

/**
 * 参数：栈的指针
 * 返回值：栈顶元素
 * 功能：读取栈顶元素但不出栈
 **/
ElementType Top( Stack S )
{
    if(IsEmpty(S))
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        return S->next->Element;
    }
    
}

/**
 * 参数：栈的指针
 * 返回值：栈顶元素
 * 功能：返回栈顶元素并且出栈
 **/
ElementType Pop( Stack S )
{
    if(IsEmpty(S))
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        ElementType num = S->next->Element;
        Stack temp = (Stack)malloc(sizeof(Linkstack));
        temp->next = S->next;
        S->next = S->next->next;
        free(temp->next);
        free(temp);

        return num;
    }
    
}