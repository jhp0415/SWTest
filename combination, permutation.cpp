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

void combination(int cnt)
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

            combination(cnt + 1);

            check[i] = false;
        }
    }
}


void permutation(int cnt)
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

            permutation(cnt + 1);

            check[i] = false;
        }
    }
}



int main()
{
    combination(0);
    permutation(0);



    return 0;
}