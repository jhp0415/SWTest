#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int t, n, m;
long long ans = 0;
long long d[30][30];

int combination(int n, int r)
{
    //값이 이미 있으면
    if (d[n][r] > 0)
        return d[n][r];

    if (n == r || r == 0) return 1;

    return d[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{

    cin >> n >> m;

    ans = combination(m, n);

    cout << ans << endl;
 

    return 0;
}