#include <bits/stdc++.h>

using namespace std;

struct brick{
int base, length, height;
brick(int base, int length, int height)
    :base(base), length(length), height(height)
    {
    }
};

struct comparePQ{
bool operator()(brick b1, brick b2)
{
    if(b1.base==b2.base)
    {
        return b1.length>b2.length;
    }
    return b1.base>b2.base;
}
};

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    priority_queue<brick, vector<brick>, comparePQ> sortedBricks;
    int tc=1;

    while(cin >> n, n!=0)
    {
        //cout << "Here" << endl;
        if(n==0)
        {
            break;
        }
        sortedBricks=priority_queue<brick, vector<brick>, comparePQ>();
        int a[3];
        int x[100000], y[100000], z[100000], length[100000], previous[100000];
        for(int i=0;i<n;i++)
        {
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a+3);
            sortedBricks.push(brick(a[0], a[1], a[2]));
            sortedBricks.push(brick(a[1], a[2], a[0]));
            sortedBricks.push(brick(a[0], a[2], a[1]));
        }
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        memset(z, 0, sizeof z);
        memset(length, 0, sizeof length);
        memset(previous, 0, sizeof previous);

        x[n]=0;
        y[n]=0;
        z[n]=0;
        previous[0]=-1;
        length[0]=0;
        length[n]=1;
        int maxheight=0;

        int i=1;
        while(!sortedBricks.empty())
        {
            brick temp=sortedBricks.top();
            //cout << temp.base << " " << temp.length << " " << temp.height << " " << i <<  endl;
            sortedBricks.pop();
            x[i]=temp.base;
            y[i]=temp.length;

            for(int j=0;j<i;j++)
            {
                if(x[j]<x[i] && y[j]<y[i] && z[i]<z[j]+temp.height)
                {
                    previous[i]=j;
                    length[i]=length[j]+1;
                    z[i]=z[j]+temp.height;
                    maxheight=max(z[i], maxheight);
                    //cout << x[i] << " " << y[i] << " " << length[i] << " " << z[i] << " "
                    //<< length[j] << " " << i << endl;
                }
            }
            i++;
        }
        cout << "Case "<< tc << ": " << "maximum height = " << maxheight << endl;
        tc++;
    }
}
