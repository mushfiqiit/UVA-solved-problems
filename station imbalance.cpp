#include <bits/stdc++.h>

using namespace std;

int main()
{
  //  freopen("input.txt", "r", stdin);
    int S, C;
    int tc=1;

    while(cin >> C >> S)
    {
        int specimen[S];
        int ans[C][2]={0};
        double average;
        int sum=0;
        double imbalance=0.0;

        for(int i=0;i<S;i++)
        {
            cin >> specimen[i];
            sum=sum+specimen[i];
        }
        average=(double)sum/(double)C;

        if(S<=C)
        {
            for(int i=0;i<S;i++)
            {
                ans[i][0]=specimen[i];
            }
        }

        else
        {
            sort(specimen, specimen+S);

            int s_iter, c_iter;
            s_iter=S-1;
            c_iter=0;

            for(;c_iter<C;c_iter++, s_iter--)
            {
                ans[c_iter][0]=specimen[s_iter];
            }

            for(c_iter=C-1;s_iter>=0;c_iter--, s_iter--)
            {
                ans[c_iter][1]=specimen[s_iter];
            }
        }

        cout << "Set #" << tc << endl;
        tc++;
        int chambermass;

        for(int i=0;i<C;i++)
        {
            chambermass=0;
            chambermass=chambermass+ans[i][0] + ans[i][1];

            cout  << " "<< i << ":";
            if(ans[i][0]!=0)
            {
                cout << " " << ans[i][0];
            }

            if(ans[i][1]!=0)
            {
                cout << " " << ans[i][1];
            }
            imbalance=imbalance+fabs((double)chambermass-average);
            cout << "\n";
        }
        cout << "IMBALANCE = ";
        printf("%.5lf\n\n", imbalance);
    }
}
