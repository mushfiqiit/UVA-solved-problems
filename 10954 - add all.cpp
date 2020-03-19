#include <bits/stdc++.h>

using namespace std;

struct comparePriority{
    bool operator() (int const &a, int const &b) {
        return a>b;
    }
};

int main()
{
    priority_queue<int, vector<int>, comparePriority> p;

    int N;

    while(cin >> N, N!=0)
    {
        p=priority_queue<int, vector<int>, comparePriority>();
        int i, a, b, cost=0;

        for(i=0;i<N;i++)
        {
            cin >> a;
            p.push(a);
        }

        while(p.size()>1)
        {
            a=p.top();
            p.pop();
            b=p.top();
            p.pop();
            cost=cost+a+b;
            p.push(a+b);
        }

        cout << cost << endl;
    }
}
