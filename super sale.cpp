#include <bits/stdc++.h>

using namespace std;


int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int ans=0;
        vector<int> value;
        vector<int> weight;
        int N;
        cin >> N;
        int p, w, flag[N]={0};

        value.push_back(0);
        weight.push_back(0);

        for(int i=0;i<N;i++)
        {
            cin >> p >> w;
            value.push_back(p);
            weight.push_back(w);
        }

        //knapsack
        int knapsack[N+1][33]={0};

        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<33;j++)
            {
                    knapsack[i][j]=knapsack[i-1][j];
                    if(weight[i]<=j)
                    {
                        knapsack[i][j]=max(knapsack[i][j], value[i]+knapsack[i-1][j-weight[i]]);
                    }
                 //   cout << knapsack[i][j] << " ";
            }
          //  cout << "\n";
        }

        int G;
        cin >> G;

        while(G--)
        {
            int maxweight;
            cin >> maxweight;
            ans=ans+knapsack[N][maxweight];
        }
        cout << ans << endl;
    }
}

