#include<iostream>
using namespace std;
const int maxn=1e6+5; 
int d[maxn][25];
int mn[maxn];
int a[maxn];
int m,n;
void rmq_init()
{
	/*初始化d数组,d[i][j]中i表示左边端点,j表示2^j个长度,
	因此d[i][j]所管辖的区间为[i,i+2^j-1] */ 
	for(int i = 1;i <= n;i++)    
	d[i][0] = a[i];
	
	for(int j = 1;(1<<j) <= n;++j) //j枚举每一个可能出现的长度 
		for(int i = 1;i + (1<<j)-1 <= n;i++)  //i枚举每一个区间的左端点 
		d[i][j] = max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
		
	//对于一定长度的区间len,mn[len]表示小于等于len的最大的2的幂次 
	 for(int len = 1;len <= n;++len)
	 {
	 	int k = 0;
	 	while(1<<(k+1) <= len)
	 	k++;
	 	mn[len] = k;
	 }
}
 int rmq(int L,int R)
 {
 	int s = mn[R-L+1];
	int ans = max(d[L][s],d[R - (1<<s) + 1][s]);
	return ans;
 }
int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++)
	cin>>a[i];
	rmq_init();
	int L,R;
	cin>>m;
	for(int i = 1;i <= m;i++)
	{
		cin>>L>>R;
		cout<<rmq(L,R)<<endl;
	}
	return 0;
 } 
