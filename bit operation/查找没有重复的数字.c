#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int a[10];
	for(int i=0;i<9;i++)
	cin>>a[i];
	int temp=a[0];
	for(int i=1;i<9;i++)
	temp ^= a[i];  //最后只剩下没有重复的数字 
	cout<<temp<<endl;
	return 0;
 } 
