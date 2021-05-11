// Adithya B Shetty
// PES1UG19EC009

// Merges two sorted halfs of an array into a single sorted arraya,start
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
	int i,j,k;
	int n1=mid-start+1;
	int n2=end-mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=a[start + i];
	for(j=0;j<n2;j++)
		R[j]=a[mid+1+j];
	i=0;
	j=0;
	k=start;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}
	
// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end)
{
	if(start<end)
	{
		int mid=start+(end-start)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		mergeSortedHalfs(a,start,mid,end);
	}
}

