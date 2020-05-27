#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    double v;

    while(cin >> v, v!=0.0)
    {
        long long int a[]={5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

        long long int value=(v*100.00)+1e-6;

        long long int dp[value+1];
        memset(dp, 0, sizeof dp);
        dp[0]=1;

        //cout << value << endl;
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<=value;j++)
            {
                if(a[i]<=j)
                {
                    dp[j]+=dp[j-a[i]];

                    /*if(dp[j]>0)
                    {
                        cout << i << " " << j << endl;
                    }*/
                }
            }
            //cout << dp[value] << endl;
        }
        printf("%6.2f%17lld\n", v, dp[value]);
    }
}
