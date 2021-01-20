#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct node
{
    int floor;
    int layer;
};
queue<node> path;
bool record[210] = {false, };

int bfs();

int main()
{
    cout << bfs();

    system("pause");
    return 0;
}

int bfs()
{
    int N, A, B;
    cin >> N >> A >> B;

    int arr[210];
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    //initialize
    node now;
    now.floor = A;
    now.layer = 0;
    record[A] = true;
    path.push(now);

    while(!path.empty())
    {
        //search
        now = path.front();
        path.pop();
        if(now.floor == B)
                return now.layer;
        int dist = arr[now.floor];
        node next;
        next.floor = now.floor + dist;
        if(next.floor <= N && !record[next.floor])
        {
            next.layer = now.layer + 1;
            if(!record[next.floor])
            {
                path.push(next);
                record[next.floor] = true;
            }
        }
        next.floor = now.floor - dist;
        if(next.floor > 0 && !record[next.floor])
        {
            next.layer = now.layer + 1;
            if(!record[next.floor])
            {
                path.push(next);
                record[next.floor] = true;
            }
        }
        
    }
    return -1;
}  