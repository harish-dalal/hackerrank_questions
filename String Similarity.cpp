#include<bits/stdc++.h>
#define N 100005
using namespace std;

char inp[N];
int Z[N];

int main()
{
    int t,i,l,r,n,j,k;
    long long int sum;
    scanf("%d\n",&t);
    while(t>0)
    {
        scanf("%s",inp);
        n=strlen(inp);
        l=r=0;
        Z[0]=n;
        sum=0;
        for(i=1;i<n;i++)
        {
            sum+=Z[i-1];
            Z[i]=0;
            if(l<=i&&i<=r)
            {
                if(Z[i-l]<r-i+1)
                {
                    Z[i]=Z[i-l];
                    continue;
                }
                for(k=r-i+1,j=r+1;j<n;j++,k++)
                {
                    if(inp[j]!=inp[k])
                        break;
                }
                Z[i]=k;
                l=i;
                r=j-1;
            }
            else
            {
                for(j=i;j<n;j++)
                {
                    if(inp[j]!=inp[j-i])
                        break;
                }
                if(j==i)
                    continue;
                l=i;
                r=j-1;
                Z[i]=r-l+1;
            }   
        }
        printf("%lld\n",sum+Z[n-1]);
        t--;
    }
    return 0;
}

