#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include "session11_horspools.h"


double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; 
    return t;
}


void main()
{
	FILE* fptr=fopen("session11_horspools_ip3.txt","r");
	FILE* fop=fopen("horspool_op3.txt","w");
        
        struct timespec start, end; 
        clock_gettime(CLOCK_REALTIME, &start); 
	
	char text[1048576];
	int t;
	fscanf(fptr,"%[^\n]s",text);
	fscanf(fptr, "%d", &t);
	//printf("%s",text);
	char *patterns[100];
	char p[1048576];
	int l;
	char *x;
	//printf("t=%d\n",t);
	for(int i=0;i<t;i++)
	{
		fscanf(fptr, "%s", p);
    		l = strlen(p);
    		// l+1 to store "\0"
    		x = (char *)malloc(l + 1);
    		strcpy(x, p);
    		patterns[i] = x;
		//printf("%d\n",3);
	}
	
	
	//printf("%s\n",patterns[0]);
	//printf("%s\n",patterns[1]);
	
	int *occur_table=(int*)malloc(t*sizeof(int));
	occur_table=horspools_strmatch_patterns(text, patterns, t);
	
	for(int i=0;i<t;i++)
	{
		fprintf(fop,"%d\n",occur_table[i]);
		//printf("%d\n",occur_table[i]);
	}
			
	clock_gettime(CLOCK_REALTIME, &end);
	fprintf(fop,"%lf sec.\n",time_elapsed(start, end)); 
	fclose(fptr);
	fclose(fop);
	//printf("File closed");
}
