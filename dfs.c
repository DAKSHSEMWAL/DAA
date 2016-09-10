#include<stdio.h>
#define max 100
#define initial 1
#define visited 2
#define finished 3
int n;
int adj[max][max];
void create_graph();
int state[max];
void dftraversal();
void dfs(int v);
void creategraph()
{
	int i,maxedges,origin,destin;
	printf("\n enter no of nodes :");
	scanf("%d",&n);
	maxedges=n*(n-1);
	for(i=1;i<maxedges;i++)
	{
		printf("\n enter edges and -1,-1 to quit %d\n ",i);
		scanf("%d %d",&origin,&destin);
		if(origin==-1&& destin==-1)
		break;
		if(destin<0||origin>=n||destin>=n||origin<0)
		{
		printf("\n invalid edges");
		i--;
		}
		else
		adj[origin][destin]=1;
	}
}
void dftraversal()
{   
    int v;
	for(v=0;v<n;v++)
	state[v]=initial;
	printf("\n starting vertex for depth first search");
	scanf("%d",&v);
	for(v=0;v<n;v++)
	{
		if(state[v]==initial)
		dfs(v);
	}
	printf("\n");
}
void dfs(int v)
{   
int i;
	printf("\n %d",v);
	state[v]=visited;
	for(i=0;i<n;i++)
	{
		if(adj[v][i]==1&&state[i]==initial)
		dfs(i);
	}
}
int main()
{
creategraph();
dftraversal();
return 0;
}

