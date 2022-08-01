#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
#include<stdlib.h>
int arr[100000];
int _count;
using namespace std;
void SetData(int arr[], int iCount)
{
	srand((unsigned int)time(NULL));
	for (int iCnt = 0; iCnt < iCount; iCnt++)
	{
		arr[iCnt] = rand() % iCount;
	}
}

void DataPrint(int arr[], int iCount)
{
	for (int iCnt = 0; iCnt < iCount; iCnt++)
	{
		if (iCnt % 15 == 0)
		{
			cout << endl;
		}

		printf("%d ", arr[iCnt]);
		
	}
}

void Swap(int arr[],int a,int b)
{
	int q = arr[a];
	arr[a] = arr[b];
	arr[b]=q;

}

int Partition(int low, int high)
{
	int i = low;
	int j = high;
	int pivot = arr[i];
	while(i<j){
		while (arr[i] <= pivot) { i++; }
		while (arr[j] > pivot) { j--; }
	if (i < j)
		Swap(arr, i, j);
	}
	Swap(arr, j, low);
	return j;
}

void QuickSort(int low,int high)
{
	if (low < high)
	{
		int pivot = Partition(low, high);
		QuickSort(low, pivot - 1);
		QuickSort(pivot + 1, high);
	}
}


int main(void)
{

	int aac[5] = { 1,9,7,5,3 };
	cin >> _count;
	SetData(arr, _count);
	int j = Partition(0, _count - 1);
	QuickSort(0, _count - 1);
	DataPrint(arr, _count);

	return 0;
}

//
//clock_t sTime, eTime;
//sTime = clock();
//eTime = clock() - sTime;
//printf("\n\ttime => [%ld,%8.3f] => ", eTime, eTime / (double)CLK_TCK);
//
