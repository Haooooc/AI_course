#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    char m[3][3] ;
    int depth ;
    int x, y ;
} M ;

M *ss ;
set<int> VIS ;
int ANS = 123456789 ;
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} ;

int map_ID(M a)
{
    int ID = 0 ;
    for (int i = 0 ; i < 3 ;i ++)
        for (int j = 0 ; j < 3 ;j ++)
        {
            if (a.m[i][j] == 'x')
            ID = ID * 10 + 9 ;
            else
            ID = ID * 10 + a.m[i][j] - '0' ;
        }
    return ID ;
}
void bfs(M a)
{
    queue<M> q ;
    q.push(a) ;
    VIS.insert(map_ID(a)) ;
    while (!q.empty())
    {
        M que = q.front() ;
        q.pop() ;
        if (map_ID(que) == ANS)
        {
            cout << que.depth ;
            return ;
        }
        for (int i = 0 ; i < 4 ;i ++)
        {
            int tx = que.x + moves[i][0] ;
            int ty = que.y + moves[i][1] ;
            if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3)
            {
                M tmp = que ;
                tmp.m[tmp.x][tmp.y] = tmp.m[tx][ty] ;
                tmp.m[tx][ty] = 'x' ;
                tmp.x = tx ; 
                tmp.y = ty ;
                tmp.depth ++ ;
                int Inp = map_ID(tmp) ;
                if (VIS.find(Inp) == VIS.end())
                {
                    VIS.insert(Inp) ;
                    q.push(tmp) ;
                }
            }
        }
    }
    cout << -1 ;
}

int main()
{
    ss = new struct node ;
    for (int i = 0 ; i < 3 ;i ++)
    for (int j = 0 ; j < 3 ;j ++)
    {
        cin >> ss->m[i][j] ;
        if (ss->m[i][j] == 'x')
        {
            ss->x = i ;
            ss->y = j ;
            ss->depth = 0 ;
        }
    }
    bfs(*ss) ;
    delete ss ;
    return 0 ; 
}