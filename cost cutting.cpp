#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T,i,j;
    cin >> T;

    int ans[T];

    for(i=0;i<T;i++)
    {
        int salary[3];

        for(j=0;j<3;j++)
        {
            cin >> salary[j];
        }

        sort(salary,salary+3);
        ans[i] = salary[1];
    }

    for(i=0;i<T;i++)
    {
        cout << "Case " << i+1 << ": " << ans[i] << endl;
    }

}
