#include <bits/stdc++.h>
using namespace std;


void addedge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
bool detect_cycle(vector<int> adj[],bool visited[],int recst[],int s)
{
visited[s]=1;
recst[s]=1;
for(auto i:adj[s])
{
	if(visited[i]==0)
	{
		if(detect_cycle(adj,visited,recst,i))
		{
			return 1;
		}
	}
else if(recst[i]==1)
{
	return 1;
}

}
recst[s]=0;
return 0;


}
int main(int argc, char const *argv[])
{
	int v=5;
	std::vector<int> adj[v];
	addedge(adj,0,1);
	addedge(adj,0,2);
	addedge(adj,1,2);
	addedge(adj,1,3);
	addedge(adj,2,3);
	addedge(adj,3,4);

	int recst[v];
	memset(recst,0,sizeof(recst));
	bool visited[v+1];
	memset(visited,0,sizeof(visited));

    for(int i=0;i<v;i++)
    {
    	if(visited[i]==0)
    	{
         visited[i]=1;
    	if(detect_cycle(adj,visited,recst,i)	)
    	{
    		cout<<1;
    	}
    	else{
    		cout<<"no";
    	}
    	}
    }
	
	
	return 0;
}