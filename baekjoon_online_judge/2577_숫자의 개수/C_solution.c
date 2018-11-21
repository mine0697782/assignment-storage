#include<stdio.h>
#include<string.h>

int main() {
	int A, B, C;
	int * Arr[3] = { &A,&B,&C };
	int i = 0;
	for (int i = 0; i < 3; i++)
		scanf("%d", Arr[i]);
	int num = ((*Arr[0]) * (*Arr[1]) * (*Arr[2]));
	char arr[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	while (num / 10) {
		arr[i] = num % 10;
		num = num / 10;
		i++;
	}
	arr[i] = num;
//	arr[i + 1] = '\0';
	int len;
	for (i = 0; i < 10; i++) {
		if (arr[i] != -1)
			len = i + 1;
	}
	int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (i = 0; i < 10; i++)
		count[arr[i]]++;
//	count[0]--;
	for (i = 0; i < 10; i++)
		printf("%d\n", count[i]);
}