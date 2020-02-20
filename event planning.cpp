#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int N,B,H,W;

    while(scanf("%d%d%d%d",&N,&B,&H, &W)!=EOF)
    {
        int i,j,k;
        int hotels[H];
        int cost, mincost;
        mincost = B+1;

        for(i=0;i<H;i++)
        {
            hotels[i]=0;
            int p;
            int beds[W];
            cost = B+1;

            cin >> p;

            for(j=0;j<W;j++)
            {
                cin >> beds[j];

                if(beds[j]>=N)
                {
                    hotels[i]=1;
                }
            }

            if(hotels[i]==1 && N*p<=B)
            {
                cost=N*p;
            }

            if(cost<mincost)
            {
                mincost = cost;
            }
        }

        if(mincost<=B)
        {
            cout << mincost << endl;
        }

        else
        {
            cout << "stay home" << endl;
        }
    }

}
