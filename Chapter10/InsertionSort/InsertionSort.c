#include <stdio.h>

void InsertSort(int arr[], int n)
{
	int insData;
	int insIdx;

	for (int i = 1; i < n; i++)
	{
		insData = arr[i];
		insIdx = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
			{
				insIdx = ++j;
				break;
			}
		}
		arr[insIdx] = insData;
	}
}

int main()
{
	int arr[5] = { 5, 3, 2, 4, 1 };

	InsertSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}