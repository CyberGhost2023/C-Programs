#include<stdio.h>
#include<stdlib.h>
#define ll long long

void toBinary(ll n)
{
	ll *bin=(ll *)malloc(8*8*sizeof(ll));
	ll k=0;
	while(n)
	{
		bin[k]=n%2;
		k++;
		n/=2;
	} 
	for(ll i=k-1;i>=0;i--)
	{
		printf("%lld",bin[i]);
	}
}

int main(){
	ll num;
	scanf("%lld",&num);
	toBinary(num);
	return 0;
}