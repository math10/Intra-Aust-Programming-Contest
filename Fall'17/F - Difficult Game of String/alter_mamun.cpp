#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)

///****************** template ends here ****************
int t,n,m;
#define mx 26
struct node
{
    node *next[mx+1];
    node()
    {
        repI(i,mx)
            next[i]=NULL;
    }
}*root;

void insert(string &str)
{
    node *curr = root;
    repI(i,str.size())
    {
        int id = str[i]-'a';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
}

int hackenbush ( node *cur ) {

    int res = 0;
    repI(i,mx)
        if(cur -> next[i])
            res ^= hackenbush(cur->next[i]) + 1;
    return res;
}


void del(node *cur)				// send root here
{
    repI(i,mx)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    rep(cs,t)
    {
        root = new node();
        string s;
        cin >> n;
        rep(i,n)
        {
            cin >> s;
            insert(s);
        }
        int res = hackenbush(root);
        cout << "Case " << cs << ": ";
        if(res) cout << "Arnab" << endl;
        else cout << "Mahir" << endl;
        del(root);
    }

    return 0;
}


