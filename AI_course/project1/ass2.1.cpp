#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    char m[3][3] ;
} M ;

M *ss ;
set <int> VIS ;
int max_depth = 40 ;
int DEP = -1 ;
int FLAG = 0 , ANS = 123456789 ;
int moves[4][2] = {{-1,0},{1,0},{0,-1},{0,1}} ;

int map_ID(M a)
{
    int ID = 0 ;
    for(int i = 0 ; i < 3 ;i ++)
        for(int j = 0 ; j < 3 ;j ++)
        {
            if(a.m[i][j] == 'x')
                ID = ID * 10 + 9 ;
            else
                ID = ID * 10 + a.m[i][j] - '0' ;
        }
    return ID ;
}

void dfs(M a ,int depth)
{
    if(max_depth < depth) return ;
    if(FLAG == 1) return ;
    int Ina = map_ID(a) ;
    VIS.insert(Ina) ;
    if(Ina == ANS)
    {
        FLAG = 1 ;
        DEP = depth ;
    }
    else
    {
        int x ,y ;
        for(int i = 0 ; i < 3 ;i ++)
            for(int j = 0 ; j < 3 ;j ++)
                if(a.m[i][j] == 'x')
                {
                    x = i ;
                    y = j ;
                    break ;
                }
        for(int i = 0 ; i < 4 ;i ++)
        {
            int tx = x + moves[i][0] ,ty = y + moves[i][1] ;
            if(tx > -1 && tx < 3 && ty > -1 && ty < 3)
            {
                M temp = a ;
                int tempi ;
                tempi = temp.m[x][y] ;
                temp.m[x][y] = temp.m[tx][ty] ;
                temp.m[tx][ty] = tempi ;
                int Inp = map_ID(temp) ;
                if(VIS.find(Inp) == VIS.end())
                dfs(temp ,depth + 1);
            }
        } 
    }
} 

int main()
{
    ss = new struct node ;
    for(int i = 0 ; i < 3 ;i ++)
        for(int j = 0 ; j < 3 ;j ++)
            cin >> ss -> m[i][j] ;
    dfs(*ss ,0) ;
    cout << FLAG ;
    delete ss ;
    return 0 ;
}