#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define malloc_assert(mem) {	\
	if (!mem) {	\
		printf("Failed to allocate memory\n");	\
		return -ENOMEM;	\
	}	\
}

struct list {
	int val;
	struct list* next;
};

static int get_list(const int size, struct list** out_head)
{
	int i = 0;
	struct list* tmp;

	/* Allocate head */	
	*out_head = malloc(sizeof(struct list));
	malloc_assert(*out_head);
	(*out_head)->val = i;
	tmp = *out_head;

	/* Allocate the rest of the list */
	for(i = 1; i < size; i++)
	{
		tmp->next = malloc(sizeof(struct list));
		malloc_assert(tmp->next);
		tmp->next->val = i;
		tmp = tmp->next;
	}
	fprintf(stdout, "List of size %d created\n", i);
	return 0;
}

/* Print the list starting from node */
static void dump_list(const struct list* node)
{
	int i = 0;
	while(node)
	{
		fprintf(stdout, "Node %d, val = %d\n", i++, node->val);		
		node = node->next;
	}
}

/* Expects list head as a place to start with */
static void middle_node(struct list* head)
{
	struct list* itr1, *itr2;

	itr1 = itr2 = head;
	while(itr2)
	{
		itr1 = itr1->next;
		if (itr2->next && ((struct list*)(itr2->next))->next)
			itr2 = (itr2->next)->next;
	}
	fprintf(stdout, "Middle node val = %d\n", itr1->val);
}

int main(int argc, char** argv)
{	
	int ll_size = 0;
	struct list* list;
	if (argc!=2)
		return fprintf(stderr, "Invalid argument(s)!\n");
	ll_size = atoi(argv[1]);
	if (get_list(ll_size, &list))
		return 1;
	dump_list(list);
	middle_node(list);
	return 0;
}
