#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<char>v;
int i,len,comment,quote,pos;
string s;
char res[1111111];

int get_cmnt()
{
    while(i<len)
    {
        if(s[i]=='*'&&s[i+1]=='/' &&i+1<len)
        {
            comment=0;
            return i+2;
        }
        i++;
    }
    return i;
}

int get_quote()
{
    while(i<len)
    {
        if(s[i]=='"' &&s[i-1]=='\\')
        {
            v.pb(s[i]);
            //res[pos++]=s[i];
            //cout<<s[i];
        }
        else if(s[i]=='"' && s[i-1]!='\\')
        {
            v.pb(s[i]);
            //res[pos++]=s[i];
            //cout<<s[i];
            return i+1;
        }
        else v.pb(s[i]);//res[pos++]=s[i];//cout<<s[i];

        i++;
    }
    return i;
}

bool valid()
{
    if(isalpha(s[i])||isdigit(s[i])||s[i]==' '||s[i]=='\t')return false;
    return true;
}

int f_go()
{
    while((s[i]==' '||s[i]=='\t')&&i<len)i++;
    return i;
}

int main()
{
    //printf( " he said, \"quotation.\"");

    //FILE*f=freopen("in.txt","r",stdin);
    //FILE*o=freopen("out.txt","w",stdout);

    comment=0;
    int t,tc=1;
    cin>>t;
    while(t--){
            cout<< "Case #"<<tc++<< ":"<<endl;
    while(getline(cin,s))
    {
        if(s=="XXX")break;

        pos=0;
        //memset(res,0,sizeof(res));
        v.clear();
        len=s.size();
        i=0;
        i=f_go();
        while(i<len)
        {
            if(i+1<len && s[i]=='/'&&s[i+1]=='/'&& !comment)break;
            if(i+1<len && s[i]=='/'&&s[i+1]=='*')comment=1;
            if(comment)
            {
                i=get_cmnt();
                i=f_go();
                continue;
            }
            if(s[i]=='"')
            {
                v.pb(s[i]);
                //res[pos++]=s[i];
                //cout<<s[i];
                i++;
                i=get_quote();
                i=f_go();
                continue;
            }
            if(valid())
            {
                v.pb(s[i]);
                //res[pos++]=s[i];
                //cout<<s[i];
                i++;
                i=f_go();
                continue;
            }
            else
            {
                v.pb(s[i]);
                //res[pos++]=s[i];
                //cout<<s[i];
                if(i+1<len && (s[i+1]==' '||s[i+1]=='\t'))
                {
                    //cout<< " ";
                    i++;
                    i=f_go();
                    if(!valid())v.pb(' ');//res[pos++]=' ';
                    continue;
                }
            }
            i++;
        }
        //res[pos]='/0';
        //cout<<endl;
        //puts(res);
        for(int j=v.size()-1;j>=0;j--)
        {
            if(v[j]==' '||v[j]=='\t')v.erase(v.begin()+v.size()-1);
            else break;
        }
        if(v.size()>0)
        {
            for(int j=0;j<v.size();j++)cout<<v[j];
            cout<<endl;
        }
    }
        //reverse(v.begin(),v.end());


        //if(res.size()>0)cout<<res<<endl;
    }


    //fclose(f);
    //fclose(o);

    return 0;
}
