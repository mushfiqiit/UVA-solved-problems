#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct query{
int Qnum;
int period;
int initial_period;

query(int Qnum, int period, int initial_period)
        :Qnum(Qnum), period(period), initial_period(initial_period)
        {
        }
};

struct compareQuery{
    bool operator()(query const& q1, query const& q2)
    {
        if(q1.period!=q2.period)
        {
            return q1.period>q2.period;
        }

        else
        {
            return q1.Qnum>q2.Qnum;
        }
    }
};

int main()
{
    priority_queue<query, vector<query>, compareQuery> Q;

    int Qnum, period, k, i;

    string reg;

    cin >> reg;

    while(reg!="#")
    {
        cin >> Qnum >> period;

        Q.push(query(Qnum, period, period));

        cin >> reg;
    }

    cin >> k;

    for(i=0;i<k;i++)
    {
        query data = Q.top();
        Q.pop();
        cout << data.Qnum << endl;
        data.period=data.period + data.initial_period;
        Q.push(data);
    }

}


