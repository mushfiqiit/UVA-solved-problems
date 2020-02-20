#include <iostream>

using namespace std;

int main()
{
    double H, D, U, F;
    cin >> H;
    while(H!=0)
    {
        cin >> U >> D >> F;
        int result;

        int i;
        double height=0, climb=U;

        for(i=1;;i++)
        {
            if(climb>0)
            {
            height = height + climb;
            }

            if(height>H)
            {
                result=1;
                break;
            }

            height = height - D;
            climb=climb-U*(F/100);

            if(height<0)
            {
                result=0;
                break;
            }
        }

        if(result==1)
        {
            cout << "success on day " << i << endl;
        }

        else if(result==0)
        {
            cout << "failure on day " << i << endl;
        }

        cin >> H;
    }
}
