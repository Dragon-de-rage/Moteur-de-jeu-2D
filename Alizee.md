# Document de suivi individuel : 

ce que j’ai fait, les problemes, les solutions, les tests, les validations, les limites, les cas critiques, les exemples, les demos, les maths mobilisees, etc

*Question 1*

Réponse :
Le monde physique étant centré sur l’écran, le centre du monde correspond au centre de l’écran :

(X,Y) = ( W/2, H/2)

*Question 2*

Le facteur de zoom z représente le nombre de pixels par mètre.

Pour une distance d exprimée en mètres, la distance correspondante à l’écran est : D = z * d

*Question 3*

Réponse :
Pour une coordonnée physique horizontale x, on part du centre de l’écran puis on se déplace de x * z pixels vers la droite : X = W/2 + x * z

*Question 4*
Réponse :
On inverse la formule précédente : x = (X - W/2) / z

*Question 5*

Réponse :
L'axe vertical de l'écran est inversé par rapport au monde physique :

dans le monde physique, \(y\) augmente vers le haut ;
sur l'écran, \(Y\) augmente vers le bas. Y = H/2 - y * z 

*Question 6*

Réponse :
On inverse la formule précédente : y = (H/2 - Y) / z

*1.3 déplacement*

Que se passe-t-il lorsque plusieurs touches directionnelles sont maintenues simultanément ? Le comportement obtenu vous paraît-il satisfaisant ?

Non car le déplacement s'éffectue que pour une des touches et ne prend pas en compte les 2. 
Mais pour rester appuyer cela fonctionne correctement. 

*2.3 euler 1*

Que devient l’équation différentielle de l’évolution de la vitesse du joueur, une fois
appliquée la méthode d’Euler ?

m dv/dt = G - kv  donc dv/dt = G/m - (k/m) * v

dv/dt != vn+1 - vn / deltaT 

donc (vn+1 - vn) / deltaT = G/m - k/m vn

*2.3 euler 2*
Établir une relation de récurrence de la forme vn+1 = a × vn + b.

(vn+1 - vn) / deltaT = G - k/m vn 

en isolant on a  vn+1 - vn = deltaT (G - k/m vn)

vn+1 = vn + deltaT ((G / m) - (k / m) vn)

vn+1 = (1-((k deltaT) / m)) vn + (deltaT G) / m

donc on a : 

a = 1-((k deltaT) / m)
b = deltaT G / m

*2.3 euler 3*

c'est une suite arithmético-géométriques

faut trouver L tel que L = aL + b

donc L (1-a) = b   L = b / 1-a

on remplace L = ((deltaT G) / m ) / 1-(1-(k deltaT)/ m)

L = ((delta T G) / m ) / (k delta T) / m

L = (delta T G) / m * m / (k delta T) 

L = G / k 

donc vn = L + (v0 - L) a^n

vn = G/k + (v0 - G/k)(1- (k deltaT)/m) ^n