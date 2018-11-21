#include<stdio.h>
#include<string.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char arr[10][11];
    for(int i = 0; i<n; i++)
        scanf("%s",&arr[i]);
    for(int i = 0; i<n; i++){
        for(int j = strlen(arr)-1; j>=0; j--)
            printf("%c",arr[i][j]);
        printf("\n");
    }
}