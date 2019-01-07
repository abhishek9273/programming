#include <stdio.h>
#include <stdlib.h>

#define sof(type) \
	(char)((char*)(&type+1) - (char*)&type)

struct abc {
	int a,b,c;
	char d;
}__attribute__((__packed__));

char char_arr[10];
char *arr[10];
char c1;

int main(void)
{
	int a;
	struct abc v;
	int pptr[4] = {1,2,3,4};

	int *ptr = pptr; 
	printf("sizeof %ld, sof %d\n", sizeof(a), sof(a));
	printf("sizeof %ld, sof %d\n", sizeof(char_arr), sof(char_arr));
	printf("sizeof %ld, sof %d\n", sizeof(*arr), sof(*arr));
	printf("sizeof %ld, sof %d\n", sizeof(*ptr), sof(*ptr));
	return 0;
}
