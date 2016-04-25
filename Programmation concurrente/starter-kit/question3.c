#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

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
	uint64_t n = *(uint64_t*)arg;
	printf("%ju: ", n);
	print_prime_factors(n);
	pthread_exit(NULL);
}

int main(void)
{
    FILE * fichier = fopen("gagne_bcp.txt", "r");
    
    char ligne [30];
    uint64_t nb1;
    uint64_t nb2;
    
    pthread_t thread1;
	pthread_t thread2;
    
    while(fgets(ligne, 30, fichier) != NULL)
    {
		nb1 = (uint64_t)atoll(ligne);
		pthread_create(&thread1, NULL, routine, &nb1);
		
		if(fgets(ligne, 30, fichier) != NULL)
		{
			nb2 = (uint64_t)atoll(ligne);
			pthread_create(&thread2, NULL, routine, &nb2);
			pthread_join(thread2, NULL);
		}
		
		pthread_join(thread1, NULL);
	}
	
	fclose(fichier);
    

    return 0;
}
