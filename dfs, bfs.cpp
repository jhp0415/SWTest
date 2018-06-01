#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> a[1001];
queue<int> q;
bool check[1001];

void dfs(int x)
{
    //깊이 우선 탐색 -> vector(stack), 재귀함수사용
    check[x] = true;
    cout << x << " ";

    for (int i = 0; i < a[x].size(); i++)
    {
        int next = a[x][i];
        if (check[next] == false)
        {
            //재귀함수
            dfs(next);
        }
    }
}

void bfs(int x)             //***** 중요
{
    //너비 우선 탐색 -> Queue
    check[x] = true;
    q.push(x);
    while (!q.empty())      //Queue가 빌때까지 == 모든 정점 탐색완료
    {
        //현재 정점 탐색
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < a[node].size(); i++)
        {
            //다음 정점 q에 추가
            int next = a[node][i];
            if (check[next] == false)
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    //간선 정렬하기
    for (int i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());

    dfs(start);
    cout << endl;
    memset(check, false, sizeof(check));
    bfs(start);
    cout << endl;


}