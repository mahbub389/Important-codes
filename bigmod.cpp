#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod =1000000007;

LL bigmod(LL N,LL P)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        LL ret=bigmod(N,P/2);
        return ((ret%mod)*(ret%mod))%mod;
    }
    else return ((N%mod)*(bigmod(N,P-1)%mod))%mod;
}

int main()
{
    int i , j , k , n ;
    while(cin>>n>>k)
    {
        cout<<bigmod(n,k)<<endl;
    }
    return 0;
}


