#include <stdio.h>


void print_char_array(char c[10])
{
	int i = 0;
	for (i=0; i < 10; i++)
		printf("c[%d] = %c\n", i, c[i]);
}

int main(int argc, char **argv)
{
	char *in = argv[1];
	char str[] = {"helloworld"};
	printf("%d\n", sizeof (str));
//	print_char_array(in);	
	return 0;
}
