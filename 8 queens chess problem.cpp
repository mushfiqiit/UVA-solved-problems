#include <bits/stdc++.h>

using namespace std;

int a, b, row[8], linecounter;

bool place(int r, int c)
{
    for(int prev=0;prev<c;prev++)
    {
        if((row[prev]==r) || (abs(row[prev]-r)==abs(prev-c)))
        {
            return false;
        }
    }
    return true;
}

void backtrack(int c)
{
    if(c==8)
    {
        printf("%2d      %d", ++linecounter, row[0]+1);
        for(int j=1;j<8;j++)
        {
            printf(" %d", row[j]+1);
        }
        cout << "\n";
    }

    for(int r=0;r<8;r++)
    {
        if(place(r, c))
        {
          //  cout << r << " " << c << endl;
            if((r==a && c!=b) || (c==b && r!=a))
            {
               // cout <<r << " " << c << "Here" << endl;
                continue;
            }
            row[c]=r;
            backtrack(c+1);
        }
    }
}


int main()
{
   // freopen("testcase.txt", "r", stdin);
    int datasets;
    cin >> datasets;

    while(datasets--)
    {
        cin >> a >> b;
        a=a-1;
        b=b-1;
        linecounter=0;

        memset(row, 0, sizeof row);


        cout << "SOLN" << "       " << "COLUMN\n";
        cout << " #      " << "1 2 3 4 5 6 7 8\n\n";
        backtrack(0);

        if(datasets)
        {
            cout << "\n";
        }
    }
}
