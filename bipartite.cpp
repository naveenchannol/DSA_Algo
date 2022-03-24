#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//finding if a strongly connected  graph is bipartite
int colour[10000];
vector<vector<int>>g;
void edge(int a,int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}
bool oddcycle(int s)
{
    queue<int>q;
    q.push(s);
    colour[s]=1;
    while(!q.empty())
    {
        int x=q.front();
        //cout<< x<< " ";
        q.pop();
        vector<int>::iterator it;
        for(it=g[x].begin();it!=g[x].end();it++)
        {
            if(colour[*it]==-1)
            {
                colour[*it]=1-colour[x];
                q.push(*it);
               // cout<<"*";
                //arr[*it]=true;
            }
            else
            {
                if(colour[*it]==colour[x])
                return true;
            }
        }
    }
return false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    for(int i=0;i<1000;i++)
    {
        colour[i]=-1;//initially ntg is coloured
    }
    g.assign(n+1, vector<int>());
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edge(a, b);
    }
 if(oddcycle(1))
 {cout<<"not bipartite";}
 else
 {cout<<"bipartite";}
  return 0;
}
