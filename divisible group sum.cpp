#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    int setcount=1;

    while(cin >> N >> Q, N!=0 || Q!=0)
    {
        int D, M;

        int item[N+1];
        for(int i=1;i<=N;i++)
        {
            cin >> item[i];
        }


        cout << "SET " << setcount << ":\n";
        setcount++;
        int query=0;
        for(int query=0;query<Q;query++)
        {
        cin >> D >> M;
        int dp[N+1][M+1][D+1];

        memset(dp, 0, sizeof dp);
        dp[0][0][0]=1;
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=M;j++)
            {
                for(int k=0;k<D;k++)
                {
                    int temp=(k+item[i])%D;
                    if(temp<0)
                    {
                        temp=temp+D;
                    }

                    dp[i][j][k]=dp[i][j][k]+dp[i-1][j][k];
                    if(j)
                    {
                        dp[i][j][k]+=dp[i-1][j-1][temp];
                    }
                }
            }
        }
        cout << "QUERY " << query+1 << ": " << dp[N][M][0] << endl;
        }

    }
}
