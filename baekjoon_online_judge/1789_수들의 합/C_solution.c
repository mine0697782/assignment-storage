#include<stdio.h>

int main() {
	unsigned int S;
	unsigned int n = 0;
	scanf("%u", &S);
	while (1) {
		if (S<n)
			break;
		else {
			S -= n;
			n++;
		}
	}
	printf("%u", n - 1);
}