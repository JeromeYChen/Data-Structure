#include<iostream>
#include<cstdio>

using namespace std;

string solution();

int main()
{
    cout << solution();

    system("pause");
    return 0;
}

string solution()
{
    string s = "", s1;
    char c;
    int n;

    while(cin >> c)
    {
        if(c == '[')
        {
            cin >> n;
            s1 = solution();
            while(n--)
                s+=s1;
        }
        else
            if(c == ']')
                return s;
            else
                s+=c;
    }
    return s;
}