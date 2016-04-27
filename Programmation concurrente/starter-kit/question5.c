#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t mutex;

void print_prime_factors(uint64_t n)
{
    uint64_t i;
	i = 2;
	while(n>1)
	{
		if(n%i == 0)
		{
			n = n / i;
			printf("%ju ", i);
		}
		else
		{
			i++;
		}
	}
	printf("\n");
}

void *routine(void *arg)
{
	FILE *fichier = (FILE*)arg;
	char ligne[30];
	uint64_t n;
	
	
	while(1)
    {
		pthread_mutex_lock(&mutex);
		if(fgets(ligne, 30, fichier) == NULL) break;
		pthread_mutex_unlock(&mutex);
		n = (uint64_t)atoll(ligne);
		printf("%ju: ", n);
		print_prime_factors(n);
	}
	pthread_mutex_unlock(&mutex);
	
	pthread_exit(NULL);
}

int main(void)
{
    FILE * fichier = fopen("question5gain.txt", "r");
    
    pthread_t thread1;
	pthread_t thread2;
	
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&thread1, NULL, routine, fichier);
	pthread_create(&thread2, NULL, routine, fichier);

	pthread_join(thread2, NULL);
	pthread_join(thread1, NULL);
	
	pthread_mutex_destroy(&mutex);
	
	fclose(fichier);
    

    return 0;
}
