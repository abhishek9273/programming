#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int num = atoi(argv[1]);

	printf("%d\n", !(num & (num-1)));
	return 0;
}
