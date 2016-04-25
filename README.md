# B3152
Question 2: 
test.txt: temps -> 17,525s
tricky.txt: temps -> 1m653s
primes.txt: temps-> Non fini...
Le temps est particulièrement long si le nombre passé en paramètre a de très grands diviseurs premiers.
(ou s'il est premier!)

Questions 3 et 4:
On utilise dans chaque boucle 2 threads à chaque itération. L'affichaage final reste mélangé, problème à traiter plus loin.
le temps d'exécution est diminué de moitié si l'on met par exemple deux nombre premiers (grands) à la suite).
Grande diminution également si il y a de nombreux nombres à traiter, pour un temps total global long.

Gagne_pas: cas où juste UN nombre prend presque 100% du temps d'exécution: on ne gagne donc pas de temps..
Gagne_beaucoup: Si deux de ces nombres se suivent OU les nombres prennent tous environ le même pourcentage du temps total.

Temps gagné: temps que met le plus court des deux threads à s'exécuter.

Questions 5 et 6:
On "déplace" la boucle principale dasn les deux thread parallèles. Ainsi ils vont chacun tourner et lire une lige dès que la courante est terminée.
Nécessité de mettre en place un mutex afin que les thread ne lisent pas les mêmes lignes en même temps (lock sur fgets());

En faisant un test avec une valeur très longue à calculer, et d'autres valeurs plus rapides, on veut qu'un des deux threads reste "bloqué" longtemps
sur cette valeur. Tandis que l'autre thread continue à lire le fichier et à décomposer les autres valeurs.
Dans ce cas: énorme gain de temps par rapport à la question 1.
Pas de gain de temps par rapport à la question 2 si jamais la longue valeur est plus longue à calculer que toutes les autres.
Sinon, :gain de temps.

Question 7:
L'affichage est désormais "rangé", car on stocke d'un côté dans un tableau les valeurs des facteurs premiers, puis on affiche le nombre à décomposr suivi de son tableau dde valeurs. Plus de mélange dans l'affichage en console.

Questions 8 et 9:
L'affichage se fait désormais en exclusion mutuelle: mise en place d'un mutex pour les printf.
Ralentissement de l'exécution par rapport à la question 7 (+2secs). En effet la mise en place du mutex pour les printf fait qu'il y a un temps 
pour chaque affichage (ou moins le temps d'effectuer les opérations sur le mutex). Ca permet d'éviter les erreurs d'affichage si les affichages ne sont pas atomiques. Peut y avoir un changement dans l'ordre d'affichage par rapport à précédemment.

Question 10:
ll
65 jours ouvrés

550€

151h

convention, RIB







