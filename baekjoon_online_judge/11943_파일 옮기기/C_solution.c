#include<stdio.h>

int main()
{
    int A,B,C,D;
    int num;
    scanf("%d %d",&A,&B);
    scanf("%d %d",&C,&D);
    num=((A+D)>(B+C) ? (B+C) : (A+D));
    printf("%d",num);
}