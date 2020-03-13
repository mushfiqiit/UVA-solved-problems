#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);
    string tc;

    while(getline(cin, tc), tc!="0 Fuel consumption 0")
    {
        int distance, jalani=0;
        char command[111];
        char garbage1[111], garbage2[111];
        double runningfuel=0.0, totaltank=0.0;
        int leak=0;
        int prevdis=0, nextdis;

        do{
            sscanf(tc.c_str(), "%d %s", &distance, &command);

            nextdis=distance;

            runningfuel=runningfuel+(jalani*(nextdis-prevdis))/100.0;
            runningfuel=runningfuel+leak*(nextdis-prevdis);

            totaltank=max(totaltank, runningfuel);

            if(command[0]=='G' && command[1]=='o')
            {
                break;
            }

            else if(command[0]=='L')
            {
                leak++;
            }

            else if(command[0]=='M')
            {
                leak=0;
            }

            else if(command[0]=='G')
            {
                runningfuel=0;
            }

            else if(command[0]=='F')
            {
                sscanf(tc.c_str(), "%d %s %s %d", &distance, &garbage1, &garbage2, &jalani);
            }
            prevdis=nextdis;
        }

        while(getline(cin , tc));

        printf("%.3lf\n", totaltank);
    }
}
