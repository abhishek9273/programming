#include <stdio.h>
int main(void)
{
	int num = -32767, num2 = 1;
	unsigned unum;

	unum = num;
	printf("0x%x\n", unum);
	unum = num2;
	printf("0x%x\n", unum);
	return 0;
}
