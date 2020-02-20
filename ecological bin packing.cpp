#include <iostream>
#include <cstdio>

using namespace std;

int priority(int * a, int i, int j , int k)
{
    int b[3];

    b[0] = i;
    b[1] = j;
    b[2] = k;


    for(int counter=0;counter<3;counter++)
    {
        if(*(a+counter)==1 && (b[counter]==2 || b[counter]==0))
        {
            return 1;
        }

        else if(*(a+counter)==2 && b[counter]==0)
        {
            return 1;
        }

        else if(*(a+counter)==0 && b[counter]!=0)
        {
            return 0;
        }

        else if(*(a+counter)==2 && b[counter]==1)
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    int bottles[9],colors[3];
    while(scanf("%d%d%d%d%d%d%d%d%d", &bottles[0], &bottles[1], &bottles[2], &bottles[3],
                &bottles[4], &bottles[5], &bottles[6], &bottles[7], &bottles[8])!=EOF)
    {
        int minmoves=1000000000;
        int moves;
        int box1[3], box2[3], box3[3];

        box1[0] = bottles[3]+bottles[6];  //Number of moves when first box is brown
        box1[1] = bottles[4]+bottles[7];  //Number of moves when first box is green
        box1[2] = bottles[5]+bottles[8];  //Number of moves when first box is clear
        box2[0] = bottles[0]+bottles[6];
        box2[1] = bottles[1]+bottles[7];
        box2[2] = bottles[2]+bottles[8];
        box3[0] = bottles[0]+bottles[3];
        box3[1] = bottles[1]+bottles[4];
        box3[2] = bottles[2]+bottles[5];

        int i,j,k;

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    moves = box1[i]+box2[j]+box3[k];

                    if(i==j || j==k || i==k)
                    {
                        continue;
                    }

                    if(moves<minmoves)
                    {
                        minmoves = moves;
                        colors[0]=i;
                        colors[1]=j;
                        colors[2]=k;
                    }

                    else if(minmoves==moves)
                    {
                       // cout << "\n\n" << colors[0] << colors[1] << colors[2] << "\n\n";
                        if(priority(colors,i,j,k))
                        {
                            colors[0]=i;
                            colors[1]=j;
                            colors[2]=k;
                        }
                       // cout << "\n\n" << colors[0] << colors[1] << colors[2] << "\n\n";
                    }
                }
            }
        }

        char result[4];

        for(i=0;i<3;i++)
        {
            if(colors[i]==0)
            {
                result[i]='B';
            }

            else if(colors[i]==1)
            {
                result[i]='G';
            }

            else
            {
                result[i]='C';
            }
        }
        result[3]='\0';

        cout << result << " " << minmoves << endl;
    }
}



