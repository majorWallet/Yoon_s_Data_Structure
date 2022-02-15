#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen)
{
	Queue buckets[BUCKET_NUM];
	int divfac = 1;
	int radix;

	for (int bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	for (int pos = 0; pos < maxLen; pos++)  //divfac, 즉 자리수를 증가시키는 것이 주된 목적
	{
		for (int di = 0; di < num; di++)  //di, 즉 버킷에 데이터를 대입하는 것이 주된 목적
		{
			radix = (arr[di] / divfac) % 10;
			Enqueue(&buckets[radix], arr[di]);
		}

		/*bi-> bucket의 갯수 index, di-> 버킷 하나에 연결된 node index*/
		for (int bi = 0, di = 0; bi < BUCKET_NUM; bi++)
		{
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		divfac *= 10;
	}
}

int main()
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}