#include<bits/stdc++.h> 
using namespace std ;
int main()
{
    int n ,m ;
    cin >> n >> m ;
    int** a = new int*[n + 1];
    for (int i = 1; i <= n ;i ++) 
    {
        a[i] = new int[n + 1];
        for (int j = 1; j <= n ;j ++) 
        a[i][j] = 0;
    }
    int* b = new int[n + 1];
    for(int i = 1 ; i <= n ;i ++)
    b[i] = 0 ;
    int* ans = new int[n + 1];
    for(int i = 1; i <= m ;i ++)
    {
        int x ,y ;
        cin >> x >> y ;
        a[x][y] = 1 ;
    }
    for(int i = 1 ; i <= n ;i ++)
    ans[i] = -1 ;
    queue<int> q ;
    q.push(1) ;
    b[1] = 1 ;
    ans[1] = 0 ;
    while(!q.empty())
    {
       int t = q.front() ;
        q.pop() ;
        for(int i = 1 ; i <= n ;i ++)
        {
            if(a[t][i] == 1 && b[i] == 0)
            {
                ans[i] = ans[t] + 1 ;
                b[i] = 1 ;
                q.push(i) ;
                if(i == n)
                {
                    cout << ans[n] ;
                    return 0 ;
                }
            }
        }
    }
    cout << ans[n] ;
    for (int i = 1; i <= n; i ++) 
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;
    delete[] ans;
    return 0 ;
}