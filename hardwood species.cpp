#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int n, i, j;

    cin >> n;

    fflush(stdin);

    string s;
    string s2;

    map <string, double> m;
    map <string, double>::iterator p;
    double total;
    double fraction;

    getline(cin, s);
    getline(cin,s);

    while(n--)
    {
        m.clear();
        total=0;
        while(getline(cin, s)&& s.length()!=0)
        {
            total++;
            m[s]++;
        }

        p=m.begin();

        while(p!=m.end())
        {
            fraction=(p->second/total)*100.0;
            cout << p->first << " ";
            printf("%.4f", fraction);
            cout << endl;
            p++;
        }

        if(n!=0)
        {
        cout << endl;
        }
    }
}
