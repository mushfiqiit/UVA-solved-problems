#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char max_hand(int spades, int hearts, int diamonds, int clubs);

int main()
{
    vector <string> ans;
    int i;
    char card[13][3];

    while(cin >> card[0] && strcmp(card[0],"EOF"))
    {
        int points=0, notrump_points=0;
        int s_power=20, h_power=20, d_power=20, c_power=20;
        int s_sub_power=20, h_sub_power=20, d_sub_power=20, c_sub_power=20;
        int s_stopped=0, h_stopped=0, d_stopped=0, c_stopped=0;
        int spades=0, hearts=0, diamonds=0, clubs=0;
        int sk=0, sq=0, sj=0, hk=0, hq=0, hj=0, dk=0, dq=0, dj=0, ck=0, cq=0, cj=0;

        for(i=1;i<13;i++)
        {
            cin >> card[i];
        }

        for(i=0;i<13;i++)
        {

            if(card[i][0]=='A')
            {
                points=points+4;
                notrump_points=notrump_points+4;

                if(card[i][1]=='S')
                {
                    s_power=0;
                    spades=spades+1;
                }

                else if(card[i][1]=='H')
                {
                    h_power=0;
                    hearts=hearts+1;
                }

                else if(card[i][1]=='D')
                {
                    d_power=0;
                    diamonds=diamonds+1;
                }

                else if(card[i][1]=='C')
                {
                    c_power=0;
                    clubs=clubs+1;
                }

                else
                {
                    cout << "Error";
                }
            }

            else if(card[i][0]=='K')
            {
                points=points+3;

                notrump_points=notrump_points+3;
                if(card[i][1]=='S')
                {
                    if(s_power>1)
                    {
                        s_power=1;
                    }
                    sk=1;
                    spades=spades+1;
                }

                else if(card[i][1]=='H')
                {
                    if(h_power>1)
                    {
                        h_power=1;
                    }
                    hk=1;
                    hearts=hearts+1;
                }

                else if(card[i][1]=='D')
                {
                    if(d_power>1)
                    {
                        d_power=1;
                    }
                    dk=1;
                    diamonds=diamonds+1;
                }

                else if(card[i][1]=='C')
                {
                    if(c_power>1)
                    {
                        c_power=1;
                    }
                    ck=1;
                    clubs=clubs+1;
                }
            }

            else if(card[i][0]=='Q')
            {
                points=points+2;

                notrump_points=notrump_points+2;
                if(card[i][1]=='S')
                {
                    if(s_power>2)
                    {
                        s_power=2;
                    }
                    sq=1;
                    spades=spades+1;
                }

                else if(card[i][1]=='H')
                {
                    if(h_power>2)
                    {
                        h_power=2;
                    }
                    hq=1;
                    hearts=hearts+1;
                }

                else if(card[i][1]=='D')
                {
                    if(d_power>2)
                    {
                        d_power=2;
                    }
                    dq=1;
                    diamonds=diamonds+1;
                }

                else if(card[i][1]=='C')
                {
                    if(c_power>2)
                    {
                        c_power=2;
                    }
                    cq=1;
                    clubs=clubs+1;
                }

                else
                {
                    cout << "Error";
                }
            }

            else if(card[i][0]=='J')
            {
                points=points+1;

                notrump_points=notrump_points+1;
                if(card[i][1]=='S')
                {
                    if(s_power>3)
                    {
                        s_power=3;
                    }
                    sj=1;
                    spades=spades+1;
                }

                else if(card[i][1]=='H')
                {
                    if(h_power>3)
                    {
                        h_power=3;
                    }
                    hj=1;
                    hearts=hearts+1;
                }

                else if(card[i][1]=='D')
                {
                    if(d_power>3)
                    {
                        d_power=3;
                    }
                    dj=1;
                    diamonds=diamonds+1;
                }

                else if(card[i][1]=='C')
                {
                    if(c_power>3)
                    {
                        c_power=3;
                    }
                    cj=1;
                    clubs=clubs+1;
                }

                else
                {
                    cout << "Error";
                }
            }

            else
            {
                if(card[i][1]=='S')
                {
                    spades=spades+1;
                }

                else if(card[i][1]=='H')
                {
                    hearts=hearts+1;
                }

                else if(card[i][1]=='D')
                {
                    diamonds=diamonds+1;
                }

                else if(card[i][1]=='C')
                {
                    clubs=clubs+1;
                }
            }
        }


        // Subtraction part :
        if(sk==1 && spades==1)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(hk==1 && hearts==1)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(dk==1 && diamonds==1)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(ck==1 && clubs==1)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(sq==1 && spades<=2)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(hq==1 && hearts<=2)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(dq==1 && diamonds<=2)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(cq==1 && clubs<=2)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(sj==1 && spades<=3)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(hj==1 && hearts<=3)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }

        if(dj==1 && diamonds<=3)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }


        if(cj==1 && clubs<=3)
        {
            points=points-1;
            notrump_points=notrump_points-1;
        }



        //Without no trump part

        if(spades==2)
        {
            points=points+1;
        }

        else if(spades<=1)
        {
            points=points+2;
        }

        if(hearts==2)
        {
            points=points+1;
        }

        else if(hearts<=1)
        {
            points=points+2;
        }

        if(diamonds==2)
        {
            points=points+1;
        }

        else if(diamonds<=1)
        {
            points=points+2;
        }

        if(clubs==2)
        {
            points=points+1;
        }

        else if(clubs<=1)
        {
            points=points+2;
        }

        if(s_power==0 || (s_power==1 && spades>=2) || (s_power==2 && spades>=3))
        {
            s_stopped=1;
        }

        if(h_power==0 || (h_power==1 && hearts>=2) || (h_power==2 && hearts>=3))
        {
            h_stopped=1;
        }

        if(d_power==0 || (d_power==1 && diamonds>=2) || (d_power==2 && diamonds>=3))
        {
            d_stopped=1;
        }

        if(c_power==0 || (c_power==1 && clubs>=2) || (c_power==2 && clubs>=3))
        {
            c_stopped=1;
        }


        if(points<14)
        {
            cout << "PASS" << endl;
            ans.push_back("PASS");
        }

        else if(notrump_points>=16 && c_stopped && d_stopped && h_stopped && s_stopped)
        {
            cout << "BID NO-TRUMP" << endl;
            ans.push_back("BID NO-TRUMP");
        }

        else
        {
            string to_show, to_show2;
            cout << "BID " << max_hand(spades, hearts, diamonds, clubs) << endl;
            to_show2 = max_hand(spades, hearts, diamonds, clubs);
            to_show = "BID " + to_show2;
            ans.push_back(to_show);
        }

    }

}

char max_hand(int spades, int hearts, int diamonds, int clubs)
{
    if(spades>=hearts && spades>=diamonds && spades>=clubs)
    {
        return 'S';
    }

    else if(hearts>=spades && hearts>=diamonds && hearts>=clubs)
    {
        return 'H';
    }

    else if(diamonds>=spades && diamonds>=hearts && diamonds>=clubs)
    {
        return 'D';
    }

    else
    {
        return 'C';
    }
}
