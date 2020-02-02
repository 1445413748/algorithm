#include<iostream>
#include<cstdio>
using namespace std;
#define max 100000
int h[max];
int n;
void swap(int i,int t)
{
	int a;
	a = h[i];
	h[i] = h[t];
	h[t] = a;
	return ;
}
//向下调整 
void siftdown(int i)    
{
	int flag = 0;
	int t;
	while(i*2 <= n && flag == 0)
	{
		if(h[i] < h[i*2])       //>表示建立最小堆,<表示建立最大堆 
		t = i*2;
		else
		t = i;
		if(i*2 + 1 <= n)
		if(h[t] < h[i*2+1])          // //>表示建立最小堆,<表示建立最大堆  
		t = i*2+1;
		if(i != t)
		{
			swap(i,t);
			i = t;
		 } 
		 else
		 flag = 1;
	} 
}
//向上调整 
void siftup(int i)
{
	int flag = 0;
	if(i == 1) return ;
	while(i != 1 && flag == 0)
	{
		if(h[i] > h[i/2])     //>表示建立最小堆,<表示建立最大堆 
		swap(i,i/2);
		else
		flag = 1;
		i = i/2;
	}
}

//建立堆 
void creat()
{
	for(int i = n/2;i >= 1; i--)
	siftdown(i);
}
//删除堆顶最小元素 
int deletemin()
{
	int t = h[1];
	swap(1,n);
	n--;
	return t;
}
//堆排序     
void heapsort()
{
	while(n > 1)
	{
		swap(1,n);
		n--;
		siftdown(1);
	} 
}
int main()
{
	int num;
	cin >> num;
	n = num;
	
	//输入一棵完全二叉树 
	for(int i = 1;i <= num; i++)
	cin>>h[i];
	creat();  //建立堆 
	heapsort();  //堆排序 
	for(int i = 1;i <= num; i++)
	cout<<h[i]<<endl;
	return 0;
}
