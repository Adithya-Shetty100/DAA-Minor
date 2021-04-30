#include<stdio.h>
#include"heapSort.h"

Heap buildMaxHeap(int *const a, int n)
{
	Heap h;
	h.a=a;
	h.size=n;
	int start=h.size/2-1;
	for(int i=start;i>=0;i--)
		maxHeapify(h,i);
	return h;		
}	

void maxHeapify(Heap h, int idx)
{
	int temp;
	int l=2*idx+1;
	int r=2*idx+2;
	if(l<h.size)
	{
		if(r<h.size && h.a[r] > h.a[l])
		{
			l++;
		}
		if(h.a[l] > h.a[idx])
		{
			temp=h.a[idx];
			h.a[idx]=h.a[l];
			h.a[l]=temp;
			maxHeapify(h,l);
		}
	}
}

void heapSort(int *const a, int n)
{
	int temp;
	Heap h=buildMaxHeap(a,n);
	for(int j=h.size-1;j>=0;j--)
	{
		temp=h.a[0];
		h.a[0]=h.a[j];
		h.a[j]=temp;
		h.size--;
		maxHeapify(h,0);
	}
}

