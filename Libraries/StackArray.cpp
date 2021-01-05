#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define EmptyTOS  -1
#define MaxStackSize  100        //栈的大小

typedef int ElementType;        //define 和 typedef的区别

typedef struct Sqstack
{
    int capacity;       //容量
    int TopofStack;       //栈顶
    ElementType *array;     //ElementType这里我们选用int
}*Stack;

//声明部分
Stack CreateStack( int MaxElements );     //创建栈
void MakeEmpty( Stack S );    //初始化
bool IsEmpty( Stack S );       //判断栈空
bool IsFull( Stack S );       //判断栈满
void Push( ElementType x, Stack S );        //入栈
void DisposeStack( Stack S );      //释放栈
ElementType Top( Stack S );       //看栈顶
ElementType Pop( Stack S );     //出栈

//Calling Function CallTest
int main()
{
    Stack myStack = CreateStack(5);
    MakeEmpty(myStack);

    if(IsEmpty(myStack))
        cout << "myStack is empty" << endl;
    if(!IsFull(myStack))
        cout << "myStack is not full" << endl;

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

    if(IsFull(myStack))
        cout << "myStack is full" << endl;

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
    if( MaxElements > MaxStackSize )
    {
        cout << "Stack size if too small" << endl;
        return NULL;
    }

    Stack S = (Stack)malloc(sizeof(Sqstack));

    S->array = (ElementType*)malloc(sizeof(ElementType) * MaxElements);
    S->capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

/**
 * 使新栈变空
 * 参数：栈的指针
 * 返回值：空
 * 功能：初始化一个新栈
 **/

void MakeEmpty( Stack S )
{
    S->TopofStack = EmptyTOS;
}

/**
 * 参数：栈的指针
 * 返回值：bool类型
 * 功能：判断一个栈是否为空
 **/
bool IsEmpty( Stack S )
{
    return S->TopofStack == EmptyTOS;
}

/**
 * 参数：栈的指针
 * 返回值：bool类型
 * 功能：判断栈是否满
 **/
bool IsFull( Stack S )
{
    return (S->TopofStack == S->capacity - 1);
}

/**
 * 参数：入栈元素， 栈的指针
 * 无返回值
 * 功能：就入栈呗
 **/
void Push( ElementType x, Stack S )
{
    if(IsFull(S))
        cout << "Full Stack" << endl;
    else
    {
        S->array[++S->TopofStack] = x;
    }
}

/**
 * 参数：栈的指针
 * 返回值：无
 * 功能：释放栈
 **/
void DisposeStack( Stack S )
{
    if(S != NULL)
    {
        free(S->array);
        free(S);
    }
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
        return S->array[S->TopofStack];
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
        return S->array[S->TopofStack--];
    }
    
}