#include <stdio.h>
#include <stdint.h>
#include <math.h>
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

/*
void print_prime_factors_bis(uint64_t n)
{
	int taille;
	int i;
	uint64_t cur;
	uint64_t *tab;
	tab = malloc (sizeof(uint64_t));
	tab[0] = (uint64_t)1;
    taille = prime_list(n, tab);
    
    for(i=1; i< taille && (cur=tab[i])<=n; i++)
    {
		if(n%cur == 0)
		{
			printf("%ju ", cur);
			n = n/cur;
			i--;
		}
	}
	
	free(tab);
	printf("\n");
    return;


}

int prime_list(uint64_t n, uint64_t *tab)
{
	uint64_t i;
	uint64_t j;
	uint64_t pasI = 4;
	uint64_t pasJ;
	uint64_t racine;
	int taille_tab = 1;
	
	
	
	if( n >= 2 )
	{
		taille_tab++;
		tab = realloc (tab, taille_tab * sizeof(uint64_t));
		tab[taille_tab-1] = (uint64_t)2;
		if(n >= 3)
		{
			taille_tab++;
			tab = realloc (tab, taille_tab * sizeof(uint64_t));
			tab[taille_tab-1] = (uint64_t)3;
			if(n >= 5)
			{
				taille_tab++;
				tab = realloc (tab, taille_tab * sizeof(uint64_t));
				tab[taille_tab-1] = (uint64_t)5;
			}
		}
	}

	
	for(i=7; i<=n; i+= pasI , pasI = 6 - pasI)
	{
		pasJ = 2;
		racine = (uint64_t) sqrt((double) i);
		for(j=5; (i%j)&&(j<racine); j+=pasJ, pasJ=6-pasJ);
		if(i%j)
		{
			taille_tab++;
			tab = realloc (tab, taille_tab * sizeof(uint64_t));
			tab[taille_tab-1] = i;
		}
	}
	
	return taille_tab;
}

*/
int main(void)
{
    print_prime_factors(77); // expected result:   77: 7 11
    print_prime_factors(84); // expected result:   84: 2 2 3 7

    // expected result:   429496729675917: 3 18229 7853726291
    //print_prime_factors(429496729675917);
    


    return 0;
}


