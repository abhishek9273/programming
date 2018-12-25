#include <stdio.h>
#include <stdlib.h>

void reverse_bits(int num)
{
	int tmp = 0xffffffff;
	printf("reversed = %x\n", num ^ tmp);
	
}

int main(int argc, char **argv)
{
	int num = atoi(argv[1]);

	printf("num = %x\n", num);
	reverse_bits(num);
	return 0;
}
