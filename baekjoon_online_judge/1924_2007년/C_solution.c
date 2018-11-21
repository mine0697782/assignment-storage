#include<stdio.h>

int main()
{
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char * week[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int x,y;
    int day=0;
    scanf("%d %d",&x,&y);
    if(x>=2)
        for(int i=0;i<x-1;i++)
            day+=month[i];
    day+=y;
    printf("%s",week[day%7]);
    return 0;
}