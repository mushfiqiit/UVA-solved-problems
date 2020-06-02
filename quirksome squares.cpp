#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<int> ans[4];
    long long int p;

    for(int i=0;i<=99999999;i++)
    {
        if(i<=99)
        {
            p=((i/10)+(i%10))*((i/10)+(i%10));
            //cout << p << " " << i << endl;
            if(p==i)
            {
                //cout << pow((i/10)+(i%10), 2) << " " << i << endl;
                ans[0].push_back(i);
                //cout << i << endl;
            }
        }

        if(i<=9999)
        {
            p=((i/100)+(i%100))*((i/100)+(i%100));

            //cout << i/100 << " " << i%100 << " " << p << " " << i << endl;
            if(p==i)
            {
                ans[1].push_back(i);
            }
        }

        if(i<=999999)
        {
            p=((i/1000)+(i%1000))*((i/1000)+(i%1000));

            if(p==i)
            {
                ans[2].push_back(i);
            }
        }

        if(i<=99999999)
        {
            p=((i/10000)+(i%10000))*((i/10000)+(i%10000));

            if(p==i)
            {
                ans[3].push_back(i);
            }
        }
    }

    int n;

    while(cin >> n)
    {
        for(int i=0;i<ans[(n/2)-1].size();i++)
        {
            if(ans[(n/2)-1][i]<=9)
            {
                for(int j=1;j<n;j++)
                {
                    cout << "0";
                }
            }

            else if(ans[(n/2)-1][i]<=99)
            {
                for(int j=2;j<n;j++)
                {
                    cout << "0";
                }
            }

            else if(ans[(n/2)-1][i]<=999)
            {
                for(int j=3;j<n;j++)
                {
                    cout << "0";
                }
            }

            else if(ans[(n/2)-1][i]<=9999)
            {
                for(int j=4;j<n;j++)
                {
                    cout << "0";
                }
            }

            else if(ans[(n/2)-1][i]<=99999)
            {
                for(int j=5;j<n;j++)
                {
                    cout << "0";
                }
            }

            else if(ans[(n/2)-1][i]<=999999)
            {
                for(int j=6;j<n;j++)
                {
                    cout << "0";
                }
            }

            else if(ans[(n/2)-1][i]<=9999999)
            {
                for(int j=7;j<n;j++)
                {
                    cout << "0";
                }
            }

            else if(ans[(n/2)-1][i]<=99999999)
            {
                for(int j=8;j<n;j++)
                {
                    cout << "0";
                }
            }
            cout << ans[(n/2)-1][i] << endl;
        }
    }
}
