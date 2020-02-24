#include <bits/stdc++.h>

using namespace std;

int distance(int person[], int a, int b, int n)
{
    int a_ind, b_ind;
    for(int i=0;i<n;i++)
    {
        if(person[i]==a)
        {
            a_ind=i;
        }

        if(person[i]==b)
        {
            b_ind=i;
        }
    }
    return abs(a_ind-b_ind);
}

int main()
{
   // freopen("testcase.txt", "r", stdin);
    int n, m;
    while(cin >> n >> m, (n!=0 || m!=0))
    {
        int ans=0;
        int person[8], a[20], b[20], c[20];

        for(int i=0;i<n;i++)
        {
            person[i]=i;
        }

        for(int i=0;i<m;i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }

        do{
            int flag=1;

            for(int i=0;i<m;i++)
            {
                if(c[i]>0)
                {
                    if(distance(person, a[i], b[i], n)>c[i])
                    {
                        flag=0;
                        break;
                    }
                }

                else
                {
                    c[i]=-c[i];
                    if(distance(person, a[i], b[i], n)<c[i])
                    {
                        flag=0;
                        c[i]=-c[i];
                        break;
                    }

                    else
                    {
                        c[i]=-c[i];
                    }
                }
            }

            if(flag)
            {
                ans++;
            }
        }

        while(next_permutation(person, person+n));

        cout << ans << endl;
    }
}
