#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	int base = (target - ar[first]) / (ar[last] - ar[first]) * (last - first) + first;
	if (!(ar[first] <= target && target <= ar[last]))
		return -1;
	else if (ar[base] == target)
		return base;
	else if (ar[base] > target)
		return BSearchRecur(ar, first, base - 1, target);
	else
		return BSearchRecur(ar, base + 1, last, target);
}

int main()
{
	int arr[] = { 1, 3, 5 ,7, 9 };
	int idx;

	idx = BSearchRecur(arr, 1, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d\n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d\n", idx);

	return 0;
}