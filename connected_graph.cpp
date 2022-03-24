#include<bits/stdc++.h>
// to check the connectivity of graph using dfs
using namespace std;
bool arr[5];
vector<vector<int>>g;
void edge(int a,int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

void dfs(int x)
{
	arr[x]=true;
	for(int i=0;i<g[x].size();i++)
	{
		if(arr[g[x][i]]==false)
			{
				dfs(g[x][i]);
			}
	}
}

int main()
{
	for(int i=0;i<5;i++)
		arr[i]=false;
	g.assign(6,vector<int>());
	edge(0,1);
	edge(3,1);
	edge(0,3);
	edge(2,4);
	dfs(3);
	int flag=0;
	for(int i=0;i<5;i++)
	{	if(arr[i]==false)
			{flag=1;break;}
	}
	if(flag==0)
	cout<<"connected";
	else
	cout<<"not connected";
return 0;
}