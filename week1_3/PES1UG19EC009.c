// Header file for the implementation of Bubble sort and
// Selection sort algorithms

// Check if an array is sorted.
// Return 1 if the array is sorted, 0 otherwise.
int isSorted(int *a, int n)
{
	for(int i=0;i<n-1;++i)
	{
		if(a[i]>a[i+1])
			return 0;
	}
	return 1;
}

//Consider an array a[0] to a[n-1]. 
//For each element a[i], which is greater than or equal to all the
// elements from a[0] thru a[i-1], move a[i] to a[k] where all the elements from
// a[i+1] thru a[k] are less than a[i] and either k=n-1 or a[k+1] >= a[i].
//Essentially, one pass of bubbling larger elements from left to right.
//Eg: Array 1 4 3 2 6 5 is transformed to 1 3 2 4 5 6.
void bubblePass(int *a, int n)
{
	int temp;
	for(int i=0;i<n-1;++i)
	{
		if(a[i]>a[i+1])
		{
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
		}	
	}		
}

//Implement Bubble sort using bubblePass() declared above.
void bubbleSort(int *a, int n)
{
	for(int i=0;i<n-1;++i)
	{
		if(isSorted(a,n))
			break;
		bubblePass(a,n-i);
	}
}

//Find the minimum number of BubblePasses required to sort by Bubble sort
// algorithm. Note that a sorted array does not require any bubblePasses. 
//Use isSorted() function before calling BubblePass().
int numBubblePasses(int *a, int n)
{
	int count=0,i=n;
	while(!isSorted(a,n))
	{
		bubblePass(a,i);
		i--;
		count++;
	}
	return count;
}

//Find the offset (that is, index) of the maximum element in an array.
//In case of multiple occurrences of the maximum element,
// return the largest offset (that is, rightmost index).
int maxIndex(int *a, int n)
{
	int max=0;
	for(int i=0;i<n;++i)
	{
		if(a[i]>=a[max])
			max=i;
	}
	return max;
}

//Consider an array a[0] to a[n-1].
//Let i be the largest offset of the maximum element in the array.
//Swap a[i] with a[n-1] only if i < n-1.
//Use maxIndex() declared above.
void swapWithMax(int *a, int n)
{
	int i=maxIndex(a,n);
	if(i<n-1)
	{
		int temp=a[n-1];
		a[n-1]=a[i];
		a[i]=temp;
	}
}

//Implement Selection sort using maxIndex() and swapWithMax() declared above.
void selectionSort(int *a, int n)
{
	for(int i=0;i<n-1;++i)
	{
		swapWithMax(a,n-i);
	}
}

//Find the number of swaps in selectionSort() declared above.
int numSwaps(int *a, int n)
{
	int count=0,k;
	for(int i=0;i<n-1;++i)
	{
		k=maxIndex(a,n-i);
		if(k<n-i-1)
		{
			int temp=a[n-i-1];
			a[n-i-1]=a[k];
			a[k]=temp;
			count++;
		}
	}
	return count;
}



