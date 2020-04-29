#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int N, x, T, k;

    while(cin >> N >> x >> T >> k)
    {
        if(N==0 && x==0 && T==0 && k==0)
        {
            break;
        }
        N++;
        int m=floor((double)(N*x)/1.1+1e-6)-N*T;

        int price[2*k+1];
        int favor[2*k+1];
        //cout << "Gotcha" << endl;
        vector<vector<vector<int> > > dp(2*k+1,vector<vector<int> >(m+1,vector<int>(2*N+1,-0)));
        //cout << "HEre" << endl;
        memset(favor, 0, sizeof favor);
        //memset(dp, 0, sizeof dp);

        for(int i=1;i<=k;i++)
        {
            cin >> price[i];
            price[i+k]=price[i];

            for(int j=0;j<N;j++)
            {
                int temp;
                cin >> temp;
                favor[i]=favor[i]+temp;
            }
            favor[i+k]=favor[i];
        }
        //cout << m << endl;

        for(int i=1;i<=2*k;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int l=0;l<=2*N;l++)
                {
                    dp[i][j][l]=dp[i-1][j][l];
                    if(price[i]<=j && l)
                    {
                        dp[i][j][l]=max(dp[i-1][j][l], favor[i]+dp[i-1][j-price[i]][l-1]);
                    }
                    //cout << dp[i][j][l] << " " << i << " " << j << " " << l << endl;
                }
            }
        }
        double ans;
        //cout << dp[2*k][m][2*N] << endl;
        ans=(double)dp[2*k][m][2*N]/(double)(N);
        printf("%0.2lf\n", ans);
    }
}
