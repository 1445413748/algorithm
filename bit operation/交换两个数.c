#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int x,y;
	while(cin>>x>>y)
	{
		x=x^y;
		y=x^y;
		x=x^y;
		cout<<"x="<<x<<",y="<<y<<endl; 
	}
	return 0;
}
