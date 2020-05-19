#include <bits/stdc++.h>

using namespace std;
int w[1000], s[1000], ind[1000], sw[1000], previous[1000], L[1000];

bool compareElephant(int x, int y)
{
    if(s[x]==s[y])
    {
        return w[x]<w[y];
    }
    return s[x]>s[y];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int i=0;


    while(cin >> w[i] >> s[i])
    {
        ind[i]=i;
        previous[i]=-1;
        L[i]=1;
        i++;
    }
    int n=i;

    sort(ind, ind+n, compareElephant);
    sort(s, s+n, greater<int>());

    for(int i=0;i<n;i++)
    {
        sw[i]=w[ind[i]];
    }

    for(int i=0;i<n;i++)
    {
        //cout << sw[i] << " " << s[i] << " " << ind[i] << endl;
    }
    //cout << "\n\n";

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(sw[j]<sw[i] && s[j]>s[i])
            {
                if(L[j]+1>L[i])
                {
                    L[i]=L[j]+1;
                    previous[i]=j;
                }
            }
            //cout << L[i] << " " << L[j] << endl;
        }
        //cout << L[i] << endl;
    }
    //cout << "\n\n";

    int lis_end=-1, lis=0;
    for(int i=0;i<n;i++)
    {
        if(L[i]>lis)
        {
            lis=L[i];
            lis_end=i;
        }
    }

    stack<int> mystack;

    int x=lis_end;

    while(x>=0)
    {
        mystack.push(ind[x]);
        x=previous[x];
    }

    cout << lis << endl;
    while(!mystack.empty())
    {
        cout << mystack.top()+1 << endl;
        mystack.pop();
    }
}
