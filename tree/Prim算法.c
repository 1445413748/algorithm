#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e4+10;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn];
int dis[maxn];  //表示点i到当前生成树中的点有连边的边长最小值 
int vst[maxn];   //标记点i是否加入最小生成树中 
int ans=0,n,m;
void read()        //读入数据,构建图 
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	g[i][j] = INF;  
	int x,y,v;
	for(int i = 1; i <= m; i++)
	{
		cin>>x>>y>>v;
		g[x][y] = g[y][x] = v;   
	}
}
void prim(int v)
{
	int k;
	memset(vst,0,sizeof(vst));
	for(int i = 1; i <= n; i++)
	dis[i] = INF;
	
	dis[v] = 0;
	ans = 0;
		
	for(int i = 1; i <= n; i++)   //选择n个点 
	{
		int minn = INF;
		for(int j = 1; j <= n; j++)    //选择最小边 
		{
			if(vst[j]==0 && dis[j] < minn)
			{
				minn = dis[j];
				 k = j;
			}
		}
		vst[k] = 1;        //标记 
		ans += dis[k]; 
		for(int i = 1; i <= n; i++)    //修改dis数组 
		if(vst[i]==0 && g[k][i] < dis[i])
		dis[i] = g[k][i];
	}
}
int main()
{
	read();
	prim(1);
	cout<<ans<<endl;
	return 0;
}
