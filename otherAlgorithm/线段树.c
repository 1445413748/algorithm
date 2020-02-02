#include<iostream>
using namespace std;
const int maxn = 1e5+5;
int n,m;
int a[4*maxn]; 
void change(int k,int l,int r,int x,int v)
{
	if(x<l || x>r)return;   //x的位置与当前区间毫无交集 
	if(l==r && l==x)   //当前结点为x的所在的叶子节点 
	{
	a[k]=v;    
	return ;
	}
	int mid=l+r>>1;
	change(2*k,l,mid,x,v);      //修改左子区间 
	change(2*k+1,mid+1,r,x,v);  //修改右子区间 
	a[k]=a[2*k]+a[2*k+1];       //更新相关的值 
}
int query(int k,int l,int r,int x,int y)
{
	if(x>r || y<l)return 0;    //当前区间与询问区间毫无交集 
	if(l>= x && r<=y)     //询问区间完全包含当前区间 
	return a[k];
	
	int mid=l+r>>1;
	int left=query(2*k,l,mid,x,y);
	int right=query(2*k+1,mid+1,r,x,y);
	long long ans=left+right;
	return ans;
 } 
int main()
{
	cin>>n>>m;
	int k,l,r;
	for(int i=1;i<=m;i++)
	{
		cin>>k>>l>>r;
		if(k==0)
		change(1,1,n,l,r);
		else
		cout<<query(1,1,n,l,r)<<endl;
	}
	return 0;
}
