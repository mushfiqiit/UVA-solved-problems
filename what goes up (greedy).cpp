#include <bits/stdc++.h>

using namespace std;


int main()
{
   // freopen("input.txt", "r", stdin);
    int input;
    vector<int> arr;
    int L[100000], L_id[100000], P[100000];


    while(cin >> input)
    {
        arr.push_back(input);
    }

    int lis=0, lis_end=0;
    for(int i=0;i<arr.size();i++)
    {
        int pos=lower_bound(L, L+lis, arr[i])-L;
     //   cout << pos << endl;
        L[pos]=arr[i];
        L_id[pos]=i;
    //    cout << "Here" << endl;

        if(pos)
        {
        P[i]=L_id[pos-1];
        }

        else
        {
            P[i]=-1;
        }

        if(pos+1>=lis)
        {
            lis=pos+1;
            lis_end=i;
        }
    }
    cout << lis << endl;
    cout << "-" << endl;

    int x=lis_end;
    stack<int> s;

    while(P[x]>=-1)
    {
        s.push
        (arr[x]);
        x=P[x];

        if(x==-1)
        {
            break;
        }
    }

    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }


}
