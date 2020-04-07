
/**Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v,vc;
long long x[150];
int main()
{
    //fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q,initial,f1,f2,bb;
    cin>>t>>bb;
    while(t--)
    {
        v.clear();
        vc.clear();
        p=1;
        q=bb;
        for(i=1; p<q; i+=2)
        {
            if(i%10==1)
            {
                i+=2;
                if(v.size()==0)
                {
                    f1=0;
                    cout<<1<<'\n'<<flush;
                    cin>>a;

                }
                else
                {
                    cout<<v[0]<<'\n'<<flush;
                    cin>>a;
                    if(x[v[0]]==a)
                        f1=0;
                    else
                        f1=1;
                }
                if(vc.size()==0)
                {
                    f2=0;
                    cout<<1<<'\n'<<flush;
                    cin>>a;

                }
                else
                {
                    cout<<vc[0]<<'\n'<<flush;
                    cin>>a;
                    if(x[vc[0]]==a)
                        f2=0;
                    else
                        f2=1;
                }
                if(f1)
                {
                    for(int i=0; i<v.size(); i++)
                    {
                        x[v[i]]^=1;
                        x[bb-v[i]+1]^=1;
                    }
                }
                if(f2)
                {
                    for(int i=0; i<vc.size(); i++)
                    {
                        x[vc[i]]^=1;
                        x[bb-vc[i]+1]^=1;
                    }
                }

            }
            cout<<p<<'\n'<<flush;
            cin>>c;
            x[p]=c;
            cout<<q<<'\n'<<flush;
            cin>>d;
            x[q]=d;
            if(c==d)
            {
                v.push_back(p);
            }
            else
                vc.push_back(p);
            p++;
            q--;

        }
        if(i%10==1)
        {
            i+=2;
            if(v.size()==0)
            {
                f1=0;
                cout<<1<<'\n'<<flush;
                cin>>a;

            }
            else
            {
                cout<<v[0]<<'\n'<<flush;
                cin>>a;
                if(x[v[0]]==a)
                    f1=0;
                else
                    f1=1;
            }
            if(vc.size()==0)
            {
                f2=0;
                cout<<1<<'\n'<<flush;
                cin>>a;

            }
            else
            {
                cout<<vc[0]<<'\n'<<flush;
                cin>>a;
                if(x[vc[0]]==a)
                    f2=0;
                else
                    f2=1;
            }
            if(f1)
            {
                for(int i=0; i<v.size(); i++)
                {
                    x[v[i]]^=1;
                    x[bb-v[i]+1]^=1;
                }
            }
            if(f2)
            {
                for(int i=0; i<vc.size(); i++)
                {
                    x[vc[i]]^=1;
                    x[bb-vc[i]+1]^=1;
                }
            }

        }
        for(i=1; i<=bb; i++)
        {
            cout<<x[i];
        }
        cout<<'\n'<<flush;
        char ch;
        cin>>ch;
        if(ch=='N')
            break;
    }
    return 0;
}
