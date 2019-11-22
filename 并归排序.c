#include<stdio.h>
#define MAX_LINE 1024
#define MAX_NUM 1024

int read(int numbers[])  // read data in file, write data in number's' []
{
	int  number[MAX_LINE] = { 0 }, i = 0, j = 1;
	for (i = 0; i < MAX_LINE; i++) {	//初始化
		number[i] = MAX_NUM;
	}  
	FILE *fp;
	if((fp = fopen("G:\\a大三上\\算法分析与设计\\算法实验\\实验一\\input2-data.txt","r")) == NULL){
		printf("Open file failed\n");
	}
	i = 0;
	printf("Before MergeSorting: ");
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
	if((fp = fopen("G:\\a大三上\\算法分析与设计\\算法实验\\实验一\\output2-data.txt","w")) == NULL){
		printf("Open file failed\n");
	}
	for(i=1;i<size;i++){
		fprintf(fp, "%d ", numbers[i]);
	}
	if (fclose(fp) != 0)
		printf("file can't close\n");
}
void merge(int SR[], int TR[], int i, int m, int n)
{
	
    int j, k;
    for(k=i,j=m+1;i<=m&&j<=n;k++){  // merge SR[i..m]  SR[m+1..n] to TR[i..n]
        if(SR[i]<=SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    /* i or j will always small than m or n */
    for( ;i<=m;i++)
        TR[k++] = SR[i];
    for( ;j<=n;j++)
        TR[k++] = SR[j]; 
}

void msort(int SR[], int TR1[], int s, int t)
{
    int m, TR2[MAX_LINE];
    if(s==t) TR1[s] = SR[s];
    else{
        m = (s+t)/2;
        msort(SR, TR2, s, m);	//SR左边有序 
        msort(SR, TR2, m+1, t);		//SR右边有序 	 
        merge(TR2, TR1, s, m, t);
    }
}

int main()
{
	int i, numbers[MAX_LINE] = {0}, high; //最后一个数组元素下标 
	high = read(numbers) - 1;
    msort(numbers,numbers,1,high);
    write(numbers, high+1);
    printf("\n\n");
    printf("After MergeSorting :");
    for(i=1; i < high+1; i++)
    	printf("%d  ",numbers[i]);
    	
    /*int i, numbers[7] = {49,38,65,97,76,13,27};
    printf("Before MergeSorting :");
    for(i=0;i<7;i++)
    	printf("%d ",numbers[i]); 
    msort(numbers,numbers,0,6);
    printf("\n\n");
    printf("After MergeSorting :");
    for(i=0;i<7;i++)
    	printf("%d ",numbers[i]);*/
    return 0;
}
