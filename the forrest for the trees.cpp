#include <bits/stdc++.h>

using namespace std;

void dfs();
void dfs_visit(int u);

vector<int> nodes[26];

int acorn[26], visited[26], presence[26];

string edges, letters;

int trees, acorns;


void dfs_visit(int u)
{
    visited[u]=1;

    for(int i=0;i<nodes[u].size();i++)
    {
        if(visited[nodes[u][i]]==0)
        {
            dfs_visit(nodes[u][i]);
        }
    }
}

void dfs()
{
    int incremented=0;
    for(int i=0;i<26;i++)
    {
        visited[i]=0;
    }

    for(int i=0;i<26;i++)
    {
        incremented=0;
        if(presence[i]==1 && visited[i]==0)
        {
            if(nodes[i].size()!=0)
            {
                visited[i]=1;
            }

            for(int j=0;j<nodes[i].size();j++)
            {
                if(visited[nodes[i][j]]==0)
                {
                    if(incremented==0)
                    {
                    trees++;
                    incremented=1;
                    }
                    dfs_visit(nodes[i][j]);
                }
            }
        }
    }
}

int main()
{
    // freopen("testcase.txt","r", stdin);

    int t;
    cin >> t;

    while(t--)
    {
        trees=0;
        acorns=0;

        for(int i=0;i<26;i++)
        {
            presence[i]=0;
            visited[i]=0;
            acorn[i]=1;
            nodes[i].clear();
        }


        while(cin >> edges, edges[0]!='*')
        {
            int from=edges[1]-65;
            int to=edges[3]-65;

            if(from==to)
            {
                continue;
            }

            acorn[from]=0;
            acorn[to]=0;
            nodes[from].push_back(to);
            nodes[to].push_back(from);
        }
        cin >> letters;

        for(int i=0;i<letters.length();i=i+2)
        {
            presence[letters[i]-'A']=1;
        }

        dfs();


        for(int i=0;i<26;i++)
        {
            if(presence[i]==1 && acorn[i]==1)
            {
                acorns++;
            }
        }

        cout <<"There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;

    }
}
