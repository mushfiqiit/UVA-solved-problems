#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int main()
{
    int n,i,j,k,l,index1i,index1j,index2i, index2j;

    cin >> n;

    int stacks[n][n];
    int top[n];

    //inititalizing

    for(i=0;i<n;i++)
    {
        top[i] = 0;
        stacks[i][0] = i;
        for(j=1;j<n;j++)
        {
            stacks[i][j] = -1;
        }
    }

    string command, prepos;

    cin >> command;


    while(command!="quit")
    {
        int n1, n2;
        cin >> n1 >> prepos >> n2;


        // Searching elements
        int found = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;stacks[i][j]!=-1;j++)
            {
                if(stacks[i][j]==n1)
                {
                    index1i = i;
                    index1j = j;
                    found = found + 1;
                }

                else if(stacks[i][j]==n2)
                {
                    index2i = i;
                    index2j = j;
                    found = found + 1;
                }
            }

            if(found==2)
            {
                break;
            }
        }

        if(n1==n2 || index1i==index2i)
        {
            cin >> command;
            continue;
        }


        if(command=="move" && prepos=="onto")
        {
            //Evacuating the n1 stack
            for(k=index1j+1;k<=top[index1i];k++)
            {
                stacks[ stacks[index1i][k] ][0] = stacks[index1i][k];
                top[ stacks[index1i][k] ] = 0;
                stacks[index1i][k]=-1;
            }

            //Evacuating the n2 stack
            for(k=index2j+1;k<=top[index2i];k++)
            {
                stacks[ stacks[index2i][k] ][0] = stacks[index2i][k];
                top[ stacks[index2i][k] ] = 0;
                stacks[index2i][k]=-1;
            }

            stacks[index2i][index2j+1]=stacks[index1i][index1j];
            stacks[index1i][index1j] = -1;
            top[index1i] = index1j-1;
            top[index2i] = index2j+1;
        }

        else if(command=="move" && prepos=="over")
        {
            //Evacuating n1 stack
            // cout << "\n\n" << top[index1i] << "\n\n";
            for(k=index1j+1;k<=top[index1i];k++)
            {
                stacks[ stacks[index1i][k] ][0] = stacks[index1i][k];
                top[ stacks[index1i][k] ] = 0;
                stacks[index1i][k]=-1;
            }
            stacks[index2i][++top[index2i]] = stacks[index1i][index1j];
            top[index1i]=index1j-1;
            stacks[index1i][index1j] = -1;
        }

        else if(command=="pile" && prepos=="over")
        {
            int elementsToPile = 0;
            l=top[index2i]+1;
            //Transferring at once
            for(k=index1j;k<=top[index1i];k++,l++)
            {
                stacks[index2i][l]=stacks[index1i][k];
                stacks[index1i][k]=-1;
                elementsToPile = elementsToPile + 1;
            }
            top[index2i] = top[index2i] + elementsToPile;
            top[index1i] = top[index1i] - elementsToPile;
        }

        else if(command=="pile" && prepos=="onto")
        {
            //Evacuating n2 stack
            for(k=index2j+1;k<=top[index2i];k++)
            {
                stacks[ stacks[index2i][k] ][0] = stacks[index2i][k];
                top[ stacks[index2i][k] ] = 0;
                stacks[index2i][k] = -1;
            }
            top[index2i] = index2j;

            l = index1j;

            //Transferring

            for(k=index2j+1;l<=top[index1i];k++,l++)
            {
                stacks[index2i][k] = stacks[index1i][l];
                stacks[index1i][l] = -1;
                top[index2i] = top[index2i]+1;
            }
            top[index1i] = index1j -1;

        }


        //Debugging purpose ***

 /*       cout << "\n\n";
    for(i=0;i<n;i++)
    {
        cout << i << ":";
        for(j=0;j<=top[i];j++)
        {
            cout << " " << stacks[i][j];
        }
        cout << "\n";
    }
     cout << "\n\n"; */

        // ******


        cin >> command;
    }

    for(i=0;i<n;i++)
    {
        cout << i << ":";
        for(j=0;j<=top[i];j++)
        {
            cout << " " << stacks[i][j];
        }
        cout << "\n";
    }
}
