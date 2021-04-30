#include<stdio.h>
#include<stdlib.h>

int get_next_permutation(int *P,int n);

int tsp(int n, int graph[][n])
{
	int P[n-1];
	for(int i=1;i<n;i++)
	{
		P[i-1]=i;	
	}
	int mincost=10000;
	do
	{
		int cost=graph[0][P[0]];
		cost+=graph[P[n-2]][0];
		for(int i=0;i<n-2;i++)
		{
			cost+=graph[P[i]][P[i+1]];
		}
		if(cost<mincost)
		{
			mincost=cost;
		}
	}
	while(get_next_permutation(P,n-1));
	return mincost;
}


int* printPath(int n, int graph[][n])
{
	int P[n-1];
	for(int i=1;i<n;i++)
	{
		P[i-1]=i;
	}
	int* C=malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		C[i]=0;
	}
	long int mincost=99999999;
	do
	{
		int cost=graph[0][P[0]];
		cost+=graph[P[n-2]][0];
		for(int i=0;i<n-2;i++)
		{
			cost+=graph[P[i]][P[i+1]];
		}
		if(cost<mincost)
		{
			mincost=cost;
			for(int i=1;i<n;i++)
			{
				C[i]=P[i-1];
			}
		}
	}
	while(get_next_permutation(P,n-1));
	return C;
}


int getCost(int n, int graph[][n], int *P)
{
	int cost=0;
	for(int i=0;i<n-1;i++)
	{
		cost+=graph[P[i]][P[i+1]];
	}
	return cost+graph[P[n-1]][P[0]];
}


