#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int cars[n];

        for(int i=0;i<n;i++)
        {
            cin >> cars[i];
        }

        int maxA[n], maxB[n];
        for(int i=n-1;i>=0;i--)
        {
            maxA[i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(cars[i]<cars[j])
                {
                maxA[i]=max(maxA[i], maxA[j]+1);
                //cout << i << " " << j << " " << cars[i] << " " << cars[j] << " " << maxA[i] << " " << maxA[j] << endl;
                }
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            maxB[i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(cars[i]>cars[j])
                {
                    maxB[i]=max(maxB[i], maxB[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //cout << maxA[i] << " " << maxB[i] << endl;
            ans=max(maxA[i]+maxB[i]-1, ans);
        }
        cout << ans << endl;
    }
}
