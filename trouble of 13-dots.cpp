#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        int p[n], f[n];
        int prevprice=0;

        for(int i=1;i<=n;i++)
        {
            cin >> p[i] >> f[i];
        }

        prevprice=m;
        if(m>1800)
        {
            m=m+200;
        }
        int knapsack[m+1]={0};

        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=p[i];j--)
            {
                if(knapsack[j-p[i]]>0 || j==p[i])
                {
                    knapsack[j]=max(knapsack[j], knapsack[j-p[i]]+f[i]);
                    //cout << knapsack[j] << " " << j << endl;
                }
            }
            //cout << "\n";
        }

        if(prevprice>1800 && prevprice<=2000)
        {
            for(int i=0;i<=prevprice;i++)
            {
                //cout << knapsack[i] << endl;
                if(knapsack[i]>ans)
                {
                    ans=knapsack[i];
                    //cout << knapsack[i] << " " << i << endl;
                }
            }

            for(int i=2001;i<=m;i++)
            {
                if(knapsack[i]>ans)
                {
                    ans=knapsack[i];
                    //cout << knapsack[i] << " " << i << endl;
                }
            }
        }

        else
        {
            for(int i=0;i<=m;i++)
            {
                if(knapsack[i]>ans)
                {
                    ans=knapsack[i];
                }
            }
        }
        cout << ans << endl;

    }

}
