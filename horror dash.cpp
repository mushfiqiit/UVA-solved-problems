#include <iostream>

using namespace std;

int main()
{
    int T,i,j;
    cin >> T;
    int ans[T];

    for(i=0;i<T;i++)
    {
        int N,maxspeed=0;
        cin >> N;
        int c[N];
        for(j=0;j<N;j++)
        {
            cin >> c[j];
            if(c[j]>maxspeed)
            {
                maxspeed = c[j];
            }
        }
        ans[i] = maxspeed;
    }

    for(i=0;i<T;i++)
    {
        cout << "Case " << i+1 << ": " << ans[i] << endl;
    }
}
