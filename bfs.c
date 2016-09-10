#include<stdio.h>
#include<stdlib.h>
#define max 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[max][max];int state[max];int queue[max],front=-1,rear=-1;
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
void insert_queue(int vertex)
{
	if(rear==max-1)
	printf("\n oveflow");
	else
	{
		if(front==-1)
		front=0;
		rear=rear+1;
		queue[rear]=vertex;
	}
}
int isempty_queue()
{
	if(front==-1||front>rear)
	return 1;
	else
	return 0;
}
int delete_queue()
{
	int delitem;
	if(front==-1||front>rear)
	{
		printf("\n queue underflow\n");return 0;
	}
	delitem=queue[front];
	front=front+1;
	return delitem;
}
void bfs(int v)
{
	int i;
	insert_queue(v);
	state[v]=waiting;
	while(!isempty_queue())
	{
		v=delete_queue();
		printf("\n %d",v);
		state[v]=visited;
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1 && state[i]==initial)
			{
				insert_queue(i);
				state[i]=waiting;
			}
		}
	}
	printf("\n");
}
void bftraversal()
{
    int v;
	for(v=0;v<n;v++)
	state[v]=initial;
	printf("\n enter starting vertex for breadth first search")	;
	scanf("%d",&v);
	bfs(v);
}
int main()
{
creategraph();
bftraversal();
return 0;
}

