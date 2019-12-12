// 快速排序C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string>

#define MAX_LINE 1024
#define MAX_NUM  1024
int read(int numbers[])
{
	int  number[MAX_LINE] = { 0 }, i = 0, j = 1;
	for (i = 0; i < MAX_LINE; i++) {	//初始化
		number[i] = MAX_NUM;
	}  
	FILE *fp;
	if((fp = fopen("G:\\a大三上\\算法分析与设计\\算法实验\\实验一\\input1-data.txt","r")) == NULL){
		printf("Open file failed\n");
	}
	i = 0;
	printf("Before QuickSorting: ");
	while (fscanf(fp, "%d", &number[i])!=EOF) {  // file writ in arrary number[] first
		printf("%d  ", number[i]);
		i++;
	}
	for (i = 0; i < MAX_LINE; i++) {
		if (number[i] == MAX_NUM)
			break;
		numbers[j] = number[i];
		++j;  // The size of numbers[]
	}
	//for (i = 0; i < j; i++)
		//printf("*%d ", numbers[i]);
	//printf("\n");
	if (fclose(fp) != 0)
		printf("file can't close\n");
	return j;
}
void write(int numbers[], int size)  // size: the size of numbers[]
{
	int i;
	FILE *fp;
	if((fp = fopen("G:\\a大三上\\算法分析与设计\\算法实验\\实验一\\output1-data.txt","w")) == NULL){
		printf("Open file failed\n");
	}
	for(i=1;i<size;i++){
		fprintf(fp, "%d ", numbers[i]);
	}
	if (fclose(fp) != 0)
		printf("file can't close\n");
}

int partition(int number[8], int low, int high) {
	number[0] = number[low];
	int pkey = number[0];
	while (low < high) {
		while (low < high && number[high] >= pkey) high--;
		number[low] = number[high];
		while (low < high && number[low] <= pkey) low++;
		number[high] = number[low];
	}
	number[low] = number[0];
	//printf("partition done \n");
	return low;  //返回位置
}
void qsort(int number[8], int low, int high) { //递归进行排序
	if (low < high) {
		int pkey = partition(number, low, high);
		//for (int i = 0; i < 8; i++) {
			//printf("d ");
			//printf("%d \n", number[i]);
		//}
		qsort(number, low, pkey - 1);
		qsort(number, pkey + 1, high);
	}
	//printf("qsort done \n");
}
void QuickSort(int number[], int high) {
	qsort(number, 1, high);
}
int main(int argc, _TCHAR* argv[])
{
	int numbers[MAX_LINE] = { 0 }, high, i;
	//FILE* fp;
	//*fp = read();
	high = read(numbers) -1;
	printf("high: %d \n\n\n",high);
	QuickSort(numbers, high);
	write(numbers,high+1);
	printf("After  QuickSorting: ");
	for (i = 1; i < high+1; i++) {
		printf("%d  ", numbers[i]);
	}
	return 0;
}

