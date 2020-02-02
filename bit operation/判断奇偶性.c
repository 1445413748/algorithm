#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
	if(n&1==1)
	cout<<"奇数.\n";
	else
	cout<<"偶数.\n";
	}
	return 0;
}
