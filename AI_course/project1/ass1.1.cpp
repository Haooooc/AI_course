#include<bits/stdc++.h> 
using namespace std ;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> ans(n + 1, -1);
    vector<bool> b(n + 1, false);
    queue<int> q;
    q.push(1);
    b[1] = true;
    ans[1] = 0;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i = 0; i < adj[t].size(); i++)
        {
            int neighbor = adj[t][i];
            if(!b[neighbor])
            {
                ans[neighbor] = ans[t] + 1;
                b[neighbor] = true;
                q.push(neighbor);
                if(neighbor == n)
                {
                    cout << ans[n];
                    return 0;
                }
            }
        }
    }
    cout << ans[n];
    return 0;
}