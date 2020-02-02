#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define max 10
void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
 } 
 void quicksort(int number[],int left,int right)
 {
 	int i,j,s;
 	if(left<right)
 	{
 		s = number[left];
 		i = left;
 		j = right+1;
 		while(1)
 		{
 			while(i+1 < 10 && number[++i] < s);
 			while(j-1 > -1 && number[--j] > s);
 			if(i >= j)
 			break;
 			swap(number[i],number[j]);
		 }
		 number[left] = number[j];
		 number[j] = s;
		 quicksort(number,left,j-1);
		 quicksort(number,j+1,right);
	 }
 }
 int main()
 {
	int number[max] = {0};
	for(int i = 0;i < 10; i++)
	number[i]=rand()%100;
	printf("排序前:\n");
	for(int i =0;i < 10; i++)
	printf("%d ",number[i]);
	printf("\n");
	quicksort(number,0,max-1);
	printf("排序后:\n");
	for(int i = 0;i < 10; i++)
	printf("%d ",number[i]);
 	return 0;
 }
