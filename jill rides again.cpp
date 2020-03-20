#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);
    int b;
    cin >> b;
    int tc;

    for(tc=1;tc<=b;tc++)
    {
        int s;
        cin >> s;
       // cout << s << endl;
        int stops[s-1];
        int sum=0, ans=0, temp_range_i=1,range_i=1, range_j=0, length=0, maxlength=0;

        for(int i=0;i<s-1;i++)
        {
            cin >> stops[i];
        }

        for(int i=0;i<s-1;i++)
        {
            sum=sum+stops[i];

            if(sum>ans || ((i+2-temp_range_i>maxlength)&& (sum==ans)))
            {
                range_i=temp_range_i;

                ans=sum;
                range_j=i+2;
                maxlength=range_j-range_i;
            }

            if(sum<0)
            {
                temp_range_i=i+2;
                sum=0;
            }
          //  cout << sum << " " << ans << " " << temp_range_i << " " << range_j << endl;
        }

        if(range_j<range_i)
        {
            ans=-1;
        }

        if(ans>0)
        {
            cout << "The nicest part of route " << tc << " is between stops "
            << range_i << " and " << range_j << endl;
        }

        else
        {
            cout << "Route " << tc << " has no nice parts" << endl;
        }
    }
}
