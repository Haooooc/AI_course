#include<bits/stdc++.h> 
using namespace std; 
#define N 501
#define MAX 5000001
int n, m ;
int a[N][N] ;
int dis[N] ;
bool vis[N] ;
 
void dijk()
{
	for(int i = 1 ; i <= n ;i ++) 
	{
		int mp = -1 ;
		for(int j = 1 ; j <= n ;j ++)
		{
			if((mp == -1 || dis[j] < dis[mp]) && !vis[j])
			mp = j ; 
		}
		if(mp == -1) 
        return ;
		vis[mp] = true ;
		for(int k = 1 ; k <= n ;k ++)
		dis[k] = min(dis[k], dis[mp] + a[mp][k]) ;
	}
}
 
int main()
{
	cin >> n >> m ;
    for(int i = 1; i <= n ;i ++) 
    for(int j = 1; j <= n ;j ++)
    a[i][j] = i == j ? 0 : MAX ;
	int x, y, w ;
	for(int i = 1; i <= m ;i ++)
	{
		cin >> x >> y >> w ;
		a[x][y] = min(a[x][y], w) ;
	}
	for(int i = 1 ; i <= n ;i ++)
	{	
		dis[i] = a[1][i] ;
		vis[i] = false ;
	}
	dijk() ;
	if(dis[n] == MAX)
    cout << -1 ;
	else
    cout << dis[n] ;
	return 0 ;
}