#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        int m;
        cin >> m;

        int coins[m+1];

        int sum=0;
        for(int i=1;i<=m;i++)
        {
            cin >> coins[i];
            sum+=coins[i];
        }

        int dp[sum+1]={0};
        dp[0]=0;
        int ans=1000000;

        for(int i=1;i<=m;i++)
        {
            for(int j=sum;j>=coins[i];j--)
            {
                if(dp[j-coins[i]]>0 || j==coins[i])
                {
                    dp[j]=max(dp[j], dp[j-coins[i]]+coins[i]);
                }
            }
        }

        for(int i=0;i<=sum;i++)
        {
            //cout << dp[i] << " ";
            ans=min(abs((sum-dp[i])-dp[i]), ans);
        }
        //cout << "\n";
        cout << ans << endl;
    }
}
