#include <iostream>
#include <cstdio>

using namespace std;

int lengthCounter(int n)
{
    int length=0;

    while(n)
    {
        length = length + 1;

        if(n==1)
        {
            break;
        }

        if(n%2!=0)
        {
            n=3*n + 1;
        }

        else
        {
            n = n/2;
        }
    }
    return length;
}

int main()
{
    int i,j;

    while(scanf("%d %d", &i, &j)!=EOF)
    {
        int small,large;
        if(i>j)
        {
            small = j;
            large = i;
        }

        else
        {
            small = i;
            large = j;
        }

        int counter,maxLength=0;

        for(counter=small;counter<=large;counter++)
        {
            if(lengthCounter(counter)>maxLength)
            {
                maxLength = lengthCounter(counter);
            }
        }

        cout << i << " " << j << " " << maxLength << endl;
    }
}
