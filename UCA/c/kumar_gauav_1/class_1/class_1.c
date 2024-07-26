// selection sort -> selection sort is sorting algorithim were we solved using 
// pivot index take a minimum and the set in left 

#include<stdio.h>
#include<assert.h>

void exch(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selection_sort(int arr[],int n) // time complexity every input in O(n^2):
{
	for(int i = 0; i < n; i++)
	{
		int min = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[min]>arr[j]) min = j;
		}
		exch(arr,i,min);
	}
}

void test_simple_input()
{
	int n = 5;
	int arr[] = {3,1,5,2,4};
	int expected_output[] = {1,2,3,4,5};
	selection_sort(arr,n);
	for(int i = 0; i < n; i++)
	{
		assert(arr[i]==expected_output[i]);
	}
}

int main(){
	test_simple_input();
}

