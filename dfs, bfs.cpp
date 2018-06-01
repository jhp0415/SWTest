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
    //���� �켱 Ž�� -> vector(stack), ����Լ����
    check[x] = true;
    cout << x << " ";

    for (int i = 0; i < a[x].size(); i++)
    {
        int next = a[x][i];
        if (check[next] == false)
        {
            //����Լ�
            dfs(next);
        }
    }
}

void bfs(int x)             //***** �߿�
{
    //�ʺ� �켱 Ž�� -> Queue
    check[x] = true;
    q.push(x);
    while (!q.empty())      //Queue�� �������� == ��� ���� Ž���Ϸ�
    {
        //���� ���� Ž��
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < a[node].size(); i++)
        {
            //���� ���� q�� �߰�
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

    //���� �����ϱ�
    for (int i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());

    dfs(start);
    cout << endl;
    memset(check, false, sizeof(check));
    bfs(start);
    cout << endl;


}