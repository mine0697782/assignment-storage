#include<stdio.h>

int main() {
	char arr[5][15];
	memset(arr, 0, 75);
		for (int i = 0; i<5; i++) {
			gets(arr[i]);
			//while(getchar!='\n');
		}
	for (int i = 0; i<15; i++)
		for (int j = 0; j<5; j++)
			if (arr[j][i] != 0)
				printf("%c", arr[j][i]);
}