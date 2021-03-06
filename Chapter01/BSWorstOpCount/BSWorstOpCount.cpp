#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len;
	int mid;
	int opCnt = 0;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (ar[mid] == target)
			return mid;
		else
		{
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
		opCnt++;
	}
	printf("?񱳿??? Ƚ??: %d\n", opCnt);
	return -1;
}

int main()
{
	int arr1[500] = {0, };
	int arr2[5000] = { 0, };
	int arr3[50000] = { 0, };
	int idx;

	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
		printf("Ž?? ????\n");
	else
		printf("Ž?? ???? ?ε???: %d\n\n", idx);

	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 2);
	if (idx == -1)
		printf("Ž?? ????\n");
	else
		printf("Ž?? ???? ?ε???: %d\n\n", idx);

	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);
	if (idx == -1)
		printf("Ž?? ????\n");
	else
		printf("Ž?? ???? ?ε???: %d\n\n", idx);

	return 0;
}