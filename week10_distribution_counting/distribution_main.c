#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "daalab10.h"


double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; 
    return t;
}


void main()
{
	FILE* fptr=fopen("session10_dcs_ip4_1million_ints_under_10million.txt","r");
	FILE* fop=fopen("dcount_op4.txt","w");
        
        struct timespec start, end; 
        clock_gettime(CLOCK_REALTIME, &start); 
	
	int n;
	fscanf(fptr, "%d", &n);
	int *A=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		fscanf(fptr, "%d", &A[i]);
	}
	
	DistributionCountingSorting(&A[0],n);   //or just (A,n)
	

	for(int i=0;i<n;i++)
	{
		fprintf(fop,"%d\n",A[i]);
	}
			
	clock_gettime(CLOCK_REALTIME, &end);
	fprintf(fop,"%lf sec.\n",time_elapsed(start, end)); 
	fclose(fptr);
	fclose(fop);
}
