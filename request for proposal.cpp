#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int n, p;
    string requirements;
    string hudai;

    int counter=0;

    while(cin >> n >> p, n||p)
    {
        counter++;
        cout << n << " " << p << endl;
        int i, j;

        double maxiprice=2000000000;
        int maxipropreq=-1, maxindex;

        string proposals;
        double price;
        int propreq;
        string name;

        // Requirement input
        for(i=0;i<n;i++)
        {
            cin.ignore();
            getline(cin, requirements);
            cout << requirements << endl;
        }


        // Proposal input
        for(i=0;i<p;i++)
        {
            // Get proposal name
            getline(cin, proposals);
            cout << proposals << endl;

            // Get price and requirements
            scanf("%lf %d", &price, &propreq);
            cout << price << " " << propreq << endl;

            if(propreq>maxipropreq)
            {
                maxipropreq = propreq;
                maxiprice = price;
                name = proposals;
            }

            else if(propreq==maxipropreq && price<maxiprice)
            {
                    maxipropreq = propreq;
                    maxiprice=price;
                    name=proposals;
            }

            for(j=0;j<propreq;j++)
            {
                getline(cin, hudai);
                cout << hudai << endl;
            }
        }

        if(counter>1)
        {
            cout << "\n";
        }


// Output values
        cout << "RFP #" << counter << endl;
        cout << name << endl;
    }
}
