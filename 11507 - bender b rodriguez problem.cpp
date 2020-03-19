#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int L;
    while(cin >> L, L)
    {
        int i, j;
        int direction=1;
        char command[L-1][3];

        for(i=0;i<L-1;i++)
        {
            cin >> command[i];

            if(!strcmp(command[i], "+y"))
            {
                if(direction==1)
                {
                    direction=3;
                }

                else if(direction==2)
                {
                    direction=4;
                }

                else if(direction==3)
                {
                    direction=2;
                }

                else if(direction==4)
                {
                    direction=1;
                }

            }

            else if(!strcmp(command[i], "-y"))
            {
                if(direction==1)
                {
                    direction=4;
                }

                else if(direction==2)
                {
                    direction=3;
                }

                else if(direction==3)
                {
                    direction=1;
                }

                else if(direction==4)
                {
                    direction=2;
                }

            }

            else if(!strcmp(command[i], "+z"))
            {
                if(direction==1)
                {
                    direction=5;
                }

                else if(direction==2)
                {
                    direction=6;
                }

                else if(direction==5)
                {
                    direction=2;
                }

                else if(direction==6)
                {
                    direction=1;
                }
            }

            else if(!strcmp(command[i], "-z"))
            {
                if(direction==1)
                {
                    direction=6;
                }

                else if(direction==2)
                {
                    direction=5;
                }

                else if(direction==5)
                {
                    direction=1;
                }

                else if(direction==6)
                {
                    direction=2;
                }
            }
        }


        if(direction==1)
        {
            cout << "+x" << endl;
        }

        else if(direction==2)
        {
            cout << "-x" << endl;
        }

        else if(direction==3)
        {
            cout << "+y" << endl;
        }

        else if(direction==4)
        {
            cout << "-y" << endl;
        }

        else if(direction==5)
        {
            cout << "+z" << endl;
        }

        else
        {
            cout << "-z" << endl;
        }

    }
}
