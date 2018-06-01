#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n = 3, m = 7;
int a[30];
bool check[30];

void dfs(int cnt)
{
    //조합
    if (cnt == n)
    {
        //출력해보기
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }


    for (int i = cnt; i < m; i++)
    {
        if (check[i] == false)
        {
            a[cnt] = i;
            check[i] = true;

            dfs(cnt + 1);

            check[i] = false;
        }
    }
}


void dfs2(int cnt)
{
    //순열
    if (cnt == n)
    {
        //출력해보기
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }


    for (int i = 0; i < m; i++)
    {
        if (check[i] == false)
        {
            a[cnt] = i;
            check[i] = true;

            dfs(cnt + 1);

            check[i] = false;
        }
    }
}



int main()
{
    //dfs(0);
    dfs2(0);



    return 0;
}