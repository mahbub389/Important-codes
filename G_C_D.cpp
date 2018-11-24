#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL gcd(LL a , LL b)
{
    if(b == 0)
        return a;
    else
        return gcd(b , a%b);
}

int main()
{
    LL a , b ,ans;
    while(cin >> a >>b){
    ans = gcd(max(a,b) , min(a,b));
    cout<<ans<<endl;
    }
    return 0;
}

