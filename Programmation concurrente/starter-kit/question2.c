#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

int main(void)
{
    // your code goes  here: open the text file (e.g.  with fopen() ),
    // then read each line (e.g. with fgets() ), turn it into a number
    // (e.g. with atoll() ) and then pass it to print_prime_factors.
    
    /*
    printf("Nom du fichier ?\n");
    char nom[20];
    scanf("%s", nom);
    */
    
    
    FILE * fichier = fopen("test.txt", "r");
    
    char ligne [30];
    uint64_t nb;
    
    while(fgets(ligne, 30, fichier) != NULL)
    {
		nb = (uint64_t)atoll(ligne);
		printf("%ju: ", nb);
		print_prime_factors(nb);
	}
	
	fclose(fichier);
    

    return 0;
}
