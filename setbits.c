#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int num = atoi(argv[1]);
	int count = 0;

	while(num > 0) {
		num = num & (num-1); 
		++count;
	}
	printf("count = %d\n", count);
	return 0;
}
