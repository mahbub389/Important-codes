#include<bits/stdc++.h>
#define mod 1000000007
#define MX 3000005
#define mx 1000000000
#define push_back pb

using namespace std;

typedef long long LL;
typedef vector <int > vect;
typedef vector <pair <int , int> > vecp;

int tree[100],arr[100];

void build(int pos , int L , int R)
{
    if(L == R)
    {
        tree[pos] = arr[L];
        return;
    }
    int mid = (L+R)/2;
    build(2*pos , L , mid);
    build(2*pos+1 , mid+1,R);
    tree[pos]=min(tree[2*pos],tree[2*pos+1]);
}

int query(int pos , int L , int R , int l , int r)
{
    if(R<l || L>r)
        return mx;
    if(L>=l && R<=r)
        return tree[pos];
    int mid = (R+L)/2;
    return min(query(2*pos,L,mid,l,r) , query(2*pos+1,mid+1,R,l,r));
}

void update(int pos , int L , int R , int ind , int num)
{
    if(L == R)
    {
        tree[pos] = num;
        return;
    }
    int mid = (L+R)/2;
    if(ind<=mid)
        update(2*pos,L,mid,ind,num);
    else
        update(2*pos+1,mid+1,R,ind,num);
    tree[pos] = min(tree[2*pos] , tree[2*pos+1]);
}

int main()
{
    int i , j , n , k , q , p , l , r;
    cin>>n>>q;
    for(i = 1 ; i <= n ; i++)
        cin>>arr[i];
    build(1 , 1 , n);
    for(i = 1 ; i <= q ; i++)
    {
        cin>>p>>l>>r;
        if(p == 0)
            update(1,1,n,l,r);
        else
            cout<<query(1,1,n,l,r)<<endl;
    }
    return 0;
}
