#include<bits/stdc++.h>
using namespace std;

double root(double n)
{
    double x=n;
    double y=1;
    double limit =0.000000001;
    while((x-y) > limit){
        x=(x+y)/2;
        y=n/x;
    }
    return x;
}

int main()
{
    double n; scanf("%lf",&n);
    printf("Square root of %lf is %lf\n",n,root(n));
    return 0;
}
