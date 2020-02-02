#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4+10;
struct Edge{
	int x;
	int y;
	int z;
}a[maxn];
bool cmp(Edge a,Edge b)
{
	return a.z<b.z;
}
int prt[maxn],n,m;
int ans ;
int flag;    //能否形成最小生成树的标志 
int Getfather(int x)   //查找祖先 
{
	if(prt[x] == x) 
	return x;
	prt[x] = Getfather(prt[x]);
	return prt[x];
}
void Kruskal()
{
	int f1,f2,k;
	for(int i = 1; i <= n; i++)
	prt[i] = i;
	for(int i = 1; i <= m; i++)
	{
		f1 = Getfather(a[i].x);
		f2 = Getfather(a[i].y);
		if(f1 != f2)
		{
			ans += a[i].z;
			k++;
			prt[f1] = f2;   //合并不相同的两个集合 
			if(k == n-1)
			break;
		}
	}
	if(k < n-1)
	{
		cout<<"Impossible"<<endl;
		flag = 1;
	}
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= m; i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	 } 
	 sort(a+1,a+1+m,cmp);
	 Kruskal();
	 if(!flag)
	 {
	 	cout<<ans<<endl;
	 }
	return 0;
}
