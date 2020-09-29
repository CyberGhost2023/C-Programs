#include<stdio.h>
#include<stdlib.h>
#define ll long long

void toRoman(ll n)
{
	ll number[18] = {1,4,5,9,10,40,50,90,100,400,500,900,1000,5000,10000,50000,100000,500000}; 
    char symbol[18][3] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M","V'","X'","L'","C'","D'"}; //using different symbols for number above 4999 
    int i=17;     
    while(n>0) 
    { 
      ll div = n/number[i]; 
      n = n%number[i]; 
      while(div--) 
      { 
        printf("%s",symbol[i]); 
      } 
      i--; 
    } 
}

int main(){
	ll num;
	scanf("%lld",&num);
	if(num>=1000000)
		printf("Invalid Input\n");
	toRoman(num);
	return 0;
}
