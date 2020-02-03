
#include<iostream>
using namespace std;
int main()
{
    int sum,maxn;
    int a[1000];
    int n,left,right;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sum = a[0];
    left = right = 0;    //left记录起始下标,right记录终点下标 
    maxn = sum;
    for(int i = 1; i < n; i++)
    {
        if(sum >= 0)    
            sum += a[i];
        else
        {
            sum = a[i];   //sum为负数没贡献,直接更新sum 
             left = i;   
        }

        if(sum > maxn)
        {
            maxn = sum;
            right = i;
        }
    }
    cout<<maxn<<endl;
    cout<<left<<" "<<right<<endl;
    return 0;
}
