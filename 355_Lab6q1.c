// 64050355 jirapat Pichai

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int csum, msum;

void *runner(void *param);

int main(int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t attr;
	
	int num = atoi(argv[1]);
	if(num > 0) {
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, runner, argv[1]);

		msum = 0;
		for(int i = 1; i <= num; i++) {
			msum += i;
		}

		pthread_join(tid, NULL);
		printf("csum - msum = %d\n", csum - msum);
		return 0;
	}
}
void *runner(void *param) {
	int upper = atoi(param);
	csum = 0;

	for(int i = 1; i <= upper*2; i++) {
		csum += i;
	}
	pthread_exit(0);
}
