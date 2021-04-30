#include<stdio.h>
#include<stdlib.h>

void DistributionCountingSorting(int* A, int n)
{
	int min=A[0];
	int max=A[0];
	int i,j;
	
	for(i=1;i<n;i++)
	{
		if(min>A[i])
			min=A[i];
		else if(max<A[i])
			max=A[i];		
	}
	
	int* D=(int*)malloc((max-min)*sizeof(int));
	
	for(j=0;j<=(max-min);j++)
	{	D[j]=0;
		//printf("D=%d\n",D[j]);
	}
		

	for(j=0;j<=(n-1);j++)
	{
		D[A[j]-min]=D[A[j]-min]+1;
	}
		
	
	for(j=1;j<=(max-min);j++) //cumulative
		D[j]+=D[j-1];


	int *S=(int*)malloc(n*sizeof(int));
	for(i=(n-1);i>=0;i--)
	{
		j=A[i]-min;    //both j and i values are different :)
		S[D[j]-1]=A[i];
		//printf("inside=%d\n",S[D[j]-1]);
		D[j]=D[j]-1;
		
		
	}
	

	
	for (i = 0; i<n; i++)
        {
        	A[i] = S[i];
        	//printf("sorted= %d\n",A[i]);
        }
	free(S);



}
