#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MX=1000005;
map<int,int>cnt;
set<int> s;
set<int>::iterator it;
int least_prime[MX+10];
bool prime[MX+10];
vector<int>v;
void Sieve()
{
    memset(prime,true,sizeof(prime));
    prime[1]=0;
    least_prime[1]=1;
    for (int p=2; p*p<=MX; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=MX; i += p)
            {
                prime[i] = false;
                if(!least_prime[i])
                    least_prime[i]=p;
            }
        }
    }
    for(int i=1; i<=MX; i++) if(prime[i]) least_prime[i]=i;
}
int main()
{
    int  i , j , k=0 , n ,t , ans=1;
    cin>>n;
    Sieve();
    LL x = n,res=1;
    LL r= least_prime[x];
    if(n==1){
        cout<<1<<" "<<0<<endl;
        return 0;
    }
    while(x!=1)
    {
        x=x/r;
        cnt[r]++;
        s.insert(r);
        r=least_prime[x];
    }
    for(it=s.begin(); it!=s.end(); it++){
        ans = ans*(*it);
        k = max(k,cnt[*it]);
        v.push_back(cnt[*it]);
    }
    int tt=1,ok=0,okk=0;
    for(i=0 ; i < v.size()-1 ; i++)
    {
        if(v[i]==v[i+1]) tt++;
    }
    if(tt == s.size())
    {
        int pp = 0;
        while(true)
        {
            if((1<<pp) ==k)
                ok=1;
            if((1<<pp) >= k) break;
            pp++;
        }
    }
    if(ok==0) okk=1;
    i=0;
    while(true)
    {
        if((1<<i) >= k) break;
        i++;
    }
    ///if(sqrt(n)*sqrt(n) == n) i++;
    cout<<ans<<" "<<i+okk<<endl;
    return 0;
}
