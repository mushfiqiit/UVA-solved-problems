#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;


int main(void)
{
    int N;
    vector <int> ans;
    int i, j;

    while(scanf("%d",&N)==1 && N)
    {
        int maxPotSum=0, sum=0, potSum=0;
        int power=1<<N;
        vector <int> w;
        vector <int> p;
        w.clear();
        p.clear();
        int weights, potencies;
        for(i=0;i<power;i++)
        {
            scanf("%d", &weights);
            w.push_back(weights);
        }


        for(i=0;i<power;i++)
        {
            sum=0;
            for(j=0;j<N;j++)
            {
                sum=sum+w[i^(1<<j)];
            }
            p.push_back(sum);

        }


        for(i=0;i<power;i++)
        {
            potSum=0;
            for(j=0;j<N; j++)
            {
                    potSum=p[i]+p[i^(1<<j)];

                    if(potSum>maxPotSum)
                    {
                        maxPotSum=potSum;
                    }
            }
        }
        ans.push_back(maxPotSum);

    }

    for(i=0;i<ans.size();i++)
    {
        cout << ans[i] << endl;
    }
}
