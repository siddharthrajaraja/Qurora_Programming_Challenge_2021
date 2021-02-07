#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define vi vector<char>
#define vvi vector<vi>

void printGrid(vvi grid)
{
    cout << "Grid :\n";
    for (auto ele : grid)
    {
        for (auto every : ele)
        {
            cout << every << " ";
        }
        cout << endl;
    }
}

bool isValid(int x, int y)
{
    return x >= 0 && x < 6 && y >= 0 && y < 7;
}

bool check(vvi grid, int x, int y, char turn)
{

    vector<vector<int>> moves = {
        {0, -1}, // R and L
        {0, 1},

        {-1, 0}, // T and B
        {1, 0},

        {1, 1}, // Ist dia
        {-1, -1},

        {1, -1}, // IInd dia
        {-1, 1}};

    vector<int> arr;

    for (auto ele : moves)
    {
        int innerX = x;
        int innerY = y;
        int count = 0;
        while (isValid(innerX + ele[0], innerY + ele[1]) && grid[innerX + ele[0]][innerY + ele[1]] == turn)
        {
            innerX += ele[0];
            innerY += ele[1];
            count++;
        }

        arr.push_back(count);
    }

    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] + arr[i + 1] + 1 >= 4)
        {
            return true;
        }
        i += 2;
    }

    return false;
}

int main()
{

    vvi grid(6, vi(7, '-'));
    vi rowIndex(7, 5);

    int i = 0;
    bool flag = false;

    while (i < 42)
    {
        int ele;
        cin >> ele;
        ele--;
        char turn;

        if (i % 2 == 0)
        {
            turn = 'R';
        }
        else
        {
            turn = 'Y';
        }

        int row = rowIndex[ele];
        rowIndex[ele]--;

        grid[row][ele] = turn;

        //sleep(3);

        if (check(grid, row, ele, turn))
        {
            string ans;
            if (turn == 'R')
                ans = "RED";
            else
                ans = "YELLOW";
            cout << ans << " " << i + 1 << endl;
            flag = true;
            break;
        }

        i++;

        //printGrid(grid);
    }

    if (!flag)
    {
        cout << "DRAW";
    }

    return 0;
}

/*

1
1
2
2
3
3
4
4
1
1
1
1
2
2
2
2
3
3
3
3
4
4
4
4
5
5
5
5
5
5
6
6
6
6
6
6
7
7
7
7
7
7

*/