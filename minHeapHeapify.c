#include <stdio.h>
#define ll long long
void swap(ll *x,ll *y)
{
    (*x) ^= (*y);
    (*y) ^= (*x);
    (*x) ^= (*y);
}

void heapify(ll ar[],ll i,ll n)
{
    ll left_child=2*i+1,right_child=2*i+2,largest=i;
    if(left_child<n && ar[left_child]<ar[largest])
        largest=left_child;
    if(right_child<n && ar[right_child]<ar[largest])
        largest=right_child;
    if(largest!=i)
    {
        swap(&ar[largest],&ar[i]);
        heapify(ar,largest,n);
    }
}

void deleteHeap(ll ar[],ll n)
{
    while(n>1)
    {
        swap(&ar[n-1],&ar[0]);
        n--;
        heapify(ar,0,n);
    }
}

int main(){
	ll n;
    scanf("%lld",&n);
    ll *ar=(ll*)malloc(n*sizeof(ll));
    for(ll i=0;i<n;i++)
        scanf("%lld",&ar[i]);
    for(ll i=n/2-1;i>=0;i--)
        heapify(ar,i,n);
    for(ll i=0;i<n;i++)
        printf("%lld ",ar[i]);
        deleteHeap(ar,n);
    printf("\n");
    for(ll i=0;i<n;i++)
        printf("%lld ",ar[i]);
	return 0;
}
