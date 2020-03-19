#include <bits/stdc++.h>

using namespace std;

int N, tracks, nearestTotal, cd[20], ans;

void choose(int total,int mask ,int p)
{
    if(total>N)
    {
        return;
    }

    if(total>nearestTotal)
    {
        nearestTotal=total;
        ans=mask;
    }

    if(p>=tracks)
    {
        return;
    }

    choose(total+cd[p], mask|(1<<p), p+1);
    choose(total, mask, p+1);
}

int main()
{
   // freopen("input.txt", "r", stdin);
    while(cin >> N)
    {
        int sum=0;
        cin >> tracks;
        nearestTotal=0;

        for(int i=0;i<tracks;i++)
        {
            cin >> cd[i];
        }
        choose(0, 0, 0);

        for(int i=0;i<tracks;i++)
        {
            if((ans>>i)%2)
            {
                cout << cd[i] << " ";
                sum=sum+cd[i];
            }
        }
        cout << "sum:" << sum << endl;
    }
}
