#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a,string b)
{
	//除去字符串前面的0 
	a=a.substr(a.find_first_not_of('0'));
	b=b.substr(b.find_first_not_of('0'));
	int lenA=a.length();
	int lenB=b.length();
	int len=max(lenA,lenB)+10;
	//将a串和b串反转,从最低位开始运算 
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end()); 
	string ans(len,'0');
	//将a串拷贝到ans串 
	for(int i=0;i<lenA;i++)
	ans[i]=a[i];
	//tem是上一位的进位 
	int tem=0;
	for(int i=0;i<len;i++)
	{
	if(i<b.length())
	tem += (ans[i]-'0')+(b[i]-'0');
	else
	tem += (ans[i]-'0'); 
	ans[i]=tem%10+'0';
	tem /= 10;
	}
	//a串和b串是从最低位开始运算,所以要将ans串反转从最高位到最低位 
	reverse(ans.begin(),ans.end());
	//前面可能存在多余的前导0,返回之前截掉 
	return ans.substr(ans.find_first_not_of('0')); 
}
int main()
{
	string a="00001234";
	string b="0005678";
	cout<<add(a,b)<<endl;
	return 0;
}
