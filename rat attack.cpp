#include <bits/stdc++.h>

using namespace std;

int killed[1025][1025]={0};

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while(t--)
    {
        memset(killed, 0, sizeof killed);
        int d, n;
        cin >> d;
        cin >> n;

        int ans=0, ans_x, ans_y;

        int x[n], y[n], s[n];

        for(int i=0;i<n;i++)
        {
            cin >> x[i] >> y[i] >> s[i];
        }


        for(int iter=0;iter<n;iter++)
        {
            for(int i=x[iter]-d;i<=x[iter]+d;i++)
            {
                for(int j=y[iter]-d;j<=y[iter]+d;j++)
                {
                    if(i<=1024 && j<=1024 && i>=0 && j>=0)
                    killed[i][j]=killed[i][j]+s[iter];
                }
            }
        }

        for(int i=0;i<=1024;i++)
        {
            for(int j=0;j<=1024;j++)
            {
                if(killed[i][j]>ans)
                {
                    ans=killed[i][j];
                    ans_x=i;
                    ans_y=j;
                }
            }
        }
        cout << ans_x << " " << ans_y << " " << ans << endl;
    }
}
