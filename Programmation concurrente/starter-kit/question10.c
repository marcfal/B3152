#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct {
	uint64_t nombre;
	int nbFacteurs;
	uint64_t *facteurs;
	
} decomposition ;

static pthread_mutex_t mutex;
static pthread_mutex_t mutex_insert;
static pthread_mutex_t mutex_print;
static uint64_t MAX_FACTORS = 30;
static int taille_tab;
static decomposition *tab_facteurs;
static const decomposition EMPTYDEC = {-1, -1, NULL};

void echange(decomposition *tab, int a, int b)
{
	decomposition tampon = tab[a];
	tab[a] = tab[b];
	tab[b] = tampon;
}

void quickSort(decomposition *tab, int debut, int fin)
{
	int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tab[debut].nombre;

    if(debut >= fin) return;

    while(1)
    {
        do
        {
			droite--;
		}while(tab[droite].nombre > pivot);
		
        do
        {
			gauche++;
		}while(tab[gauche].nombre < pivot);

        if(gauche < droite)
        {
			echange(tab, gauche, droite);
		}
        else
        {
			break;
		}

    }
    
    quickSort(tab, debut, droite);

    quickSort(tab, droite+1, fin);
}

static decomposition find(int nb, int debut, int fin)
{
	if (taille_tab == 0 || debut > fin)
	{
		return EMPTYDEC;
	}
	
	if (fin - debut <= 1)	//ARRET Changé de 0 à 1
	{
		if(tab_facteurs[debut].nombre == nb)
		{
			return tab_facteurs[debut];
		}
		else if(tab_facteurs[fin].nombre == nb) //test de la fin (normalement inutile)
        {
            return tab_facteurs[fin];
        }
        else
		{
			return EMPTYDEC;
		}
	}
	
	int milieu = (fin + debut)/2;
	if(tab_facteurs[milieu].nombre <= nb)
	{
		return find(nb, milieu, fin);
	}
	else
	{
		return find(nb, debut, milieu);
	}
	
	return EMPTYDEC;
    
    /*Là si le bon nombr eets pile sur milieu on re-boucle quand meme non? ou pas grave? le find marche par apire, mais pas plus. 
     * Probleme stockage des trucs trouvés? Problème pour les trouver? Proble de realloc? Mettre mutex ? 
     * 
     if(tab_facteurs[milieu].nombre < nb)
	{
		return find(nb, milieu, fin);	//TODO : BOUCLE 0 1
	}
	else if(tab_facteurs[milieu].nombre > nb)
	{
		return find(nb, debut, milieu);
	}
    else 
    {
        return tab_facteurs[milieu];
    }
     * */
}

static void insert (decomposition dec) //mutex sur insertion!
{
	pthread_mutex_lock(&mutex_insert);
	taille_tab++;
	tab_facteurs = realloc (tab_facteurs, taille_tab * sizeof(decomposition));
	tab_facteurs[taille_tab-1] = dec;
    quickSort(tab_facteurs,0,taille_tab-1);
	pthread_mutex_unlock(&mutex_insert);
}



int get_prime_factors(uint64_t n,uint64_t* dest)
{
	decomposition dec;
	if((dec = find(n, 0, taille_tab-1)).nombre != -1)	//TROUVE
	{
		int k;
		for(k=0; k<dec.nbFacteurs ; k++)
		{
			dest[k] = dec.facteurs[k];
		}
		return  dec.nbFacteurs;
	}
	/*NON-TROUVE*/
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
	
	uint64_t *temp = malloc(j * sizeof(uint64_t));
	int k;
	
	for(k=0; k<j ; k++)
	{
		temp[k] = dest[k];
	}
	
	dec.nombre = n;
	dec.nbFacteurs = j;
	dec.facteurs = temp;
	insert(dec);
	
	return j;
}

int get_prime_factors_mem(uint64_t n, uint64_t* dest, uint64_t nbDiviseursTrouves)
{
	decomposition dec;
	if ((dec = find(n, 0, taille_tab - 1)).nombre != -1)	//TROUVE
	{
		int k;
		for (k = 0; k<(dec.nbFacteurs); k++)
		{
			dest[k + nbDiviseursTrouves] = dec.facteurs[k];
		}
		return  dec.nbFacteurs + nbDiviseursTrouves;
	}

	/*NON-TROUVE*/
	uint64_t i;
	i = 2;

	while (n%i != 0)
	{
		i++;
	}
	
	dest[nbDiviseursTrouves++] = i;
	uint64_t *temp = malloc(nbDiviseursTrouves * sizeof(uint64_t));
	int k;

	for (k = 0; k<nbDiviseursTrouves; k++)
	{
		temp[k] = dest[k];
	}

	dec.nombre = n;
	dec.nbFacteurs = nbDiviseursTrouves;
	dec.facteurs = temp;
	insert(dec);

	if (n == i) //nombre premier, decomposition terminee
	{
		return nbDiviseursTrouves;
	}
	else
	{
		return get_prime_factors_mem(n / i, dest, nbDiviseursTrouves);
	}
	return 0;
}

void print_prime_factors(uint64_t n)
{
    uint64_t factors[MAX_FACTORS];
	int j,k;
	k=get_prime_factors(n,factors);
	
	pthread_mutex_lock(&mutex_print);
	printf("%ju: ",n);
	for(j=0; j<k; j++)
	{
		printf("%ju ",factors[j]);
	}
	printf("\n");
	pthread_mutex_unlock(&mutex_print);
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
	tab_facteurs = malloc (sizeof(decomposition));
	uint64_t *deux = malloc(sizeof(uint64_t));
	deux[0] = 2;
	tab_facteurs[0].nombre = 2;
	tab_facteurs[0].nbFacteurs = 1;
	tab_facteurs[0].facteurs = deux;

	taille_tab = 1;
	
    FILE * fichier = fopen("illustr_mutex.txt", "r");
    
    pthread_t thread1;
	pthread_t thread2;
	
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&mutex_print, NULL);
	pthread_mutex_init(&mutex_insert, NULL);
	
	pthread_create(&thread1, NULL, routine, fichier);
	pthread_create(&thread2, NULL, routine, fichier);

	pthread_join(thread2, NULL);
	pthread_join(thread1, NULL);
	
	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&mutex_print);
	pthread_mutex_destroy(&mutex_insert);
	
	fclose(fichier);
    
    //FREEEEEE
    int z;
    for(z = 0; z < taille_tab; z++)
    {
		free(tab_facteurs[z].facteurs);
	}
	free(tab_facteurs);

    return 0;
}
