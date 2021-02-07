#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vvi vector<vi>
#define MOD 1000000007

void printGrid(vvi mat, string type)
{
    cout << type << ": \n";
    for (auto ele : mat)
    {
        for (auto every : ele)
        {
            cout << every << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vvi dis(n, vi(n, 0));
    vvi path(n, vi(n, 0));
    vvi mat(n, vi(n, 0));

    int i;
    REP(i, 0, n)
    {
        int j;
        REP(j, 0, n)
        {
            char ele;
            cin >> ele;
            mat[i][j] = ele - '0';
        }
    }

    i = 0;
    int j = 0;
    dis[i][j] = mat[i][j];
    path[i][j] = 1;
    i = 1;
    while (i < n)
    {
        dis[0][i] = dis[0][i - 1] + mat[0][i];
        dis[0][i] %= MOD;
        path[0][i] = 1;
        path[0][i] %= MOD;

        dis[i][0] = dis[i - 1][0] + mat[i][0];
        dis[i][0] %= MOD;
        path[i][0] = 1;
        path[i][0] %= MOD;

        i++;
    }

    REP(i, 1, n)
    {
        int j;
        REP(j, 1, n)
        {

            if (dis[i - 1][j] == dis[i][j - 1])
            {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
                path[i][j] %= MOD;
                dis[i][j] = (dis[i - 1][j] + mat[i][j]) % MOD;
            }
            else if (dis[i - 1][j] > dis[i][j - 1])
            {
                path[i][j] = path[i - 1][j] % MOD;
                dis[i][j] = (dis[i - 1][j] + mat[i][j]) % MOD;
            }
            else
            {
                path[i][j] = path[i][j - 1] % MOD;
                dis[i][j] = (dis[i][j - 1] + mat[i][j]) % MOD;
            }
        }
    }

    // printGrid(mat,"MAt");
    // printGrid(dis,"Dis");
    // printGrid(path,"Path");

    cout << dis.back().back() << " " << path.back().back();

    return 0;
}

/*
5
0 1 0 1 0
0 0 0 0 0
1 0 0 1 0
1 0 0 1 0
1 1 0 0 0

5
01010
00000
10010
10010
11000
*/