//전투력 = 1 * (HP) + 5 * (MP) + 2 * (공격력) + 2 * (방어력)
#include<stdio.h>

int main(){
    int n;
    int stat[8];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<8;j++)
            scanf("%d",&stat[j]);
        for(int j=0;j<4;j++)
            stat[j]+=stat[j+4];
        if(stat[0]<1)
            stat[0]=1;
        if(stat[1]<1)
            stat[1]=1;
        if(stat[2]<0)
            stat[2]=0;
        printf("%d\n",1 * stat[0] + 5 * stat[1] + 2 * stat[2] + 2 * stat[3]);
    }
}