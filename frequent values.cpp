#include <bits/stdc++.h>

using namespace std;

int arr[100001], tree[300003], f[100001]={0};

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=f[b];
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int mid=(b+e)/2;
    init(l, b, mid);
    init(r, mid+1, e);
    tree[node]=max(tree[l], tree[r]);
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
    {
        return 0;
    }

    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int l=node*2;
    int r=node*2+1;
    int mid=(b+e)/2;
    int p1=query(l, b, mid, i, j);
    int p2=query(r, mid+1, e, i, j);
    return max(p1, p2);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    while(cin >> n, n!=0)
    {
    cin >> q;
    memset(f, 0, sizeof f);

    int a[n+1], ind[n+1], b[n+1]={0};
    int counter=0;

    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        counter++;
        if(i!=1)
        {
            if(a[i]!=a[i-1])
            {
                b[i-1]=1;
                f[i-1]=counter-1;
                counter=1;
            }
        }
    }
    f[n]=counter;
    b[n]=1;
    ind[n]=n;

    for(int i=n;i>1;i--)
    {
        if(a[i-1]==a[i])
        {
            ind[i-1]=ind[i];
            f[i-1]=f[i];
        }

        else
        {
            ind[i-1]=i-1;
        }
    }

    /*for(int i=1;i<=n;i++)
    {
        cout << f[i] << " ";
    }

    cout << "\n";

    for(int i=1;i<=n;i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";

    for(int i=1;i<=n;i++)
    {
        cout << ind[i] << " ";
    }
    cout << "\n";*/

    init(1, 1, n);

    int ans=0;
    for(int i=0;i<q;i++)
    {
        ans=0;
        int p, q;
        cin >> p >> q;
        int u, v;
        u=min(ind[p]+1, q+1);
        if(b[q]!=1)
        {
        v=max(q-(f[q]-(ind[q]-q)), p-1);
        }

        else
        {
            v=q;
        }
        //cout << "p q : " << p << " " << q << endl;
        //cout << u << " " << v << endl;
        if(u<v)
        {
        ans=query(1, 1, n, u, v);
        }
        //cout << ans << endl;
        ans=max(ans, u-p);
        ans=max(ans, q-v);
        cout << ans << endl;
    }
    }

}
