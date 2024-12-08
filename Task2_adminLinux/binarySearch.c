#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] < key)
			low = mid + 1;

		else
			high = mid - 1;

	}

	return -1;

}


int main(void)
{
	int *ptr;
	int n, data;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	ptr = (int*)calloc(n,sizeof(int));
	if(ptr == NULL)
	{
		printf("Memory Allocation Failed\n");
		exit(0);
	}
	else
	{
		printf("Memory Successfully Allocated\n");
	}
	printf("Enter array elements: \n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&ptr[i]);
	}
	printf("Array elements: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", ptr[i]);
	}
	printf("Enter the number to be searched for: ");
	scanf("%d", &data);
	int result = binarySearch(ptr, 0, n - 1, data);
	if (result == -1)
		printf("Element is not found in the array\n");
	else
		printf("Element is fount at index %d\n",result);
	free(ptr);
}
