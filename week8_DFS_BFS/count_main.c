#include <stdio.h>
#include <stdlib.h>
//#include "session8_dfsbfs.h"
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; 
    return t;
}

int main(){
        FILE *fptr = fopen("session8_dfsbfs_ip1.txt","r"); 
        
        if(fptr==NULL)
	{
		printf("Cant open file");
		return 0;
	}
        int n,k = 0;
        
        fscanf(fptr, "%d", &n);//trials
        //printf("%lld",numtrials);
        FILE *fp1=fopen("op_ip1.txt","w");
		if(fp1==NULL)
		{
			printf("Cant open file");
			return 0;}
        
        for(int i=0;i<n;i++)
        {
        	
        	
        	fscanf(fptr, "%d", &k); //order
        	int **arr=(int**)malloc(k*sizeof(int*));
        	for(int j=0;j<k;j++)
        	{
        		arr[j]=(int*)malloc(k*sizeof(int));
        	}
        	
	
		int count=count_components_dfs(arr,n);
		
		
		/*struct timespec start, end; 

		clock_gettime(CLOCK_REALTIME, &start); 
		//
		clock_gettime(CLOCK_REALTIME, &end);
	    
		for(int j=0;j<numtrials;i++)
		{
			
			fprintf(fp1,"%d %d\n",arr[i].id,arr[i].value);
		}*/
        
        }
        
        
             
        //printf("%lf sec spent on Quick Sort()\n",time_elapsed(start, end));

	
	fclose(fp1);
        fclose(fptr);
   
    return 0; 
}
