#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

void* t1_callback(void *arg)
{
	for (;;) {
		printf("t1 callback\n");
		sleep(1);
	}
	return NULL;
}

void* t2_callback(void *arg)
{
	for (;;) {
		printf("t2 callback\n");
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	pthread_t t1, t2;
	void *ret1, *ret2;

	if (pthread_create(&t1, NULL, t1_callback, NULL)) {
		fprintf(stderr, "Error creating thread t1\n");
		return -EFAULT;
	}

	if (pthread_create(&t2, NULL, t2_callback, NULL)) {
		fprintf(stderr, "Error creating thread t2\n");
		return -EFAULT;
	}

//	pthread_join(t1, &ret1);
	//pthread_join(t2, &ret2);
	pthread_detach(t2);

	printf("Main thread returns\n");
//	pthread_exit(ret1);
	printf("Main thread returns\n");
	return 0;
}
