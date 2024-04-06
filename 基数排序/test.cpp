#include <stdio.h>
#include <stdlib.h>

// ��������/Ͱ����
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		printf("calloc fail\n");
		return;
	}

	// ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	// ����
	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
}