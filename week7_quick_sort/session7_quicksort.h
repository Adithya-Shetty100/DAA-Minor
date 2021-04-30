//Header file for session6_quicksort.c

typedef struct Data {
	int id;
	int value;
} Data;

//Quick Sort
//Use Quick Sort algorithm to sort the array an of records by their id.
void QuickSort(Data* A, int l,int r);

//Hoare Partition
//Partitions the array on a pivot element and returns the index of the 
// pivot element in the partitioned array of records
int Partition(Data * A, int l,int r);

void swap(Data* ele1,Data* ele2);
