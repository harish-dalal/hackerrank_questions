#include<bits/stdc++.h>
#define ll long long int
using namespace std;

long int power(long int a, long int b, long int c)
{
    long int temp;
    if(b==0)
        return (1%c);
    if(b==1)
        return (a%c);
    temp = (power(a,b/2,c))%c;
    if(b%2==0)
        return (((temp%c)*(temp%c))%c);
    else
        return (((((temp%c)*(temp%c))%c)*(a%c))%c);
}


long int mod(long int a,long int m)
{
    long int x = 0,y = 1,u = 1,v = 0;
    long int e = m,f = a;
    long int c,d,q,r;
    while(f != 1)
    {
        q = e/f;
        r = e%f;
        c = x-q*u;
        d = y-q*v;
        x = u;
        y = v;
        u = c;
        v = d;
        e = f;
        f = r;
    }
    u = (u+m)%m;
    return u;
}

long int in(long int a, long int b, long int c)
{
    long int temp;
    temp = mod(a,c);
    b = -1*b;
    return (power(temp,b,c));
}


int main() {
    long int t,a,b,x,i,j,ans;
    cin >> t;
    for(i=0;i<t;i++)
    {
        cin >> a;
        cin >> b;
        cin >> x;
        if(b>=0)
            ans = power(a,b,x);
        else
            ans = in(a,b,x);
        cout << ans <<endl;
    }
    return 0;
}
