//Header file for session7_sort.c
#include "session5_sort.h"

//Insertion Sort
//Sorts the array of Records on the serialnumber field using the Insertion Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int InsertionSort(Record* A, int n)
{
	long int comparsion_count=0;
	for(int i=1; i<n; ++i)
	{
		Record temp=A[i];
		int j=i-1;
		while(j>=0 && ++comparsion_count && A[j].serialnumber>temp.serialnumber)
		{
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=temp;
	}
	return comparsion_count;
}

//Bubble Sort
//Sorts the array of Records on the serialnumber field using the Bubble Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int BubbleSort(Record* A, int n)
{
	long int comparsion_count=0;
	for(int i=0;i<n-1;++i)
	{
		int noswaps=1;
		for(int j=0; j<n-1-i; ++j)
		{
			++comparsion_count;
			if(A[j].serialnumber>A[j+1].serialnumber)
			{
				Record temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				noswaps=0;
			}
		}
		if(noswaps)
		break;
	}
	return comparsion_count;
}

//Selection Sort
//Sorts the array of Records on the serialnumber field using the Selection Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int SelectionSort(Record* A, int n)
{
	long int comparsion_count=0;
	for(int i=0;i<n-1;++i)
	{
		int min=i;
		for(int j=i+1;j<n;++j)
		{
			if(++comparsion_count && A[j].serialnumber < A[min].serialnumber)
			{
				min=j;				
			}
		}
		Record temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}
	return comparsion_count;

}

//Merge sort will be for next lab sessions
//Merge Sort
//Sorts the array of Records on the serialnumber field using the Merge Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
//long int MergeSort(Record* A, int n);

// Quick sort will be for next lab sessions
//Quick Sort
//Sorts the array of Records on the serialnumber field using the Quick Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
//long int QuickSort(Record* A, int n);
