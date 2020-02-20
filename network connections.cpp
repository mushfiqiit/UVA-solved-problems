#include <bits/stdc++.h>

using namespace std;

void initialize( int Arr[], int size[], int N)
{
    for(int i = 0;i<N;i++)
    {
Arr[ i ] = i ;
size[ i ] = 1;
}
}

int root (int Arr[ ] ,int i)
{
    while(Arr[i]!= i)
    {
        i = Arr[ i ];
    }
return i;
}

bool findit(int Arr[], int A, int B)
{
    if(root(Arr, A)==root(Arr, B))
    {
        return true;
    }

    else
    {
        return false;
    }
}

void Union(int Arr[], int Size[], int A, int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);


    if(Size[root_A] < Size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
Size[root_B] += Size[root_A];
}
    else
    {
Arr[ root_B ] = Arr[root_A];
Size[root_A] += Size[root_B];
}

}

int main()
{
    //freopen("testcase.txt", "r", stdin);
    int t;
    cin >> t;


    while(t--)
    {
        int success=0, failure=0;
        int n;
        cin >> n;
        cin.ignore();
        int parent[n], Size[n];

        initialize(parent, Size, n);

        char ch;
        int connect1, connect2;

        while(1)
        {
            string str;
            getline(cin, str);
            if(str.empty())
            {
                break;
            }
            sscanf(str.c_str(), "%c %d %d",&ch, &connect1, &connect2);
            connect1--;
            connect2--;

        if(ch=='c')
        {
            Union(parent, Size, connect1, connect2);
        }

        else
        {
            if(findit(parent, connect1, connect2))
            {
                success++;
            }

            else
            {
                failure++;
            }
        }
        }

        cout << success << "," << failure << endl;

        if(t!=0)
        {
        cout << "\n";
        }
    }
}
