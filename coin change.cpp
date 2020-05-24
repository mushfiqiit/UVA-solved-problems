#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v;

    while(cin >> v)
    {
        int a[]={1, 5, 10, 25, 50};
        int n=5;
        int dp[v+1];
        memset(dp, 0, sizeof dp);
        dp[0]=1;
        int maxi=0;
        for(int j=0;j<n;j++)
        {
            //maxi=0;
            for(int i=0;i<=v;i++)
            {
                if(a[j]<=i)
                {
                    dp[i]+=dp[i-a[j]];
                }
            }
        }
        cout << dp[v] << endl;
    }
}
