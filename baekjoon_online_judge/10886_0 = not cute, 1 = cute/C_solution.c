#include<stdio.h>

int main() {
	int n, in, c = 0;
	char * cute[2] = { "not cute","cute" };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		c += in;
	}
	printf("Junhee is %s!", cute[c>n / 2]);
}