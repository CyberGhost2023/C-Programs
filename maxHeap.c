#include <stdio.h>
#define ll long long
void swap(ll *x,ll *y)
{
    (*x) ^= (*y);
    (*y) ^= (*x);
    (*x) ^= (*y);
}

void maxHeap(ll ar[],ll n)
{
    for(ll i=n;i>0;i--)
    {
        ll node=i;
        ll parent=(i-1)/2;
        while(parent>=0 && ar[parent]<ar[node])
        {
            swap(&ar[parent],&ar[node]);
            node=parent;
            parent=(node-1)/2;
        }
    }
}

void deleteHeap(ll ar[],ll n)
{
    while(n>1)
    {
        swap(&ar[n-1],&ar[0]);
        n--;
        for(ll i=1;i<n;i++)
            maxHeap(ar,i);
    }
}

int main(){
	ll n;
    scanf("%lld",&n);
    ll *ar=(ll*)malloc(n*sizeof(ll));
    for(ll i=0;i<n;i++)
        scanf("%lld",&ar[i]);
    for(ll i=1;i<n;i++)
        maxHeap(ar,i);
    for(ll i=0;i<n;i++)
        printf("%lld ",ar[i]);
    deleteHeap(ar,n);
    printf("\n");
    for(ll i=0;i<n;i++)
        printf("%lld ",ar[i]);
	return 0;
}
