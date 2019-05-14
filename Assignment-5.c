//203165
//Abhishek Wahane
//B1 Batch
//Multithreading Arithmetic Operations

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
typedef struct
{
int num1;
int num2;
}num;

void *add(void *arg)
{
	num*m=(num*)arg;
	int result;
	result=m->num1 + m->num2;
    printf("Sum: %d\n",result);
	return NULL;
}
void *sub(void *arg)
{
	num*m=(num*)arg;
	int result;
	result=m->num1 - m->num2;
    printf("Difference: %d\n",result);
	return NULL;
}
void *multi(void *arg)
{
	num*m=(num*)arg;
	int result;
	result=m->num1 * m->num2;
    printf("Multiplication: %d\n",result);
	return NULL;
}
void *div(void *arg)
{
	num*m=(num*)arg;
	int result;
	result=m->num1 / m->num2;
    printf("Dvision: %d\n",result);
	return NULL;
}
int main()
{
	num n;
    printf("\nMultithreading - Arithmetic Operations\n");
	printf("\nEnter First Number: \n");
	scanf("%d",&n.num1);
    printf("Enter Second Number: \n");
	scanf("%d",&n.num2);
    printf("\nResults: \n");
	pthread_t tid;
	
	pthread_create(&tid,NULL,add,(num *)&n);
	pthread_create(&tid,NULL,sub,(num *)&n);
	pthread_create(&tid,NULL,multi,(num *)&n);
	pthread_create(&tid,NULL,div,(num *)&n);
	pthread_join(tid,NULL);
	pthread_join(tid,NULL);
	pthread_join(tid,NULL);
	pthread_join(tid,NULL);
	
	return 0;
}
