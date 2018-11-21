#include<stdio.h>
int main(){
    int c,n=0;
    scanf("%d",&c);
    int i=1000-c,d=500,s=0;
    while(1){
        if(i<d){
            d=(s==0?d/5:d/2);
            s=(s==0?1:0);
        }
        n+=i/d;
        i%=d;
        if(i<=0)
            break;
    }
    printf("%d",n);
}