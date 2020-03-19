#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);
    int n, m;
    while(cin >> n >> m, (n!=0 && m!=0))
    {
        int flag=1, coins=0;
        int heads[n], knights[m];

        for(int i=0;i<n;i++)
        {
            cin >> heads[i];
        }

        for(int i=0;i<m;i++)
        {
            cin >> knights[i];
        }

        if(m<n)
        {
            flag=0;
        }

        else
        {
            sort(heads, heads+n);
            sort(knights, knights+m);
            int hc=0,kc=0;

            while(kc<m && hc<n)
            {
                if(knights[kc]>=heads[hc])
                {
                    coins=coins+knights[kc];
                    hc++;
                }
                kc++;
            }

            if(hc!=n)
            {
                flag=0;
            }
        }

        if(flag==0)
        {
            cout << "Loowater is doomed!" << endl;
        }

        else
        {
            cout << coins << endl;
        }
    }
}
