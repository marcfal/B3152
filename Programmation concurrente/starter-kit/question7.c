#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t mutex;
static uint64_t MAX_FACTORS = 30;

int get_prime_factors(uint64_t n,uint64_t* dest)
{
	uint64_t i;
	int j = 0;
	i = 2;
	while(n>1 && j<MAX_FACTORS)
	{
		if(n%i == 0)
		{
			n = n / i;
			dest[j++] = i;
		}
		else
		{
			i++;
		}
	}
	return j;
}
void print_prime_factors(uint64_t n)
{
    uint64_t factors[MAX_FACTORS];
	int j,k;
	k=get_prime_factors(n,factors);
	printf("%ju: ",n);
	for(j=0; j<k; j++)
	{
		printf("%ju ",factors[j]);
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
