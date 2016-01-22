#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char notes[13][4];
int fret_board[13][7];
int pos [7]= {0,5,12,8,3,10,5};

void preprocess(){

    strcpy(notes[1],"C");
    strcpy(notes[2],"C#");
    strcpy(notes[3],"D");
    strcpy(notes[4],"D#");
    strcpy(notes[5],"E");
    strcpy(notes[6],"F");
    strcpy(notes[7],"F#");
    strcpy(notes[8],"G");
    strcpy(notes[9],"G#");
    strcpy(notes[10],"A");
    strcpy(notes[11],"A#");
    strcpy(notes[12],"B");
    int i,j,p;
    for( i = 1 ; i <=6 ; i ++ ){
        p = pos[i];
        for(j = 0 ; j <= 12 ; j ++){

            fret_board[j][i] = p;
            p++;
            if(p > 12 )p = 1;

        }

    }
}

int main (){

    int t,i,j,k;
    int f,s;
    preprocess();
//   freopen("problem1.in","r",stdin);
  //  freopen("guitar_fret.out","w",stdout);
    scanf("%d",&t);
    for( i = 1 ; i <= t ; i ++ ){
        scanf("%d%d",&f,&s);
        printf("Case %d: %s\n",i,notes[fret_board[f][s]]);
    }

    return 0;
}
