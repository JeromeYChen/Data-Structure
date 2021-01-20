#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int main()
{
    stack<int> s;

    char op;
    int now = 0;

    while((op = getchar()) != '@')
    {
        if(op >= '0' && op <= '9')
            now = now * 10 + op - '0';
        else if(op == '.')
        {
            s.push(now);
            now = 0;
        }
        else if(op == '+')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b + a);
        }
        else if(op == '-')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b - a);
        }
        else if(op == '*')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b * a);
        }
        else if(op == '/')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b / a);
        }
    }

    cout << s.top();


    return 0;
}