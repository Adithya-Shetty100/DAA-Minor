#include "session7_quicksort.h"
#include <stdlib.h>
#include <stdio.h>

int Partition(Data* arr,int n){
    int p;
    int i,j;
    int l=0;
    int r=n-1;
    p=arr[l].id;
    i=l;
    j=r+1;
    int temp;
    int temp2;
    do{
        do{
            i++;

        }while(arr[i].id<p);
        do{
            j--;
        }while(arr[j].id>p);
        
        if(i<j)
        {
		temp=arr[i].id;
	    	arr[i].id=arr[j].id;
	    	arr[j].id=temp;
	    	temp2=arr[i].value;
	    	arr[i].value=arr[j].value;
	    	arr[j].value=temp2;
	}
        
    }while(i<j);
    
    
    /*temp=arr[i].id;
    arr[i].id=arr[j].id;
    arr[j].id=temp;
    temp2=arr[i].value;
    arr[i].value=arr[j].value;
    arr[j].value=temp2;*/
    
    temp=arr[l].id;
    arr[l].id=arr[j].id;
    arr[j].id=temp;
    temp2=arr[l].value;
    arr[l].value=arr[j].value;
    arr[j].value=temp2;
    
    return j;
}
void QuickSort(Data* arr,int n){
    int s;
    int l=0;
    int r=n-1;
    
    if(l<r){
        s=Partition(arr,n);
        //printf("%s","h3");
        
        Data *b = malloc(sizeof(Data)*(s)); 
        Data *c = malloc(sizeof(Data)*(n-s-1)); 
        for(int i=0;i<s;i++)
        {
             b[i].id=arr[i].id;
             b[i].value=arr[i].value;
        }
        for(int i=s+1,j=0;i<n;i++,j++)
        {
             c[j].id=arr[i].id;
             c[j].value=arr[i].value;
        }
        //printf("%s","h4");
              
        QuickSort(b,s);
	for(int i=0;i<s;i++)
        {
             arr[i].id=b[i].id;
             arr[i].value=b[i].value;
        }
        QuickSort(c,(n-s-1));
	for(int i=s+1,j=0;i<n;i++,j++)
        {
             arr[i].id=c[j].id;
             arr[i].value=c[j].value;
        }
        //printf("%s","h5");
    }
}
