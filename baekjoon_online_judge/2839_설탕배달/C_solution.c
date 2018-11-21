#include<stdio.h>

int Test(int input) {
	int Five = 0, Three = 0;
	int test = 0;
	Five = input / 5;
	test = input % 5;
	if (test == 0)
		return(Five);
	switch (test) {
	case 1:
		if (Five<1)
			return -1;
		else {
			Five--;
			Three += 2;
			break;
		}
	case 2:
		if (Five<2)
			return -1;
		else {
			Five -= 2;
			Three += 4;
			break;
		}
	case 3:
		Three++;
		break;
	case 4:
		if (Five<1)
			return -1;
		else {
			Five--;
			Three += 3;
			break;
		}
	}
	return (Five + Three);
}
int main()
{
	int input;
	scanf("%d", &input);
	printf("%d",Test(input));
	return 0;
}