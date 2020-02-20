#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ans;
    for(;;)
    {
        int month,depreciations;
        double downPayment,loan;

        cin >> month >> downPayment >> loan >> depreciations;

        int depmonth[depreciations];
        float depamount[depreciations];

        if(month<0)
        {
            break;
        }

        int i,j;

        for(i=0;i<depreciations;i++)
        {
            cin >> depmonth[i] >> depamount[i];
        }

        double owed,value,payment;
        value = loan + downPayment;
        owed = loan;
        payment = loan/(double) month;

        for(i=0,j=0;j<month;j++)
        {
            if(j==depmonth[i])
            {
                value = value - depamount[i] * value;

                i=i+1;
            }

            else if(j!=depmonth[i] && i!=0)
            {
                value = value - depamount[i-1]*value;
            }

            if(j!=0)
            {
            owed=owed - payment;
            }

     //       cout << owed << " " << value << endl;

            if(owed<value)
            {
                ans.push_back(j);
                break;
            }
        }

        if(j==month)
        {
            ans.push_back(j);
        }

    }

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==1)
        {
        cout << ans[i] << " month" << endl;
        }

        else
        {
            cout << ans[i] << " months" << endl;
        }
    }
}
