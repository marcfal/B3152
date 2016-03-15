#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** cout;

void creeCout(int nbSommets){
    int coutMin = 10;
    int coutMax = 40;
    int i, j, iseed, it;
    iseed = 1;
    cout = (int**) malloc(nbSommets*sizeof(int*));
    for (i=0; i<nbSommets; i++){
        cout[i] = (int*) malloc(nbSommets*sizeof(int));
        for (j=0; j<nbSommets; j++){
            if (i == j) cout[i][j] = coutMax+1;
            else {
                it = 16807 * (iseed % 127773) - 2836 * (iseed / 127773);
                if (it > 0)	iseed = it;
                else iseed = 2147483647 + it;
                cout[i][j] = coutMin + iseed % (coutMax-coutMin+1);
            }
        }
    }
}

int permut(int vus[], int nbVus, int nonVus[], int nbNonVus, int longueur, int pcc){
    /*
     Variable globale :
     - pour tout couple de sommets (i,j), cout[i][j] = cout pour aller de i vers j
     Entree :
     - nonVus[0..nbNonVus-1] = sommets non visites
     - vus[0..nbVus-1] = sommets visites
     Precondition :
     - nbVus > 0 et Vus[0] = 0 (on commence toujours par le sommet 0)
     - longueur = somme des couts des arcs du chemin <vus[0], vus[1], ..., vus[nbVus-1]>
     - pcc = longueur du plus court circuit trouve depuis le premier appel à permut
     Postcondition : Soit C l'ensemble des circuits commencant par Vus[0..nbVus-1] et visitant ensuite chaque sommet de nonVus[0..nbNonVus-1] puis retournant en 0.
         S'il existe un circuit de C de longueur inferieure a borne, alors retourne la longueur du plus petit circuit de C, sinon retourne borne
     */
    // INSEREZ VOTRE CODE ICI !
	
	if(nbNonVus == 0 )
	{
		longueur += cout[vus[nbVus-1]][0];
		if(longueur < pcc)
		{
			pcc = longueur;
		}
	}
	else
	{
		int l = 100000;
		int li[nbNonVus];
		int k;
		for(k=0; k<nbNonVus; k++)
		{
			li[k] = 100000;
		}
		int j;
		for(k = 0; k< nbNonVus; k++)
		{
			if(cout[vus[nbVus-1]][nonVus[k]] < l)
			{
				l = cout[vus[nbVus-1]][nonVus[k]];
			}
			
			for(j=0; j< nbNonVus; j++)
			{
				if(j!=k && cout[nonVus[k]][nonVus[j]] <li[k])
				{
					li[k] = cout[nonVus[k]][nonVus[j]];
				}
			}
			if(cout[nonVus[k]][0] <li[k])
			{
				li[k] = cout[nonVus[k]][0] <li[k];
			}
		}
		
		
		//calcul l + somme(li)
		
	
		if(1);	//comparaison avec la somme
		{
			int i;
			for(i=0 ; i< nbNonVus; i++)
			{
				vus[nbVus] = nonVus[i];
				nonVus[i] = nonVus[nbNonVus-1];
				nbVus++;
				nbNonVus--;
				pcc = permut(vus, nbVus, nonVus, nbNonVus, longueur + cout[vus[nbVus-2]][vus[nbVus-1]], pcc);
				nbVus--;
				nbNonVus++;
				nonVus[nbNonVus-1] = nonVus[i];
				nonVus[i] = vus[nbVus];
			}
		}
	}
	return pcc;
}

int main(){
    int nbSommets, i, pcc;
    scanf("%d",&nbSommets);
    int vus[nbSommets];
    int nonVus[nbSommets-1];
    creeCout(nbSommets);
    for (i=0; i<nbSommets-1; i++)
        nonVus[i] = i+1;
    vus[0] = 0;
    pcc = permut(vus,1,nonVus,nbSommets-1,0,INT_MAX);
    printf("%d\n",pcc);
    return 0;
}
