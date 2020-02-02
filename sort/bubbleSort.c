#include<stdio.h>
template <class T>
T swap(T *a,T *b)
{
	T c;
	c = *a;
	*a = *b;
	*b = c;
}
int main()
{
	int a[10];
	int i,c,t;
	printf("imput 10 numbers:\n");
	for(i = 0;i < 4; i++)
	scanf("%d",&a[i]);
		printf("\n");
	for(c = 0;c < 4;c++)
		for(i = 0; i < 4-1-c; i++)
			if(a[i]>a[i+1])
			{
				swap(&a[i],&a[i+1]); 
			}
			printf("the socted numbers:\n");
	for(i = 0; i < 4; i++)
	printf("%d\t",a[i]);
	printf("\n");
	return 0; 
}
