#include <iostream>

using namespace std;

struct Segment{
    int power, id;
};
//一般线段树开四倍大防爆
Segment a[150], tree[600];

void Build_tree(int node, int start, int end);

//选出两者能力值大的那个
Segment maxn(Segment a, Segment b){
    return a.power > b.power ? a : b;
}
//在一二名中选出第二名
Segment minn(Segment a, Segment b){
    return a.power < b.power ? a : b;
}

int main()
{  
    int n;

    cin >> n;

    // 1 << n 就是2的n次方，比pow更快
    for(int i = 1; i <= (1 << n); i++){
        cin >> a[i].power;
        a[i].id = i;
    }

    Build_tree(1, 1, (1 << n));

    cout << minn(tree[2], tree[3]).id;

    system("pause");

    return 0;
}

void Build_tree(int node, int start, int end)
{
    //叶节点返回
    if(start == end){
        tree[node] = a[start];
        return;        
    }

    int lnode = node * 2;
    int rnode = node * 2 + 1;
    int mid = (end + start) / 2;

    Build_tree(lnode, start, mid);
    Build_tree(rnode, mid + 1, end);
    tree[node] = maxn(tree[lnode], tree[rnode]);
}