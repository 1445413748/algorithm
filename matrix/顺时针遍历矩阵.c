#include<iostream>
using namespace std;
const int maxn = 100;
int main()
{
    int m,n;
    int a[maxn][maxn];
    cin>>m>>n;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cin>>a[i][j];
    }
    int leftUpRow = 0,leftUpCol = 0,rightDownRow = m - 1,rightDownCol = n -1;
    while(leftUpRow <= rightDownRow && leftUpCol <= rightDownCol)
    {
        int r = leftUpRow, c = leftUpCol;
        while(c <= rightDownCol)   //打印上边的行 
        {
            cout<<a[r][c]<<" ";
            c++;
        }
        c--;
        r++;
        while( r <= rightDownRow)   //打印右边的列 
        {
            cout<<a[r][c]<<" ";
            r++;
        }
        r--;
        c--;
        while( c >= leftUpCol)       //打印下边的行 
        {
            cout<<a[r][c]<<" ";
            c--;
        }
        c++;
        r--;
        while( r > leftUpRow)       //打印左边的列 
        {
            cout<<a[r][c]<<" ";
            r--;
        }
        leftUpRow++;             //左上角的点坐标都+1 
        leftUpCol++;
        rightDownRow--;           //右下角的点坐标都-1 
        rightDownCol--;
    }
    return 0;
}
