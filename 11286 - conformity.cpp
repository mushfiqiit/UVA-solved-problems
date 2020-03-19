#include <bits/stdc++.h>

using namespace std;


int main()
{
    map <vector<int>, int>::iterator p;
    map <vector <int>, int> m;
    int n, i, j;
    int ans, maxipop;

    int popularity, maxpop=0;

    while(cin >> n, n)
    {
        m.clear();
       vector<int> a(5);

       for(i=0;i<n;i++)
       {
        for(j=0;j<5;j++)
        {
           cin >> a[j];
        }
       sort(a.begin(), a.end());
       m[a]++;
       }
        maxipop=0;
        ans=0;

       p=m.begin();

       while(p!=m.end())
       {
           if(p->second==maxipop)
           {
               ans=ans+p->second;
           }

           else if(p->second>maxipop)
           {
               maxipop=p->second;
               ans=p->second;
           }
           p++;
       }
       cout << ans << endl;
    }
}
