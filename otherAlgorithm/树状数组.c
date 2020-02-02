#include<iostream>
#include<cstring>
using namespace std;
int lowbit(int n)
{
	return n-(n&(n-1));
}
void updata(int n,int i,int v,int c[])
{
	for(int k=i;k<=n;k+=lowbit(k))
	{
		c[k]+=v;
	}
}
int getsum(int c[],int i)
{
	int sum=0;
	for(int k=i;k>=1;k-=lowbit(k))
	{
		sum += c[k];
	}	return sum;
}
int main()
{
	int c[10];
	int arr[]={1,2,3,4,5,6,7,8,9};
	memset(c,0,sizeof(c));
	for(int i=0;i<9;i++)
	updata(10,i+1,arr[i],c);
	cout<<getsum(c,7)-getsum(c,5)<<endl;
	return 0;
}
