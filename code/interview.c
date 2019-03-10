#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#if 0
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
#endif

/* Jaarwis technologies interview questions */

struct node {
	const char *word;
	int len;
	bool is_last;
	struct node *next;
};

void print_list(struct node *list)
{
	for (; list; list = list->next)
		printf("word = %s, len = %d, is_last = %d, stt = %d\n",
				list->word, list->len, list->is_last, list->sum_till_this);
}

struct node *populate_list(char **str)
{
	int i;
	struct node *tmp;
	struct node *ret;

	tmp = malloc(sizeof(struct node));
	ret = tmp;
	tmp->word = str[i];
	tmp->len = strlen(str[i]);
	tmp->is_last = str[i+1] ? false : true;
	for (i = 1; str[i]!=NULL; i++) {
		tmp->next = malloc(sizeof(struct node));
		if (!tmp->next) {
			printf("Error allocating memory\n");
			return NULL;
		}
		tmp = tmp->next;
		tmp->word = str[i];
		tmp->len = strlen(str[i]);
		tmp->is_last = str[i+1] ? false : true;
	}
	return ret;
}

int main(void)
{
	char *str[] = {"This", "is", "an", "example", "justification", NULL};
	struct node *list;

	list = populate_list(str);
	printf("List populated\n");
	print_list(list);
	return 0;
}
