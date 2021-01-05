#include <iostream>
#include <cstdio>

using namespace std;

//定义一个叫做LinkedList的结构布局
typedef struct Node
{
    int data;
    struct Node *next;
}LinkedList;

/*
接下来都是具有头结点的单链表操作
单链表：list，list既是单链表的名字，也是其头结点
注意这里是头结点，并非头指针形式
*/

//初始化单链表,即建立一个新的空表
//调用函数，无需参数，返回头结点
LinkedList *Initiate ()
{
    //内存申请失败极小可能性发生，故在此不判断
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));     //创建一个头节点
    //初始化头结点，链表为空
    list->data = 0;
    list->next = NULL;
    //返回头结点
    return list;
}

//创建储存链表的结点，将元素添加至指向的链表末尾
//调用函数，参数为元素及相应链表的头结点即链表名，返回是否成功
bool AddItem(int element, LinkedList* List)
{
    LinkedList *pnew;       //新的结点
    LinkedList *scan = List;        //扫描指针

    //申请空间
    pnew = (LinkedList*) malloc(sizeof(LinkedList));
    //建立结点
    pnew->data = element;
    pnew->next = NULL;

    if(scan->next == NULL)        //空链表，把结点放在链表开头
        List->next = pnew;
    else
    {
        while(scan->next != NULL)   //寻找链表末尾
            scan = scan->next;
        scan->next = pnew;      //向末尾接入结点
    }
    
    return true;
}

//按顺序显示整条链表操作
//调用函数，参数为链表名，返回为空
void DisplayAll(LinkedList* List)
{
    //注意，头结点只是个头结点，真正的链表要从头结点指向的结点开始
    LinkedList* scan = List->next;
    while(scan->next != NULL)
    {
        cout << scan->data << " ";
        scan = scan->next;
    }
    //最后一个结点也要输出才完整
    cout << scan->data << endl;
}

//求表长
//调用函数，参数为链表名，返回值为整数
int Length(LinkedList* List )
{
    LinkedList *scan;        //当前指针
    scan = List -> next;       //从表头开始，不算头节点
    int count = 0;      //计数器
    while( scan != NULL)
    {
        count++;
        scan = scan -> next;
    }
    return count;
}

//获取第i个结点元素操作,
//调用函数，给出要第几个以及相应链表
int GetINode(int i, LinkedList* List)
{
    LinkedList* scan = List->next;
    int j = 1;
    while( (scan != NULL) && (j < i) )
    {
        scan = scan->next;
        j++;
    }
    return scan->data;
}

//定位操作：找到链表中e出现的位置
//调用函数，给出寻找的元素e以及链表名，返回位置，没找到就返回-1
int LocatedE(int e, LinkedList* List)
{
    int index = 1;
    LinkedList *scan = List->next;

    while((scan != NULL) && (scan->data != e))
    {
        scan = scan -> next;
        index++;
    }
    //没找到返回-1
    if(scan == NULL)    return -1;

    return index;
}

//插入结点操作,比如插入1，那就是第一个结点放置新结点，原链表第一个结点变成第二个
//给出插入的元素，以及插入的位置，以及插入的链表名，返回插入是否成功
bool Insert(int element, int i, LinkedList* List)
{
    LinkedList *pnew;       //新的结点
    LinkedList *scan = List;        //扫描指针，注意细节，从头节点开始
    int index = 1;          //位置

    //插入的位置在1~Length之间,否者插入失败
    if(i > Length(List) || i < 1)    return false;

    //扫描为指定位置
    while(index < i && scan != NULL)
    {
        scan = scan->next;
        index++;
    }

    //申请空间
    pnew = (LinkedList*) malloc(sizeof(LinkedList));
    //建立结点
    pnew->data = element;
    pnew->next = scan->next;
    scan->next = pnew;

    return true;
}

//删除元素为e的所有结点
void DelElem(LinkedList* List, int ele)
{
    LinkedList* scan = List;
    LinkedList* del = NULL;

    while(scan->next != NULL)
    {
        if(scan->next->data == ele)
        {
            del = scan->next;
            scan->next = scan->next->next;
            free(del);
        }
        else
            scan = scan->next;
    }
}

 
int main()
{
    //声明一个叫mylist的链表
    LinkedList* mylist = Initiate();

    //将5 4 3 2 1存入相对应的链表中
    for(int i = 5; i > 0; i--)
        AddItem(i, mylist);

    //将链表全部显示出来看看
    DisplayAll(mylist);

    //输出表长（不包括头结点，这里表长为5）
    cout << Length(mylist) << endl;

    //看看第二个元素是什么
    cout << GetINode(2, mylist) << endl;

    //找找2在序列中的位置
    cout << LocatedE(2, mylist) << endl;

    //将8插入位置1，然后显示链表
    if(Insert(8, 1, mylist))
         DisplayAll(mylist);
    else
        cout << "ERROR" << endl;
    
    //删除5，然后显示链表
    DelElem(mylist, 5);
    DisplayAll(mylist);


    system("pause");

    return 0;
}