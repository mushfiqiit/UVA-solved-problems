#include <bits/stdc++.h>

using namespace std;

int main()
{
  //  freopen("input.txt", "r", stdin);
    int N;

    while(cin >> N)
    {
        int a[N][N];

        int leftpointer, rightpointer;
        int rowsum[N]={0};
        int ans=0;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin >> a[i][j];
            }
        }

        for(int leftpointer=0;leftpointer<N;leftpointer++)
        {
            for(int rightpointer=leftpointer;rightpointer<N;rightpointer++)
            {
                int colsum=0, maxcolsum=0;
                memset(rowsum, 0, sizeof rowsum);
                for(int i=0;i<N;i++)
                {
                    for(int j=leftpointer;j<rightpointer;j++)
                    {
                        rowsum[i]=rowsum[i]+a[i][j];
                    }

                    colsum=colsum+rowsum[i];
                    maxcolsum=max(colsum, maxcolsum);

                    if(colsum<0)
                    {
                        colsum=0;
                    }
                }

                if(maxcolsum>ans)
                {
                    ans=maxcolsum;
                }
            }
        }

        cout << ans << endl;
    }
}
