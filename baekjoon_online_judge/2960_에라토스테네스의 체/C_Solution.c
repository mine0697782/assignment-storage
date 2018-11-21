#include<stdio.h>

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	int num[999];
	for (int i = 2; i <= N; i++)
		num[i - 2] = i;
	int i = 2, j = 2, k = 0, n = 0;
	while (1) {
		while (1) {
			if ((i - 2 + j * n) > N-2)
				break;
			if (num[i - 2 + j * n] != 0) {
				k++;
				if (K == k) {
					//printf("i:%d  j:%d  k:%d  n:%d\n", i, j, k, n);
					printf("%d", num[i - 2 + j * n]);
					return;
				}
				num[i - 2 + j * n] = 0;
			}
			n++;
		}
		i++;
		j++;
		n = 0;
	}
}