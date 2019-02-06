#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

/* Detect if two numbers have opposite sign */
static void opp_signs(const int a, const int b)
{
	/* Note : Question is only valid for signed integers */
	int tmp = a ^ b;
	if (tmp > 0)
		printf("Same sign\n");
	else
		printf("Opposite sign\n");
}

static void reset_bit(uint64_t num, int index)
{
	uint64_t bit = (1 << index);	
}

static void bit_pattern(uint64_t num)
{
	
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return printf("Insufficient parameters\n");

//	opp_signs(atoi(argv[1]), atoi(argv[2]));
	bit_pattern(atoi(argv[1]), 0);
	return 0;
}
