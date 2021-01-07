/*
The prperty of that makes a binary tree into a binary search tree is
that for every node, X, in the tree, the values of all the keys in its
left subtree are smaller than the key value in X, and the values of all the keys
in its right subtree are larger than the key value in X.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int ElementType;

typedef struct TreeNode *SearchTree;
struct TreeNode
{
    ElementType data;
    SearchTree left;
    SearchTree right;
};
typedef struct TreeNode *Position;

//Test
SearchTree Create();
ElementType visit(SearchTree T);
void PreOrder(SearchTree T);
//Function
SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
ElementType Retrieve(Position P);

int main()
{
    SearchTree ST = Create();
    
    //cout <<Retrieve(Find(2, ST)) << endl;
    //Delete(2, ST);
    //Insert(2, ST);

    PreOrder(ST);
    MakeEmpty(ST);

    system("pause");
    return 0;
}

//Test: 6 2 1 0 0 4 3 0 0 0 8 0 0 
SearchTree Create()
{
    SearchTree T;
    ElementType e;

    //Input
    cin >> e;
    
    if(e == 0)
        T = NULL;
    else
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        T->data = e;
        T->left = Create();
        T->right = Create();
    }
    
    return T;
}

ElementType visit(SearchTree T)
{   
    cout << T->data << ' ';

    return T->data;
}

void PreOrder(SearchTree T)
{
    if(T)
    {
        visit(T);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}


SearchTree MakeEmpty( SearchTree T )
{
    if(T != NULL)
    {
        //To free node definitely recur by post-order
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
}

Position Find( ElementType X, SearchTree T )
{
    if(T == NULL)
        return NULL;
    
    if(X < T->data)
        Find( X, T->left);
    else if(X > T->data)
        Find( X, T->right );
    else
        return T;
}

ElementType Retrieve(Position P)
{
    return P->data;
}

Position FindMin( SearchTree T )
{
    if(T == NULL)
        return NULL;
    
    if(T->left == NULL)
        return T;
    else
        FindMin(T->left);
}

//You can't insert a node as root(out of table)
SearchTree Insert( ElementType X, SearchTree T )
{
    if(T == NULL)
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if(T == NULL)
        {
            cout << "Out of space!" << endl;
            return NULL;
        }
        else
        {
            T->data = X;
            T->left = NULL;
            T->right = NULL;
        }
    }
    else if(X < T->data)
        T->left = Insert(X, T->left);
    else if(X > T->data)
        T->right = Insert(X, T->right);
    //else X == T->data we will do nothing
    
    return T;
}

SearchTree Delete( ElementType X, SearchTree T )
{
    Position TmpCell;

    if(T == NULL)   //Error
        cout << "Error" << endl;
    else if(X < T->data)
        T->left = Delete(X, T->left);
    else if(X > T->data)
        T->right = Delete(X, T->right);
    //Find the element
    else if(T->left && T->right)    //two child
    {
        //Replace with the smallest element in the right tree
        TmpCell = FindMin(T->right);
        T->data = TmpCell->data;
        T->right = Delete(T->data, T->right);
    }
    else    //zero or one child
    {
        TmpCell = T;
        if(T->left == NULL)
            T = T->right;
        else
            T = T->left;
        free(TmpCell);
    }

    //After retursion, T always a complete tree
    return T;
}
