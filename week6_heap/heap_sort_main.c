#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "heapSort.h"

double time_elapsed(struct timespec start, struct timespec end);
int _isSorted(int *a, int n);
void printArray(int *a, int n);

int main(int argc, char const *argv[])
{
    FILE *fp1 = fopen("session5_sort_ip_rand032k.txt", "r"); 
    struct timespec start, end; 
    int n;
    fscanf(fp1,"%d",&n);
    int A[n];
    for(int i=0;i<n;i++){
        int m;
        fscanf(fp1,"%d",&A[i]);
        fscanf(fp1,"%d",&m);
    }
    clock_gettime(CLOCK_REALTIME, &start); 
    heapSort(A, n);
    clock_gettime(CLOCK_REALTIME, &end);
    if (1 == _isSorted(A, n))
    {	
    	FILE *fp1=fopen("op_ip1.txt","w");
	if(fp1==NULL)
	{
		printf("Cant open file");
		return 0;}
	
	for(int i=0;i<n;i++)
        {
        	fprintf(fp1,"%d %d\n",A[i],m);
        	
        }
        printf("%lf sec spent on test1 of heapSort()\n", time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of heapSort()\n");
    }
    return 0;
}

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);           
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; 
    return t;
}

int _isSorted(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i){
        if (a[i] > a[i + 1])
            return 0;
    return 1;
    }
}


