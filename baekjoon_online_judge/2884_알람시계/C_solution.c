#include<stdio.h>

int main(){
    int time[2];
    scanf("%d%d",&time[0],&time[1]);
    if(time[1]<45){
        if(time[0]==0)
            time[0]=23;
        else
            time[0]--;
        time[1]+=15;
    }
    else
        time[1]-=45;
    printf("%d %d",time[0],time[1]);
}