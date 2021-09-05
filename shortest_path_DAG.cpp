#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

class ListNode
{
	int v;
	int weight;
public:
	ListNode(int _v,int _weight){
		this.v=_v;
		this.weight=_weight;
	}
	int getv()
	{
		return v;

	}
	int getweight()
	{
		return weight;
	}
	~ListNode();
	
};

class Graph
{
	int v;
	vector<ListNode> *adj;
	void topsort(int v,bool visited[],stack<int>&st);
public:
	Graph(int v);
	void addedge(int u,int v,int weight);
	void shortestpath(int s);
	
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new vector<ListNode>[v];
}

void Graph::topsort(int v,bool visited[],stack<int>&st)
{
	visited[v]=1;

	for(auto i:adj[v])
	{

		if(visited[i]==0)
			{
				// visited[i]=1;
				topsort(i,visited,st);
			}

	}
	st.push(v);
}

void Graph::shortestpath(int s)
{
	stack<int>s;

	int dist[v];
	bool visited[v];
	memset(visited,0,sizeof(visited));

	for(int i=0;i<v;i++)
	{
		if(visited[i]==0)
		{
			topsort(i,visited,st);
		}
		
	}
}