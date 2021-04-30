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
        FILE *fptr = fopen("session7_quicksort_ip1.txt","r"); 
        
        if(fptr!=NULL)
	{
		printf("Cant open file");
		//return 0;
	}
        int numtrials = 0;
        printf("%d",numtrials);
        fscanf(fptr, "%d", &numtrials);
        printf("%s","hi bo");
        Data *arr = malloc(sizeof(Data)*numtrials); 
        for(int k=0; k<numtrials; ++k){
                fscanf(fptr,"%d",&arr[k].id); 
                //printf("%s","h9");
                fscanf(fptr,"%d",&arr[k].value);
                //printf("%s","h1");
        }
        
        FILE *fp1=fopen("op_ip1.txt","w");
	if(fp1==NULL)
	{
		printf("Cant open file");
		return 0;}
        
        struct timespec start, end; 

        clock_gettime(CLOCK_REALTIME, &start); 
        QuickSort(arr, numtrials);
        clock_gettime(CLOCK_REALTIME, &end);
    
        for(int i=0;i<numtrials;i++)
        {
        	
        	fprintf(fp1,"%d %d\n",arr[i].id,arr[i].value);
        	//printf("%s","h2");
        }
        
             
        fprintf(fp1,"%lf sec spent on Quick Sort()\n",time_elapsed(start, end)); // data is written into file only after file closes fclose, till then stored in buffer. Sometimes u can even use f1.flush() before fclose
        

	
	fclose(fp1);
        fclose(fptr);
   
    return 0; 
}
