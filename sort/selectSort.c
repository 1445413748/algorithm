
#include<stdio.h>
const int N = 5; 
void sort(int array[],int n)
{
	int i,j,k,t;
	for(i = 0;i <n-1; i++)
	{
		k=i;
		for(j = i+1; j < n; j++)
			if(array[j]>array[k])
			k=j;
			t=array[k];array[k]=array[i];array[i]=t;
	}
}
int main()
{
	void sort(int array[],int n);
	int a[N],i;
	printf("enetr array:\n");
	for(i = 0; i < N; i++)
	scanf("%d",&a[i]);
	sort(a,N);
	printf("The sorted array:\n");
	for(i = 0;i < N; i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}
