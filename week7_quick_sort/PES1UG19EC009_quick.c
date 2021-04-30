#include<stdio.h>
#include<stdlib.h>
#include "session7_quicksort.h"

void swap(Data* ele1,Data* ele2){
    int temp,temp2;
    temp=ele1->id;
    ele1->id=ele2->id;
    ele2->id=temp;
    
    temp2=ele1->value;
    ele1->value=ele2->value;
    ele2->value=temp2;
}

int Partition(Data* arr,int l,int r){
    int p;
    int i,j;
    p=arr[l].id;
    i=l;
    j=r+1;
    do{
        do{
            i++;

        }while(arr[i].id<p);
        
        do{
            j--;
        }while(arr[j].id>p);
        swap(&arr[i],&arr[j]);
    }while(i<j);
    swap(&arr[i],&arr[j]);
    swap(&arr[l],&arr[j]);
    return j;
}

void QuickSort(Data* arr,int l,int r){
    int s;
    if(l<r){
        s=Partition(arr,l,r);
        
        
        QuickSort(arr,l,s-1);
        QuickSort(arr,s+1,r);
        
    }
}



