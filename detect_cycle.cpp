#include <bits/stdc++.h>
using namespace std;

bool detect_cycle(vector<int> adj[],bool visited[],int s,int parent)
{
	visited[s]=1;

	for(auto i:adj[s])
	{
		if(visited[i]==false)
		{
			if(detect_cycle(adj,visited,i,s))
			{
				return 1;
			}
			else if(i!=parent)
			{
				return 1;
			}
		}
	}
	return 0;
}

void addedge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(int argc, char const *argv[])
{
	
	int v=5;
	std::vector<int> adj[v];
	addedge(adj,0,1);
	addedge(adj,0,2);
	addedge(adj,0,3);
	addedge(adj,1,2);
	addedge(adj,1,3);
	addedge(adj,2,4);

	bool visited[v+1];
	memset(visited,0,sizeof(visited));

	for(int i=0;i<v;i++)
	{
		if(visited[i]==0)
		{
			// visited[i]=1;
			if(detect_cycle(adj,visited,i,-1))
			{
				cout<<"cycle";
			}
		}
	}
	for(auto i:visited)
		{
			cout<<i;
		}
	

	// print(adj,v);



	return 0;
}