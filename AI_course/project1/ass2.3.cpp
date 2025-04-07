#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    char m[3][3] ;
    int depth ;
    int x, y ;
    int f ;
    string path ;
} M ;

bool operator<(const M &a, const M &b)
{
    return a.f > b.f ;
}

M *ss ;
set<int> VIS ;
int ANS = 123456789 ;
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} ;
char move_way[4] = {'u', 'd', 'l', 'r'} ;

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

int D_(M a)
{
    int d = 0 ;
    for (int i = 0 ; i < 3 ;i ++)
    for (int j = 0 ; j < 3 ;j ++)
    {
        if (a.m[i][j] != 'x')
        {
            int num = a.m[i][j] - '0' ;
            int tx = num / 3 ;
            int ty = num % 3 ;
            d += abs(i - tx) + abs(j - ty) ;
        }
        else
        d += abs(i - 2) + abs(j - 2) ;
    }
    return d ;
}

void a_star(M a)
{
    priority_queue<M> pq ;
    a.f = a.depth + D_(a) ;
    pq.push(a) ;
    VIS.insert(map_ID(a)) ;
    while (!pq.empty())
    {
        M cur = pq.top() ;
        pq.pop() ;
        if (map_ID(cur) == ANS)
        {
            cout << cur.path ;
            return ;
        }
        for (int i = 0 ; i < 4 ;i ++)
        {
            int tx = cur.x + moves[i][0] ;
            int ty = cur.y + moves[i][1] ;
            if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3)
            {
                M tmp = cur ;
                tmp.m[tmp.x][tmp.y] = tmp.m[tx][ty] ;
                tmp.m[tx][ty] = 'x' ;
                tmp.x = tx ;
                tmp.y = ty ;
                tmp.depth ++ ;
                tmp.f = tmp.depth + D_(tmp) ;
                tmp.path = cur.path + move_way[i] ;
                int Inp = map_ID(tmp) ;
                if (VIS.find(Inp) == VIS.end())
                {
                    VIS.insert(Inp) ;
                    pq.push(tmp) ;
                }
            }
        }
    }
    cout << "unsolvable" ;
}

int main()
{
    int cnt = 0 ;
    ss = new struct node ;
    for (int i = 0 ; i < 3 ;i ++)
    for (int j = 0 ; j < 3 ;j ++)
    {
        cin >> ss->m[i][j] ;
        if(ss->m[i][j] != 'x')
        for(int k = 0 ; k < i ;k ++)
        for(int l = 0 ; l < 3 ;l ++)
        {
            if(ss->m[k][l] != 'x' && ss->m[k][l] > ss->m[i][j])
            cnt ++ ;
        }
        if(ss->m[i][j] != 'x')
        for(int l = 0 ; l < j ;l ++)
        {
            if(ss->m[i][l] != 'x' && ss->m[i][l] > ss->m[i][j])
            cnt ++ ;
        }
        if (ss->m[i][j] == 'x')
        {
            ss->x = i ;
            ss->y = j ;
            ss->depth = 0 ;
        }
    }
    if(cnt % 2 == 0)
    a_star(*ss);
    else
    cout << "unsolvable" ;
    delete ss;
    return 0;
}