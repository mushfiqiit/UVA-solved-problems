#include <bits/stdc++.h>

using namespace std;

struct sprinkler{
int position;
double leftbound, rightbound, dx;
sprinkler(int position, double leftbound, double rightbound, double dx)
        :position(position), leftbound(leftbound), rightbound(rightbound), dx(dx)
        {
        }
};

struct comparePQ{
bool operator()(sprinkler const& s1, sprinkler const& s2)
{
    if (s1.leftbound==s2.leftbound)
    {
        return s1.rightbound<s2.rightbound;
    }

    else
    {
        return s1.leftbound>s2.leftbound;
    }
}
};;

int main()
{
   // freopen("input.txt", "r", stdin);
    int n, l, w;

    while(cin >> n >> l >> w)
    {
        int ans=0;
        priority_queue<sprinkler, vector<sprinkler>, comparePQ> sprinklers;
        int position, radius;
        double dx;

        for(int i=0;i<n;i++)
        {
        cin >> position >> radius;
        if((double)((double)radius*(double)radius - ((double)w/2.0)*((double)w/2.0))>=0)
        {
        dx=(double)sqrt((double)((double)radius*(double)radius - ((double)w/2.0)*((double)w/2.0)));
        sprinklers.push(sprinkler(position, position-dx, position+dx, dx));
        }

        }

        struct sprinkler temp1(0, 0, 0, 0);
        int counter=0;
        sprinkler tempmax(0, 0, 0, 0);

      /*  while(!sprinklers.empty())
        {
            cout << sprinklers.top().leftbound << " " << sprinklers.top().rightbound << endl;
            sprinklers.pop();
        } */

        while(!sprinklers.empty())
        {
           // cout <<sprinklers.top().leftbound << " " << sprinklers.top().rightbound << endl;

            while(!sprinklers.empty() && sprinklers.top().leftbound<=temp1.rightbound)
            {
            if(sprinklers.top().leftbound<=temp1.rightbound
               && sprinklers.top().rightbound>temp1.rightbound
               && sprinklers.top().rightbound>tempmax.rightbound)
            {
                tempmax=sprinklers.top();
            }
            sprinklers.pop();
            }

            if(tempmax.rightbound>temp1.rightbound)
            {
                temp1=tempmax;
                ans++;
            }

            else
            {
                break;
            }

            if(temp1.rightbound>=l)
            {
                break;
            }
        }


        if(temp1.rightbound<l)
        {
            ans=-1;
        }
        cout << ans << endl;
    }

}
