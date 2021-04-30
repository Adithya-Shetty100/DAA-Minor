#include <stdio.h>
#include <stdlib.h>
#include "session7_quicksort.h"
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; 
    return t;
}

int main(){
        FILE *fptr = fopen("session7_quicksort_ip4.txt","r"); 
        
        if(fptr==NULL)
	{
		printf("Cant open file");
		return 0;
	}
        long long int numtrials = 0;
        
        fscanf(fptr, "%lld", &numtrials);
        //printf("%lld",numtrials);
        Data *arr = malloc(sizeof(Data)*numtrials); 
        for(long long int k=0; k<numtrials; ++k){
                fscanf(fptr,"%d",&arr[k].id); 
                
                fscanf(fptr,"%d",&arr[k].value);
                
        }

        
        FILE *fp1=fopen("op_ip4.txt","w");
	if(fp1==NULL)
	{
		printf("Cant open file");
		return 0;}
        
        struct timespec start, end; 

        clock_gettime(CLOCK_REALTIME, &start); 
        QuickSort(arr,0,numtrials-1);
        clock_gettime(CLOCK_REALTIME, &end);
    
        for(long long int i=0;i<numtrials;i++)
        {
        	
        	fprintf(fp1,"%d %d\n",arr[i].id,arr[i].value);
        }
        
             
        printf("%lf sec spent on Quick Sort()\n",time_elapsed(start, end));
        fprintf(fp1,"%lf sec spent on Quick Sort()\n",time_elapsed(start, end)); // data is written into file only after file closes fclose, till then stored in buffer. Sometimes u can even use f1.flush() before fclose
        

	
	fclose(fp1);
        fclose(fptr);
   
    return 0; 
}
