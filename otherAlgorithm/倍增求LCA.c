#include<iostream>
#include<vector>
using namespace std;
const int maxn = 5e5+10;
vector<int> G[maxn];
int dep[maxn];
int f[maxn][21];
void deal_first(int nowp,int fa)  //预处理 
{
	dep[nowp] = dep[fa] + 1;    //当前结点深度为父节点深度+1 
	f[nowp][0] = fa;
	for(int i = 1;i <= 20; i++)
	{
		//结点nowp向根结点走2^i步,相当于nowp结点先向根节点走2^(i-1)步,再向上走2^(i-1)步
		f[nowp][i] = f[f[nowp][i-1]][i-1];   
	}
	for(int i=0;i<G[nowp].size();i++)
	if(G[nowp][i] != fa)        //与nowp相邻的结点不是父节点,则继续递归 
	{
		deal_first(G[nowp][i],nowp);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])    //先假设x是深度更大的结点 
	swap(x,y);
	for(int i=20;i >= 0; i--)   //先将较深的x结点向上跳到与y结点同一深度 
	{
		if(dep[f[x][i]] >= dep[y])
		x = f[x][i];
		if(x == y)
		return x;
	}
	for(int i = 20; i >= 0; i--)   //x与y结点一起跳到最近公共祖先的子节点 
	{
		if(f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];     //返回最近公共祖先 
}
int dis(int x,int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x,y)]; 
}
int main()
{
	int n,q;
	cin>>n;
	int x,y;
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	 } 
	 deal_first(1,0);
	 cin>>q;
	 while(q--)
	 {
	 	cin>>x>>y;
	 	cout<<dis(x,y)<<endl;
	 }
	return 0;
} 	
