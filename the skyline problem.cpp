#include <bits/stdc++.h>

using namespace std;

struct building{
int L, R, H;
building(int L, int H, int R)
    :L(L), H(H), R(R)
    {
    }
};

struct comparePQ{
bool operator()(building const& b1, building const& b2)
{
    return b1.H<b2.H;
}
};

int main()
{
    //freopen("input.txt", "r", stdin);
    int land[10001]={0};
    vector<int> ans;
    priority_queue<building, vector<building>, comparePQ> sortedBuildings;

    int Le, Ri, He;

    while(cin >> Le >> He >> Ri)
    {
        sortedBuildings.push(building(Le, He, Ri));
    }

    while(!sortedBuildings.empty())
    {
        building btemp=sortedBuildings.top();
        sortedBuildings.pop();

        for(int i=btemp.L;i<btemp.R;i++)
        {
            if(btemp.H>land[i])
            {
                land[i]=btemp.H;
            }
        }
    }

    for(int i=1;i<=10000;i++)
    {
        if(land[i]!=land[i-1])
        {
            ans.push_back(i);
            ans.push_back(land[i]);
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i];

        if(i!=ans.size()-1)
        {
            cout << " ";
        }
    }
    cout << "\n";
}
