#include <bits/stdc++.h>

using namespace std;

int board[8][8];
int maxscore=0;
int row[8];

bool place(int r, int c)
{
    for(int prev=0;prev<c;prev++)
    {
        if(row[prev]==r || abs(row[prev]-r)==abs(prev-c))
        {
            return false;
        }
    }
    return true;
}

void backtrack(int c, int tempscore)
{
    if(c==8)
    {
        maxscore=max(tempscore, maxscore);
    }

    for(int r=0;r<8;r++)
    {
        if(place(r, c))
        {
            row[c]=r;
            backtrack(c+1, tempscore+board[r][c]);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin >> k;

    while(k--)
    {
        maxscore=0;
        memset(row, 0, sizeof row);
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cin >> board[i][j];
            }
        }
        backtrack(0 ,0);
        printf("%5d\n", maxscore);
    }
}
