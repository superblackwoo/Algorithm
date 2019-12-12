#include<stdio.h>
#define MAX_LINE 1024
#define MAX_NUM  1024

int read(int numbers[])  // read data in file, write data in number's' []
{
	int  number[MAX_LINE] = { 0 }, i = 0, j = 1;
	for (i = 0; i < MAX_LINE; i++) {	//��ʼ��
		number[i] = MAX_NUM;
	}  
	FILE *fp;
	if((fp = fopen("G:\\a������\\�㷨���������\\�㷨ʵ��\\ʵ��һ\\input3-data.txt","r")) == NULL){
		printf("Open file failed\n");
	}
	i = 0;
	printf("Before HeapSorting: ");
	while (fscanf(fp, "%d", &number[i])!=EOF) {  // file writ in the arrary number[] first
		printf("%d  ", number[i]);
		i++; //		the location of last 
	}
	for (i = 0; i < MAX_LINE; i++) {
		if (number[i] == MAX_NUM)
			break;
		numbers[j] = number[i];
		++j;  // j initlize j = 1. So j is The size of numbers[]
			  //                      
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
	if((fp = fopen("G:\\a������\\�㷨���������\\�㷨ʵ��\\ʵ��һ\\output3-data.txt","w")) == NULL){
		printf("Open file failed\n");
	}
	for(i=1;i<size;i++){
		fprintf(fp, "%d ", numbers[i]);
	}
	if (fclose(fp) != 0)
		printf("file can't close\n");
}

void swap(int numbers[], int i, int j)
{
	int temp;
	temp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = temp;
}

void HeapAdjust(int numbers[], int s, int n)
{
	int i, temp;
	temp = numbers[s];
	for(i=2*s; i<=n; i*=2){
		/* i��Զָ�������ӽڵ� */ 
		if(i<n && numbers[i] < numbers[i+1]) i++;	//�������������ӽڵ� iָ�����ӽڵ�
		if(temp >= numbers[i]) break;		//˫���Ѿ�����������ӽڵ� 
		numbers[s] = numbers[i];
		s = i;
	}
	numbers[s] = temp;
}

void Heapsort(int numbers[], int n)
{
	int i;
	for(i=n/2; i>0; i--){  //�������ϣ����ҵ��󹹽��󶥶� 
		HeapAdjust(numbers, i, n);
	}
	
	for (i=n; i>1; i--)	//���� ��һ��Ԫ�غ����һ��Ԫ�ػ��� 
	{
		swap(numbers, 1, i);  //��һ��Ԫ�غ����һ��Ԫ�ػ��� 
		HeapAdjust(numbers, 1, i-1);	//���������¹��� 
	 } 
}

int main()
{
	int i, numbers[MAX_LINE] = {-1,49,38,65,97,76,13,27}, high; // high is down flag
    high = read(numbers) - 1;
    Heapsort(numbers,high);
    write(numbers, high+1);
    printf("\n\nAfter  HeapSorting :");
    for(i=1;i<high+1;i++)
    	printf("%d  ",numbers[i]);
    printf("\n");
    /*int i, numbers[8] = {-1,49,38,65,97,76,13,27};
    printf("Before sorting :") ;
    for(i=1;i<9;i++)
    	printf("%d ",numbers[i]); 
    printf("\n");
    Heapsort(numbers,7);
    printf("After sorting :") ;
    for(i=1;i<9;i++)
    	printf("%d ",numbers[i]);
    printf("\n");*/
    return 0;
}
