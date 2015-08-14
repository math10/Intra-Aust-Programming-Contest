#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
const int MX = 70 ;

int dx[] = { 1 , 0 , -1 ,  0 };
int dy[] = { 0 , 1 ,  0 , -1 };

struct node {
    int x , y , cost ;
    node( int _x , int _y , int _c ) {
        x = _x  , y = _y  , cost = _c ;
    }
    node(){}
};

int R , C ;
char g[MX][MX];
bool Vis1[MX][MX] , Vis2[MX][MX];
int D[MX][MX];
pii den ;

queue< node > flood , St ;

bool isValid(int x , int y){
    return ( x >= 0 and y >= 0 and x < R and y < C and g[x][y] != 'X' );
}
void Init(){
    memset(Vis1,false,sizeof Vis1);
    memset(Vis2,false,sizeof Vis2);
    memset(D,-1,sizeof D);
    while( !flood.empty() ) flood.pop();
    while( !St.empty() ) St.pop();
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T ;
    scanf("%d",&T);
    for( int cs = 1 ; cs <= T ; cs++ ){
        scanf("%d %d",&R,&C);
        Init();
        for( int i = 0 ; i < R ; i++ ) scanf("%s",g[i]);
        for( int i = 0 ; i < R ; i++ ){
            for( int j = 0 ; j < C ; j++ ){
                if( g[i][j] == '*' ){
                    flood.push( node(i,j,0) );
                    Vis1[i][j] = true ;
                }else if( g[i][j] == 'D' ){
                    den = pii( i , j );
                    Vis1[i][j] = true ;
                }else if( g[i][j] == 'S' ){
                    St.push( node(i,j,0) );
                    Vis2[i][j] = true ;
                }
            }
        }
        while( !flood.empty() ){
            node u = flood.front() ;
            flood.pop();
            D[ u.x ][ u.y ] = u.cost ;
            for( int i = 0 ; i < 4 ; i++ ){
                int nx = dx[i] + u.x ;
                int ny = dy[i] + u.y ;
                if( isValid(nx,ny) and Vis1[nx][ny] == false ){
                    flood.push( node(nx,ny,u.cost+1) );
                    Vis1[nx][ny] = true ;
                }
            }
        }
        int Ans = -1 ;
        while( !St.empty() ){
            node u = St.front() ;
            St.pop();
            if( abs( u.x - den.first ) + abs( u.y - den.second) == 1 ){
                Ans = u.cost + 1 ;
                break ;
            }
            for( int i = 0 ; i < 4 ; i++ ){
                int nx = dx[i] + u.x ;
                int ny = dy[i] + u.y ;
                if( isValid(nx,ny) and ( Vis2[nx][ny] == false ) and ( D[nx][ny] > u.cost + 1 or D[nx][ny] == -1) ){
                    St.push( node(nx,ny,u.cost+1) );
                    Vis2[nx][ny] = true ;
                }
            }
        }
        printf("Case %d: ",cs);
        if( Ans == -1 ) puts("Go to Brazil");
        else printf("%d\n",Ans);
    }
}
