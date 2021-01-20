#include<iostream>

#define maxn 51

using namespace std;

int n,m;
int ans = 0;
int worklist[maxn * maxn];
int worknumber[maxn][maxn];
int worktime[maxn][maxn];
int cnt_now_work_step[maxn];
int lasttime[maxn];
bool timeline[maxn * maxn][maxn * maxn];

bool check_in_line(int begin_time_point,int end_time_length,int workid){
    for (int time = begin_time_point; time <= end_time_length;time++)
        if (timeline[workid][time])
            return false;
    return true;    
}

int main(){
    cin >> m >> n;
    for (int i=1;i<=n*m;i++)
        cin >> worklist[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> worknumber[i][j];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> worktime[i][j];

    for (int i=1;i<=n*m;i++){
        int nowitem = worklist[i];
        cnt_now_work_step[nowitem]++;//工序数
        int nownumber = worknumber[nowitem][cnt_now_work_step[nowitem]];
        int costtime = worktime[nowitem][cnt_now_work_step[nowitem]];
        
        for (int time = lasttime[nowitem]+1;;time++)//扫描时间轴
            if (check_in_line(time,time+costtime-1,nownumber)){
                for (int marktime = time;marktime <= time+costtime-1;marktime++)
                    timeline[nownumber][marktime] = true;
                lasttime[nowitem] = time + costtime - 1;
                break;
            }
    }

    for (int i=1;i<=n;i++)
        ans = max(ans,lasttime[i]);

    cout << ans << endl;

    system("pause");
    return 0;
}