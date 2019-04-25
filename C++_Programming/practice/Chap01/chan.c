#include<stdio.h>

int main(){
    int num1 = 3;
    int num2 = 4;
    int result = num1 + num2;

    printf("덧셈 결과 : %d \n ", result);
    printf("test1 \n"); // 테스트 1번
    printf("%d+%d=%d\n", num1, num2, result);
    printf("test2 \n"); // 테스트 2번
    printf("%d와(과) %d의 합은 %d 입니다.\n", num1, num2, result);
    return 0;
}
