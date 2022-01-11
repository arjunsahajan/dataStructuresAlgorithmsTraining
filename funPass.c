#include <stdio.h>

void fun(int [], int);

void fun(int arr[], int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%d\n", arr[i]);
		i += 1;
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};

	fun(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}

