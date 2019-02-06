#include <stdio.h>

int main(void)
{
	int *ptr = 100;
	ptr++;
	printf("%p, %d\n", ptr, ptr);
	return 0;
}
