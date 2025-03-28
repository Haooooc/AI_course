#include <bits/stdc++.h>
using namespace std;
#define N 150001
#define MAX 1000000001
int n, m ;
vector<pair<int, int>> adj[N] ;
int dis[N] ;
bool vis[N] ;
void dij() 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
    pq.push({0, 1}) ;
    while (!pq.empty()) 
    {
        int p = pq.top().second ;
        int d = pq.top().first ;
        pq.pop() ;
        if (vis[p]) 
        continue ;
        vis[p] = true ;
        for(size_t i = 0; i < adj[p].size() ;i ++) 
        {
            int y = adj[p][i].first ;
            int w = adj[p][i].second ;
            if (dis[y] > dis[p] + w) 
            {
                dis[y] = dis[p] + w ;
                pq.push({dis[y], y}) ;
            }
        }
    }
}
int main() 
{
    cin >> n >> m ;
    for (int i = 1 ; i <= m ;i ++) 
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w}) ;
    }
    for (int i = 1; i <= n ;i ++) 
    {
        dis[i] = MAX ;
        vis[i] = false ;
    }
    dis[1] = 0 ;
    dij() ;
    if (dis[n] == MAX) 
    cout << -1 ;
    else
    cout << dis[n] ;
    return 0 ;
}