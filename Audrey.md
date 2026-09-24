# Document de suivi individuel :

ce que j’ai fait, les problemes, les solutions, les tests, les validations, les limites, les cas critiques, les exemples, les demos, les maths mobilisees, etc

## Cours du 09/09/26

### Réponses aux questions du sujet

**1.2 Coordonnées physiques vs écran**

*(1) On note H la hauteur de l’écran en pixels et W sa largeur. Le monde physique sera centré sur l’écran. Quelle est la position écran du centre du monde?*

La position écran du centre du monde sera noté : x = W/2 et y = H/2

*(2) On note z le facteur de zoom, qu’on exprime en pixels par mètre. Pour une distance d dans le monde physique, que vaut la distance D à l’écran?*

D = d*z

## Cours du 10/09/26

### Continuation des réponses aux questions du sujet

*(3) Pour un point M de coordonnée horizontale x dans le monde physique, que vaut sa coordonnée X dans le monde écran?*

X = W/2 + x*z

*(4) Inversement, connaissant X, comment retrouver x?*

X = W/2 + (x * z)

=> X - W/2 = x * z

=> x = (X - W/2)/z

*(5) Pour un point M de coordonnée verticale y dans le monde physique, que vaut sa coordonnée Y dans le monde écran? Attention : en général les bibliothèques graphiques comptent les distances verticales à partir du haut de la fenêtre (l’axe des Y est donc inversé!).*

Y = -H + (y * z)

*(6) Inversement, connaissant Y , comment retrouver y?*

Y = -H + (y * z)

=> Y + H = y * z

=> y = (Y + H)/z


Ensuite j'ai essayé de fix les bug du code (qui étaient prévu pour une version anterieur)

## Cours du 14/09/26

Réponses aux question de la section 2.1 : 

1/ Pn/tn = 1    Pn+1/tn+1 = 1.3

*résultats aproximatifs*

2/ P(t) = 2t + A *(A étant une constante)*

P(0) = 0 => P(0) = 0t + A => P(0) = A => A = 0

3/ Pn+1 = Pn + 2 => suite arithmétique

## Cours du 15/09/26

Création de la courbe comparative pour le 2.1 sur tableur

Avancement des question du 2.2 (avec Elven)

À noter que nous avons eu des dificultés concerant la démonstration de l'exercice 1 du 2.2

2/ A = (v(t) - G/k)/exp(-t/τ)

3/ A = (v(0)-100/1.8)/exp(-0/(1208/1.8)) = -100/1.8

Nous avons tracé la courbes dans "Courbes_exercices.xlsx"

## Cours du 17/09/26

Nous nous sommes aperçu qu'il y avait une erreur avec notre courbe car elle ne partait pas de 0 et elle décélerait au lieu d'accelérer.

Le problème était que nous avions pris A = 100/1.8 au lieu de A = -100/1.8.

## Cours du 18/09/26

Commencement de l'ajout de la classe abstraîte *Entity* (utilisation de l'IA pour la structure puis apropriation et début de modifications des classes)

## Cours du 21/09/26

Restructuration de *GameWindow* pour introduire *Entity* et ajout de la classe fille de *Entity* : *Player*

J'ai eu des difficulter à adapter le code existant pour sortir le *player* de *GameWindow* et en faire une classe fonctionel sans rien perdre.

Je n'ai pas encore fini l'intégration.

## Cours du 22/09/26

Débugage de la refactorisation, j'ai eu les mêmes problème que la séance dernière.

## Cours du 24/09/26

J'ai encore travaillé sur l'intégration de *Entity* et *Player* dans le code existant. J'ai commencé à travailler sur l'intégration des touches réglable (pour les déplacements d'un ou plusieurs joueurs).

J'ai également mis à jour le fichier *CMakeList* afin qu'il incluse *Entity* et *Player* afin qu'ils soient pris en compte dans la solution.