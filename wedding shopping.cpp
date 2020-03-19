#include <bits/stdc++.h>

using namespace std;

int price[21][21];
int reachable[21][201];

int main()
{
    //freopen("input.txt", "r" , stdin);
    int N;
    cin >> N;

    int ans;

    while(N--)
    {
        int M, C;
        cin >> M >> C;

        for(int i=0;i<C;i++)
        {
            cin >> price[i][0];

            for(int j=1;j<=price[i][0];j++)
            {
                cin >> price[i][j];
            }
        }

        memset(reachable, 0, sizeof reachable);

        for(int i=1;i<=price[0][0];i++)
        {
            if(M-price[0][i]>0)
            {
                reachable[0][M-price[0][i]]=1;
            }
        }

        for(int i=1;i<C;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(reachable[i-1][j])
                {
                    for(int k=1;k<=price[i][0];k++)
                    {
                        if(j-price[i][k]>=0)
                        {
                            reachable[i][j-price[i][k]]=1;
                        }
                    }
                }
            }
        }

        int i;
        ans=-1;
        for(i=0;i<=M;i++)
        {
            if(reachable[C-1][i])
            {
                ans=M-i;
                break;
            }
        }

        if(ans==-1)
        {
            cout << "no solution" << endl;
        }

        else
        {
            cout << ans << endl;
        }
    }
}
